/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:42:13 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/10 13:40:47 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/// @brief  Opens a file in the mode specified by the in_out parameter.
///         - IN:      Opens the file for reading only.
///         - OUT:     Opens (or creates) the file for writing and truncates it.
///         - APPEND:  Opens (or creates) the file for writing in append mode.
/// @param  filename Name of the file to open.
/// @param  in_out   File mode indicator (IN, OUT, or APPEND).
/// @return File descriptor on success, or -1 on failure.
static int	file_open(char *filename, enum e_in_out in_out)
{
	int	fd;

	fd = -1;
	if (in_out == IN)
		fd = open(filename, O_RDONLY);
	else if (in_out == OUT)
		fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (in_out == APPEND)
		fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0644);
	return (fd);
}

/// @brief  Executes one command from the parsed command list in a child 
///			process. Redirects STDIN and STDOUT to the correct file descriptors,
///         closes unused pipe ends, and replaces the process image with
///         the command using execve().
/// @param  data Main data structure containing command info, fds, and envp.
/// @param  i    Index of the command to execute.
/// @note   On failure (access, dup2, or execve), prints an error with perror()
///         and returns. The process should exit afterward to avoid undefined 
///			behavior.
static void	child_proccess(t_data *data, int i)
{
	if (access(data->cmds[i][0], X_OK) == -1)
	{
		perror("Access failed");
		return ;
	}
	if (dup2(data->input_fd, STDIN_FILENO) == -1)
	{
		perror("Dup2 for STDIN failed");
		return ;
	}
	close(data->input_fd);
	if (dup2(data->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("Dup2 for STDOUT failed");
		return ;
	}
	close(data->pipefd[1]);
	close(data->pipefd[0]);
	execve(data->cmds[i][0], data->cmds[i], data->envp);
	perror("Execve failed");
}

/// @brief  Creates pipes and forks child processes for all commands except
///         the last one. Each child executes command i using child_proccess().
/// @param  data Main data structure with command info and file descriptors.
/// @return 1 on success, 0 on failure (after printing an error message).
static int	execute_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->cmds_count) - 1)
	{
		if (pipe(data->pipefd) < 0)
			return (close(data->input_fd), perror("Pipe Failed"), 0);
		data->proccess = fork();
		if (data->proccess < 0)
			return (perror("Fork failed"), 0);
		else if (data->proccess == 0)
		{
			child_proccess(data, i);
			return (0);
		}
		else
		{
			close(data->input_fd);
			close(data->pipefd[1]);
			data->input_fd = data->pipefd[0];
		}
		i++;
	}
	return (1);
}

/// @brief  Handles execution of the last command in the pipeline.
///         Opens the output file (append mode if using heredoc), forks,
///         and runs the last command in the child via child_proccess().
/// @param  data Main data structure with argc/argv, commands and fds.
/// @return 1 on success, 0 on failure (after printing an error message).
static int	execute_last(t_data *data)
{
	int	last_cmd;

	last_cmd = data->cmds_count - 1;
	if (!ft_strncmp(data->argv[1], "heredoc", 8))
		data->pipefd[1] = file_open(data->argv[data->argc - 1], APPEND);
	else
		data->pipefd[1] = file_open(data->argv[data->argc - 1], OUT);
	if (data->pipefd[1] == -1)
		return (perror("Open outfile failed"), 0);
	data->proccess = fork();
	if (data->proccess < 0)
		return (perror("Fork failed"), 0);
	else if (data->proccess == 0)
	{
		child_proccess(data, last_cmd);
		return (0);
	}
	else
	{
		close(data->pipefd[0]);
		close(data->pipefd[1]);
	}
	return (1);
}

/// @brief  Entry point of the program. Initializes data structures, handles
///         heredoc or input file setup, executes all pipeline commands, and
///         performs cleanup before exiting.
/// @param  argc Argument count received from main.
/// @param  argv Argument vector received from main.
/// @param  envp Environment variable array received from main.
/// @return 0 on success, 1 on failure (after printing an error message).
int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = setup(argc, argv, envp);
	if (!data)
		return (1);
	if (!ft_strncmp(argv[1], "heredoc", 8))
	{
		if (!read_heredoc(data))
			return (1);
	}
	else
		data->input_fd = file_open(argv[1], IN);
	if (data->input_fd < 0)
		return (free_data(data), perror("open infile failed"), 1);
	if (!execute_loop(data))
		return (free_data(data), 1);
	if (!execute_last(data))
		return (free_data(data), 1);
	free_data(data);
	return (0);
}
