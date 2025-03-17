/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:47:11 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/17 18:40:23 by andcarva         ###   ########.fr       */
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
	int		pid1;
	int		pid2;
	int 	fd[2];
	char	**cmds;
	char	**path;
	int		infile;
	int		outfile;
	
}			t_pipex;


//PARSE FUNC
// void	check_args(int ac, char **av, char **env);

// ERROR FUNC
void	ft_error_file(t_pipex *pipex);
void	ft_error(char *s);

// PROCESS FUNC
void	write_to_pipe(char **env, t_pipex *pipex);
void	parent_process(char **env, t_pipex *pipex);
void	pipex_to_stdin(t_pipex *piex);

// GET FUNC
char	**get_cmds(char **av);
char	*get_path(char *cmds, char **env);

// UTILS FUNC
char	**ft_split_pipe(char const *s, char c);

#endif //PIPEX_H