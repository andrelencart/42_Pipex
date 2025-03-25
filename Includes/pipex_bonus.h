/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:57:04 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/25 17:21:49 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include "../Includes/pipex.h"

typedef struct s_pipex_b
{
	int		*pid;
	int 	fd[2];
	char	**cmds;
	char	*path;
	char	**env;
	int		infile;
	int		outfile;
	int		hdfd;
	int		exit_code;
	
}			t_pipex_b;

// UTILS
void	is_here_doc(t_pipex_b *pipex_b, char **av);
void	loop_here_doc(t_pipex_b *pipex_b, char **av);
void	write_to_pipe_bonus(char **av, t_pipex_b *pipex_b, int cmdn);
void	create_pipe(t_pipex_b *pipex_b);

#endif //PIPEX_BONUS_H