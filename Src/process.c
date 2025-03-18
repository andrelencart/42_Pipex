/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:00:03 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/18 19:31:17 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	write_to_pipe(char **av, char **env, t_pipex *pipex)
{
	close(pipex->fd[0]);
	pipex->cmds = get_cmds(av);
	pipex->path = get_path(pipex->cmds[0], env);
	pipex->infile = open("Includes/infile.txt", O_RDWR, 0644);
	if (pipex->infile == -1)
		ft_error_file(pipex, "Error IN");
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[1]);
	if (execve(pipex->path, &pipex->cmds[0], env) == -1)
		ft_error("Error Exe IN");
}

void	the_pipe(char **av, char **env, t_pipex *pipex)
{
	close(pipex->fd[1]);
	pipex->cmds = get_cmds(av);
	pipex->path = get_path(pipex->cmds[1], env);
	pipex->outfile = open("Includes/outfile.txt", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile == -1)
		ft_error_file(pipex, "Error OUT");
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	if (execve(pipex->path, &pipex->cmds[1], env) == -1)
		ft_error("Error Exe OUT");
	close(pipex->fd[0]);
}
