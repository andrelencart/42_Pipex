/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:55:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/04/01 18:08:15 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex_b	pipex_b;
	int			i;

	i = 0;
	if (ac < 5)
		ft_error("Error Argument Count");
	ft_bzero((void *)&pipex_b, sizeof(t_pipex));
	pipex_b.env = env;
	if_here_doc(&pipex_b, av, ac, &i);
	printf("infile: %d\n", pipex_b.infile);
	printf("outfile: %d\n", pipex_b.outfile);
	printf("herefd: %d\n", pipex_b.hdfd);
	while (++i < ac - 2)
		loop_pipes(&pipex_b, av, &i);
	the_output(&pipex_b, av, i);
	master_close();
	wait_pid_loop(&pipex_b, ac);
	if (WIFEXITED(pipex_b.status))
		return(unlink("here_doc"), free(pipex_b.pid), WEXITSTATUS(pipex_b.status));
	return (unlink("here_doc"), free(pipex_b.pid), pipex_b.status);
}
