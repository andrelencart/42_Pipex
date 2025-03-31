/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:47:18 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/31 15:40:23 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

void	is_here_doc(t_pipex_b *pipex_b, char **av)
{
	char	*cancer_line;

	pipex_b->hdfd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex_b->hdfd == -1)
		ft_error_file_bonus(pipex_b, "Error Heredoc");
	while(1)
	{
		ft_putstr_fd(">", 1);
		cancer_line = get_next_line(0);
		ft_putstr_fd(cancer_line, pipex_b->hdfd);
		if (ft_strncmp(av[2], cancer_line, ft_strlen(av[2])) == 0)
		break ;
		free(cancer_line);
	}
	if (cancer_line)
		free(cancer_line);
	close (pipex_b->hdfd);
	loop_pipes(pipex_b, av, 1);
	unlink("here_doc");
}

// needs fixing loop
void	loop_pipes(t_pipex_b *pipex_b, char **av, int flag)
{
	int	i;
	int	n;
	
	i = 0;
	n = 3;
	if (pipe(pipex_b->fd) == -1)
		ft_error_file_bonus(pipex_b, "Error Pipe");
	create_fork(pipex_b, i);
	if (pipex_b->pid[i] == 0)
		if_here_doc(pipex_b, av, flag, n++);
	while (pipex_b->cmdn - 2 > 0)
	{
		i++;
		if (pipe(pipex_b->fd) == -1)
			ft_error_file_bonus(pipex_b, "Error Pipe");
		create_fork(pipex_b, i);
		if (pipex_b->pid[i] == 0)
			the_pipe_bonus(av, pipex_b, n, i);
		n++;
		pipex_b->cmdn--;
	}
	create_fork(pipex_b, i);
	if (pipex_b->pid[i] == 0)
		the_output(av, pipex_b, n, i);
}

void	create_fork(t_pipex_b *pipex_b, int i)
{
	pipex_b->pid[i] = fork();
	if (pipex_b->pid[i] < 0)
		ft_error("Error Pid");
}