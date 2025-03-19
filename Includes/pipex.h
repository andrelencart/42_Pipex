/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:47:11 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/19 15:51:29 by andcarva         ###   ########.fr       */
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
	char	*path;
	int		infile;
	int		outfile;
	int		exit_code;
	
}			t_pipex;

// PROCESS FUNC
void	write_to_pipe(char **av, char **env, t_pipex *pipex);
void	the_pipe(char **av, char **env, t_pipex *pipex);

// GET FUNC
// char	**get_cmds(char **av);
char	*get_path(char *cmds, char **env);

// ERROR FUNC
void	ft_error_file(t_pipex *pipex, char *s);
void	ft_error(char *s);

// UTILS FUNC
char	**ft_split_pipe(char const *s, char c);
void	master_close();

#endif //PIPEX_H