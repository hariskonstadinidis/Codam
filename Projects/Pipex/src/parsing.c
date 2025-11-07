/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hariskon <hariskon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:12:04 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/07 17:23:21 by hariskon         ###   ########.fr       */
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
static char	***parse_argv(int cmds_count, char **argv)
{
	char	***cmds;
	int		i;

	i = 0;
	cmds = malloc(sizeof(char **) * (cmds_count + 1));
	if (cmds == NULL)
		return (write(2, "1st mem alloc in parse_argv failed\n", 35), NULL);
	while (i < cmds_count)
	{
		cmds[i] = ft_split(argv[i], ' ');
		if (!cmds[i])
			return (write(2, "2nd mem alloc in parse_argv failed\n", 35), NULL);
		i++;
	}
	cmds[i] = NULL;
	return (cmds);
}

/// @brief  Parses the PATH variable from the environment to obtain executable 
///         directories. Searches for "PATH=" in envp, appends ":." so the 
///         current directory is included, and splits the result by ':' into 
///         an array of directory strings. If no "PATH=" entry is found, only 
///         the current directory is used.
/// @param  envp Null-terminated array of environment variable strings.
/// @return A null-terminated array of directory path strings on success, or 
///         NULL on failure (after printing an error message).
static char	**parse_paths(char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;

	if (envp == NULL)
		return (write(2, "envp is NULL", 12), NULL);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			break ;
		else
			i++;
	}
	full_path = ft_strjoin(envp[i], ":.");
	if (!full_path)
		return (perror("ft_strjoin failed"), NULL);
	if (!ft_strncmp(full_path, "PATH=", 5))
		paths = ft_split(full_path + 5, ':');
	else
		paths = ft_split(full_path, ':');
	if (!paths)
		return (free(full_path), write(2, "Split Failed", 12), NULL);
	return (free(full_path), paths);
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
		return (NULL);
	data->cmds = parse_argv(data->cmds_count, data->first_cmd);
	if (!data->cmds)
		return (NULL);
	data->paths = parse_paths(envp);
	if (!data->paths)
		return (NULL);
	if (!path_check(data->cmds, data->paths))
		return (NULL);
	return (data);
}
