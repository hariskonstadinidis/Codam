/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkonstan <hkonstan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:15:03 by hariskon          #+#    #+#             */
/*   Updated: 2025/11/03 17:35:14 by hkonstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <string.h> 
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

enum	e_in_out
{
	IN,
	OUT,
	APPEND,
};

typedef struct s_data
{
	char	***cmds;
	char	**paths;
	char	**argv;
	char	**envp;
	int		argc;
	int		pipefd[2];
	int		input_fd;
	int		outfile_fd;
	int		cmds_count;
	char	**first_cmd;
	pid_t	proccess;
}	t_data;

int		main(int argc, char **argv, char **envp);
t_data	*init_setup(int argc, char **argv, char **envp);
t_data	*init_data(int argc, char **argv, char **envp);
char	***parse_argv(int argc, char **argv);
void	free_cmds(char ***cmds);
char	**parse_paths(char **envp);
void	free_paths(char **paths);
int		path_check(char ***cmds, char **paths);
void	free_data(t_data *data);

#endif
