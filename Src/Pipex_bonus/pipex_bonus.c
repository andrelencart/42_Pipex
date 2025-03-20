/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:55:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/20 18:15:12 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

// int	main(int ac, char **av, char **env)
// {
// 	t_pipex	pipex_b;

// 	ft_bzero((void *)&pipex_b, sizeof(t_pipex));
// 	alloc_pid(ac - 6, &pipex_b);
// 	if(pipe(pipex_b.fd) == -1)
// 		ft_error_file(&pipex_b, "Error");
// 	// pipex_b.pid[0] = fork();
// 	// if (pipex_b.pid[0] < 0)
// 	// 	ft_error("Error 3");
// 	// if (pipex_b.pid[0] == 0)
// 	// 	write_to_pipe(av, env, &pipex_b);
// 	// pipex_b.pid[1] = fork();
// 	// if (pipex_b.pid[1] < 0)
// 	// 	ft_error("Error 4");
// 	// if (pipex_b.pid[1] == 0)
// 	// 	the_pipe(av, env, &pipex_b);
// 	master_close();
// 	waitpid(pipex_b.pid[0], NULL, 0);
// 	waitpid(pipex_b.pid[1], &pipex_b.exit_code, 0);
// 	free(pipex_b.pid);
// 	if (WIFEXITED(pipex_b.exit_code))
// 		WEXITSTATUS(pipex_b.exit_code);
// 	return(pipex_b.exit_code);
// }
