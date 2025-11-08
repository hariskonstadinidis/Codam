/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:12:04 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/08 18:02:28 by hariskon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/// @brief  Splits each command string from argv into tokens and stores them 
///         in a null-terminated array of commands. Each command is itself a 
///         null-terminated array of argument strings.
/// @param  cmds_count Number of commands to parse from argv.
/// @param  argv Array of command strings to split.
/// @return A null-terminated array of commands (char ***), or NULL on failure 
///         (after printing an error message).
static int	parse_argv(t_data *data)
{
	int		i;

	i = 0;
	data->cmds = ft_calloc(sizeof(char **), (data->cmds_count + 1));
	if (data->cmds == NULL)
		return (write(2, "1st mem alloc in parse_argv failed", 34), 0);
	while (i < data->cmds_count)
	{
		data->cmds[i] = ft_split(data->first_cmd[i], ' ');
		if (!data->cmds[i])
			return (write(2, "2nd mem alloc in parse_argv fail", 32), 0);
		i++;
	}
	data->cmds[i] = NULL;
	return (1);
}

/// @brief  Parses the PATH variable from the environment to obtain executable 
///         directories. Searches for "PATH=" in envp, appends ":." so the 
///         current directory is included, and splits the result by ':' into 
///         an array of directory strings. If no "PATH=" entry is found, only 
///         the current directory is used.
/// @param  envp Null-terminated array of environment variable strings.
/// @return A null-terminated array of directory path strings on success, or 
///         NULL on failure (after printing an error message).
static int	parse_paths(t_data *data)
{
	int		i;
	char	*full_path;

	if (data->envp == NULL)
		return (write(2, "envp is NULL", 12), 0);
	i = 0;
	while (data->envp[i])
	{
		if (!ft_strncmp(data->envp[i], "PATH=", 5))
			break ;
		else
			i++;
	}
	full_path = ft_strjoin(data->envp[i], ":.");
	if (!full_path)
		return (perror("ft_strjoin failed"), 0);
	if (!ft_strncmp(full_path, "PATH=", 5))
		data->paths = ft_split(full_path + 5, ':');
	else
		data->paths = ft_split(full_path, ':');
	if (!data->paths)
		return (free(full_path), write(2, "Split Failed", 12), 0);
	return (free(full_path), 1);
}

/// @brief  Joins two path segments into a single string, inserting a '/' 
///         between them. Used to create full executable paths such as 
///         "/usr/bin/ls".
/// @param  s1 The first part of the path (a directory).
/// @param  s2 The second part of the path (a command name).
/// @return A newly allocated string containing "s1/s2", or NULL if memory 
///         allocation fails. The caller is responsible for freeing the result.
static char	*ft_strjoin_path(char const *s1, char const *s2)
{
	char	*new_string;
	size_t	total_len;
	size_t	i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 2;
	new_string = malloc(sizeof(char) * total_len);
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

/// @brief  Checks each command against all given PATH directories and,
///         if an executable is found, replaces the command name with
///         its full path. If it doesnt find one it does nothing.
/// @param cmds  Null-terminated array of commands, where each command is a
///              null-terminated array of strings (argv-style).
/// @param paths Null-terminated array of directory paths.
/// @return 1 on success, or 0 if a memory allocation/join fails.
static int	path_check(char ***cmds, char **paths)
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
				return (write(2, "Strjoin_path Failed", 19), 0);
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

/// @brief  Prepares and initializes the main program data structure.
///         Validates argument count, allocates memory, parses commands,
///         retrieves PATH directories, and verifies executable paths.
/// @param  argc Argument count received from main.
/// @param  argv Argument vector received from main.
/// @param  envp Environment variable array received from main.
/// @return Pointer to a fully initialized t_data structure on success,
///         or NULL on failure (after printing an error message).
t_data	*setup(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc <= 4)
		return (write(2, "Wrong input, put more arguments\n", 32), NULL);
	data = init_data(argc, argv, envp);
	if (!data)
		return (free_data(data), NULL);
	if (!parse_argv(data))
		return (free_data(data), NULL);
	if (!parse_paths(data))
		return (free_data(data), NULL);
	if (!path_check(data->cmds, data->paths))
		return (free_data(data), NULL);
	return (data);
}
