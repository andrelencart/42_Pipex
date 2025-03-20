/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/20 17:28:18 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	
	if (ac != 5)
		ft_error("Error 1");
	ft_bzero((void *)&pipex, sizeof(t_pipex));
	alloc_pid(ac - 3, &pipex);
	if(pipe(pipex.fd) == -1)
		ft_error_file(&pipex, "Error");
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
	waitpid(pipex.pid[0], NULL, 0);
	waitpid(pipex.pid[1], &pipex.exit_code, 0);
	free(pipex.pid);
	if (WIFEXITED(pipex.exit_code))
		WEXITSTATUS(pipex.exit_code);
	return(pipex.exit_code);
}
