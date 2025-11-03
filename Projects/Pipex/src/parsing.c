/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:12:04 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/03 16:01:03 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	***parse_argv(int cmds_count, char **argv)
{
	char	***cmds;
	int		i;

	i = 0;
	cmds = malloc(sizeof(char **) * (cmds_count + 1));
	if (cmds == NULL)
		return (write(2, "1st mem alloc in parse_argv failed\n", 36), NULL);
	while (i < cmds_count)
	{
		cmds[i] = ft_split(argv[i], ' ');
		if (!cmds[i])
			return (free_cmds(cmds),
				write(2, "2nd mem alloc in parse_argv failed\n", 36), NULL);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

char	**parse_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	if (envp == NULL)
		return (write(2, "envp is NULL", 11), NULL);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
			break ;
		else
			i++;
	}
	full_path = ft_strjoin(envp[i], ":.");
	if (!full_path)
		return (NULL);
	paths = ft_split(full_path + 5, ':');
	if (!paths)
		return (free(full_path), NULL);
	return (free(full_path), paths);
}

static char	*ft_strjoin_path(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	total_len;
	size_t	i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 2;
	new_string = malloc(total_len);
	if (new_string == NULL)
		return (NULL);
	while (*s1)
	{
		new_string[i] = *s1;
		s1++;
		i++;
	}
	new_string[i++] = '/';
	while (*s2)
	{
		new_string[i] = *s2;
		s2++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

int	path_check(char ***cmds, char **paths)
{
	int		i;
	int		j;
	char	*temp;

	j = 0;
	while (cmds[j])
	{
		i = 0;
		while (paths[i])
		{
			temp = ft_strjoin_path(paths[i++], cmds[j][0]);
			if (!temp)
				return (free_cmds(cmds), free_paths(paths), 0);
			if (!access(temp, X_OK))
			{
				free(cmds[j][0]);
				cmds[j][0] = temp;
				break ;
			}
			else
				free(temp);
		}
		j++;
	}
	return (1);
}

t_data	*init_setup(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc <= 4)
		return (write(2, "Wrong input, put more arguments\n", 33), NULL);
	data = init_data(argc, argv, envp);
	if (!data)
		return (write(2, "Malloc Failed for struct data", 30), NULL);
	// if (!ft_strncmp(argv[1], "heredoc", 8))
	// 	data->cmds = parse_argv(argc - 4, argv + 3);
	// else
	// 	data->cmds = parse_argv(argc - 3, argv + 2);
	data->cmds = parse_argv(data->cmds_count, data->first_cmd);
	if (!data->cmds)
		return (write(2, "Malloc Failed in cmds parsing", 30), NULL);
	data->paths = parse_paths(envp);
	if (!data->paths)
		return (free_data(data), write(2, "All_fail in par", 25), NULL);
	path_check(data->cmds, data->paths);
	return (data);
}
