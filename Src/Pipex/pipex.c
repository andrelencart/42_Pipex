/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/04/02 17:27:32 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac != 5)
		return (master_close(), ft_printf("Wrong Argument Count\n"));
	ft_bzero((void *)&pipex, sizeof(t_pipex));
	alloc_pid(ac - 3, &pipex);
	if (pipe(pipex.fd) == -1)
		ft_error_file(&pipex, "Error Pipe");
	pipex.pid[0] = fork();
	if (pipex.pid[0] < 0)
		ft_error("Error 3");
	if (pipex.pid[0] == 0)
		write_to_pipe(av, env, &pipex);
	pipex.pid[1] = fork();
	if (pipex.pid[1] < 0)
		ft_error("Error 4");
	if (pipex.pid[1] == 0)
		the_pipe(av, env, &pipex);
	master_close();
	wait_pid(&pipex);
	if (WIFEXITED(pipex.status))
		return (free(pipex.pid), WEXITSTATUS(pipex.status));
	return (free(pipex.pid), pipex.status);
}
