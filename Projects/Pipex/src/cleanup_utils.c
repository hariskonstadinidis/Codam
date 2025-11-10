/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 17:55:03 by hkonstan          #+#    #+#             */
/*   Updated: 2025/11/10 12:23:55 by hariskon         ###   ########.fr       */
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
		free(data);
	}
}
