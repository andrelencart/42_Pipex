/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:47:11 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/27 16:54:29 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../Includes/Libft/libft.h"

typedef struct s_pipex
{
	int		*pid;
	int 	fd[2];
	char	**cmds;
	char	*path;
	int		infile;
	int		outfile;
	int		status;
	
}			t_pipex;

// PROCESS FUNC
void	write_to_pipe(char **av, char **env, t_pipex *pipex);
void	the_pipe(char **av, char **env, t_pipex *pipex);

// GET FUNC
char	*get_path(char *cmds, char **env, int i);

// ERROR FUNC
void	ft_error_file(t_pipex *pipex, char *s);
void	ft_error(char *s);
void	ft_error_execve(t_pipex *pipex, char *s);

// UTILS FUNC
char	**ft_split_pipe(char const *s, char c);
void	master_close();
void	alloc_pid(int size, t_pipex *pipex);
void	wait_pid(t_pipex *pipex);
int		env_check(char *cmds, char **env, int i);

#endif //PIPEX_H