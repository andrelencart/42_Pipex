/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:57:04 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/27 18:11:56 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Includes/pipex.h"

typedef struct s_pipex_b
{
	int		*pid;
	int		**fd;
	char	**cmds;
	char	*path;
	char	**env;
	int		cmdn;
	int		infile;
	int		outfile;
	int		hdfd;
	int		exit_code;
}			t_pipex_b;

// PROCESS

	// HERE_DOC
void	is_here_doc(t_pipex_b *pipex_b, char **av);
void	loop_here_doc(t_pipex_b *pipex_b, char **av);
void	write_to_pipe_hdfd(char **av, t_pipex_b *pipex_b, int n);

	// NORMAL
void	the_pipe_bonus(char **av, t_pipex_b *pipex_b, int n, int fdn);
void	final_pipe(char **av, t_pipex_b *pipex_b, int n, int fdn);
void	create_pipe(char **av, t_pipex_b *pipex_b, int i);
void	alloc_pid_bonus(int size, t_pipex_b *pipex_b);

// ERROR
void	ft_error_file_bonus(t_pipex_b *pipex_b, char *s);
void	ft_error_execve_bonus(t_pipex_b *pipex_b, char *s);

#endif //PIPEX_BONUS_H