/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:12:51 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/03 15:22:41 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
	return (data);
}
