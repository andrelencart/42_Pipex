/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:19:00 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/25 17:22:45 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

void	create_pipe(t_pipex_b *pipex_b)
{
	
}

void	write_to_pipe_bonus(char **av, t_pipex_b *pipex_b, int cmdn)
{
	// close(pipex_b->fd[0]);
	pipex_b->cmds = ft_split_pipe(av[cmdn], ' ');
	if (!pipex_b->cmds || !pipex_b->cmds[0])
		ft_error_file(pipex_b ,"Error Cmds In");
	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env);
	if (!pipex_b->path)
		ft_error_file(pipex_b, "Error Path In");
	printf("Command[0]: %s\n", pipex_b->cmds[0]);
	printf("Path[0]: %s\n", pipex_b->path);
	pipex_b->infile = open(av[1], O_RDWR, 0644);
	if (pipex_b->infile == -1)
		ft_error_file(pipex_b, "Error In");
	dup2(pipex_b->fd[1], STDOUT_FILENO);
	dup2(pipex_b->infile, STDIN_FILENO);
	master_close();
	if (execve(pipex_b->path, pipex_b->cmds, env) == -1)
		ft_error_file(pipex ,"Error Exec In");
}
