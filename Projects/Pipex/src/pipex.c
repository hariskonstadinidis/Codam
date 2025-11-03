/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:42:13 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/03 18:12:16 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// static void	print_argvs(char ***cmds, char **paths)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (cmds[i])
// 	{
// 		j = 0;
// 		while (cmds[i][j])
// 		{
// 			printf("%s ", cmds[i][j]);
// 			j++;
// 		}
// 		printf("%s ", cmds[i][j]);
// 		printf("\n");
// 		i++;
// 	}
// 	printf("\n");
// 	i = 0;
// 	if (!paths)
// 		return ;
// 	while (paths[i])
// 		printf("%s\n", paths[i++]);
// }

static void	safe_pipe(int *pipefd, t_data *data)
{
	if (pipe(pipefd) == -1)
	{
		free_data(data);
		// close_fds(data);
		exit(EXIT_FAILURE);
	}
}

/// @brief opens a file with the given filepath
/// @param filename the path of the file to open  
/// @return file descriptor, -1 on failure
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
	if (fd == -1)
		perror("Failed to open infile");
	return (fd);
}

static int	execute_loop(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->cmds_count) - 1)
	{
		safe_pipe(data->pipefd, data);
		data->proccess = fork();
		if (data->proccess < 0)
			return (perror("Fork failed"), 0);
		else if (data->proccess == 0)
		{
			if (access(data->cmds[i][0], X_OK) == -1)
				return (perror("Access failed"), 0);
			dup2(data->input_fd, STDIN_FILENO);
			close(data->input_fd);
			dup2(data->pipefd[1], STDOUT_FILENO);
			close(data->pipefd[1]);
			execve(data->cmds[i][0], data->cmds[i], data->envp);
			close(data->pipefd[0]);
			return (perror("Execve failed"), 0);
		}
		else
		{
			close(data->input_fd);
			close(data->pipefd[1]);
			data->input_fd = (data->pipefd)[0];
		}
		i++;
	}
	return (1);
}

int	execute_last(t_data *data)
{
	int	last_cmd;

	last_cmd = data->cmds_count - 1;
	data->outfile_fd = file_open(data->argv[data->argc - 1], OUT);
	data->proccess = fork();
	if (data->proccess < 0)
		return (free_cmds(data->cmds), perror("Fork failed"), 1);
	else if (data->proccess == 0)
	{
		printf("%s", data->cmds[last_cmd][0]);
		if (access(data->cmds[last_cmd][0], X_OK))
			return (perror("Access failed"), 0);
		dup2(data->input_fd, STDIN_FILENO);
		close(data->input_fd);
		dup2(data->outfile_fd, STDOUT_FILENO);
		close(data->outfile_fd);
		execve((data->cmds[last_cmd][0]), data->cmds[last_cmd], data->envp);
		// close_fds();
		return (perror("Execve failed"), 0);
	}
	else
	{
		close(data->input_fd);
		close(data->pipefd[1]);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = init_setup(argc, argv, envp);
	if (!data)
		return (free_data(data), write(2, "Initial setup failed", 21), 1);
	if (!ft_strncmp(argv[1], "heredoc", 8))
		data->input_fd = file_open(argv[2], IN);
	else
	{
		data->input_fd = file_open(argv[1], IN);
	}
	if (data->input_fd < 0)
		return (free_data(data), perror("open infile failed"), 1);
	if (!execute_loop(data))
		return (free_data(data), write(2, "Loop Fork Failed", 12), 1);
	if (!execute_last(data))
		return (free_data(data), write(2, "Last Fork Failed", 12), 1);
	close(data->outfile_fd);
	free_data(data);
	return (0);
}
