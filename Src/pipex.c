/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/13 14:10:51 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	pid;
	
	if (ac == 5)
	{
		if(pipe(fd) == -1)
			ft_error_file(fd);
		pid = fork();
		if (pid < 0)
			perror("Error");
		if (pid == 0)
			child_process(fd);
		waitpid(pid, NULL, 0);
		parent_process(fd);
	}
	return(0);
}

// 	(void)ac;
// 	(void)env;
// 	(void)av;
// 	if (pipe(pipex.fd) == -1)
// 		ft_error_file(pipex.fd);
// 	pipex.pid = fork();
// 	if (pipex.pid < 0)
// 		perror("Error");
// 	if (pipex.pid == 0)
// 		child_process(pipex.fd);
// 	// else
// 	// 	parent_process(pipex.fd);
// 	wait(&pipex.pid);
// 	return(0);
// }