/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:57:04 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/31 15:39:46 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../Includes/pipex.h"

typedef struct s_pipex_b
{
	int		*pid;
	int		fd[2];
	char	**cmds;
	char	*path;
	char	**env;
	int		cmdn;
	int		infile;
	int		outfile;
	int		hdfd;
	int		status;
}			t_pipex_b;

// PROCESS

	// HERE_DOC
void	is_here_doc(t_pipex_b *pipex_b, char **av);
void	write_to_pipe_hdfd(char **av, t_pipex_b *pipex_b, int n);
void	if_here_doc(t_pipex_b *pipex_b, char **av, int flag, int n);

	// NORMAL
	// Tirar i dos printf commands
void	the_pipe_bonus(char **av, t_pipex_b *pipex_b, int n, int i);
void	the_output(char **av, t_pipex_b *pipex_b, int n, int i);
void	alloc_pid_bonus(int size, t_pipex_b *pipex_b);
void	loop_pipes(t_pipex_b *pipex_b, char **av, int flag);
void	write_to_pipe_bonus(char **av, t_pipex_b *pipex_b, int n);

// ERROR
void	ft_error_file_bonus(t_pipex_b *pipex_b, char *s);
void	ft_error_execve_bonus(t_pipex_b *pipex_b, char *s);

// UTILS
void	wait_pid_bonus(t_pipex_b *pipex_b);
void	create_fork(t_pipex_b *pipex_b, int i);

#endif //PIPEX_BONUS_H