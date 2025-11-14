/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:55:03 by hkonstan          #+#    #+#             */
/*   Updated: 2025/11/14 13:53:31 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
/// @brief Closed both ends of pipefd.
/// @param pipefd The int[2] that contains both pipe ends.
void	close_pipefd(int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
}

void	child_exec_error(t_data *data, int i)
{
	char	*cmd;

	cmd = data->cmds[i][0];
	if (errno == ENOENT)
	{
		write(2, "pipex: command not found: ", 27);
		write(2, cmd, strlen(cmd));
		write(2, "\n", 1);
		free_data(data);
		_exit(127);
	}
	if (errno == EACCES)
	{
		write(2, "pipex: permission denied: ", 27);
		write(2, cmd, strlen(cmd));
		write(2, "\n", 1);
		free_data(data);
		_exit(126);
	}
	write(2, "pipex: ", 7);
	perror(cmd);
	free_data(data);
	_exit(1);
}

/// @brief  Frees all memory allocated for the array of path strings.
///         Each individual string and the array itself are freed safely.
/// @param  paths Null-terminated array of directory path strings to free.
static void	free_paths(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		return ;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	paths = NULL;
}

/// @brief  Frees all memory allocated for the command table. Each command 
///			and its arguments are freed, followed by the main array.
/// @param  cmds Null-terminated array of commands, where each command is a 
///         null-terminated array of argument strings.
static void	free_cmds(char ***cmds)
{
	int	i;
	int	j;

	i = 0;
	if (!cmds)
		return ;
	while (cmds[i])
	{
		j = 0;
		while (cmds[i][j])
		{
			free(cmds[i][j]);
			j++;
		}
		free(cmds[i++]);
	}
	free(cmds);
	cmds = NULL;
}

/// @brief  Frees all dynamically allocated memory within the main data 
///			structure. This includes command arrays, path arrays, and the
///			data structure itself.
/// @param  data Pointer to the t_data structure to free.
void	free_data(t_data *data)
{
	if (data)
	{
		if (data->cmds)
			free_cmds(data->cmds);
		if (data->paths)
			free_paths(data->paths);
		if (data->pids)
			free(data->pids);
		free(data);
	}
}
