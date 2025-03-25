/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:47:18 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/25 17:23:05 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

void	is_here_doc(t_pipex_b *pipex_b, char **av)
{
	char	*cancer_line;

	pipex_b->hdfd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex_b->hdfd == -1)
		ft_error_file(pipex_b, "Error Heredoc");
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
	loop_pid(pipex_b, av);
	unlink("here_doc");
}

void	loop_here_doc(t_pipex_b *pipex_b, char **av)
{
	int	i;
	int	cmdn;
	
	i = 0;
	cmdn = 3;
	pipex_b->hdfd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex_b->hdfd == -1)
		ft_error_file(pipex_b, "Error Heredoc");
	while (pipex_b->pid[i])
	{
		create_pipe(pipex_b);
		pipex_b->pid[i] = fork();
		if (pipex_b->pid[i] < 0)
			ft_error("Error Pid");
		if (pipex_b->pid[i] == 0)
			write_to_pipe_bonus(av, pipex_b, cmdn);
		i++;
		cmdn++;
	}
}

