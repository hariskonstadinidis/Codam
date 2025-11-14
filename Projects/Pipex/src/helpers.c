/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:12:51 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/13 17:31:04 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	pid_wait_and_free(t_data *data)
{
	int	i;
	int	status;
	int	exit_code;

	i = 0;
	while (data->pids[i])
	{
		if (waitpid(data->pids[i], &status, 0) > 0)
		{
			if (WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				exit_code = 128 + WTERMSIG(status);
			else
				exit_code = 1;
		}
		i++;
	}
	free_data(data);
	return (exit_code);
}

/// @brief  Allocates and initializes the main data structure used by the
///			program. Stores argument and environment pointers, determines the
///			number of commands, and sets the pointer to the first command
///			based on whether heredoc mode is active.
/// @param  argc Argument count received from main.
/// @param  argv Argument vector received from main.
/// @param  envp Environment variable array received from main.
/// @return Pointer to an initialized t_data structure on success, or NULL on 
///         failure (if memory allocation fails).
t_data	*init_data(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->argc = argc;
	data->argv = argv;
	data->envp = envp;
	data->cmds = NULL;
	data->paths = NULL;
	if (!ft_strncmp(argv[1], "heredoc", 8))
	{
		data->cmds_count = argc - 4;
		data->first_cmd = argv + 3;
	}
	else
	{
		data->cmds_count = (argc - 3);
		data->first_cmd = argv + 2;
	}
	data->pids = ft_calloc(data->cmds_count + 1, sizeof(pid_t));
	if (!data->pids)
		return (NULL);
	return (data);
}

/// @brief  Handles heredoc input by reading lines from stdin until the
///			specified delimiter is reached. Writes all input lines to a pipe,
///			which becomes the program’s new input file descriptor.
/// @param  data Main data structure containing argv and input_fd.
/// @return 1 on success, or 0 on failure (after printing an error message and 
///         closing the pipe).
int	read_heredoc(t_data *data)
{
	int		pipefd[2];
	char	*s;
	char	*delimiter;

	delimiter = data->argv[2];
	if (!delimiter)
		return (write(2, "Invalid delimiter", 17), 0);
	if (pipe(pipefd) < 0)
		return (perror("Pipe failed"), 0);
	s = get_next_line(0);
	if (!s)
		return (close_pipefd(pipefd), write(2, "GNL Fail", 8), 0);
	while (ft_strncmp(s, delimiter, ft_strlen(delimiter)))
	{
		write(pipefd[1], s, ft_strlen(s));
		free(s);
		s = get_next_line(0);
		if (!s)
			return (close_pipefd(pipefd), free(s), write(2, "GNL Fail", 8), 0);
	}
	free (s);
	get_next_line(-1);
	close(pipefd[1]);
	data->input_fd = pipefd[0];
	return (1);
}
