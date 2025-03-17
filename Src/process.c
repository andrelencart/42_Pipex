/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:00:03 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/17 18:42:28 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	write_to_pipe(char **env, t_pipex *pipex)
{
	close(pipex->fd[0]);
	pipex->infile = open("Includes/infile.txt", O_RDWR, 0644);
	if (pipex->infile == -1)
		ft_error_file(pipex->infile);
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->fd[1]);
	if (execve(pipex->path, pipex->cmds, env) == -1)
		ft_error("Error\n");
}

void	parent_process(char **env, t_pipex *pipex)
{
	pipex->outfile = open("Includes/outfile.txt", O_RDWR, 0644);
	if (pipex->outfile == -1)
		ft_error_file(pipex->outfile);
	dup2(pipex->fd[0], STDOUT_FILENO);
	dup2(pipex->outfile, STDIN_FILENO);
	close(pipex->fd[0]);
}

void	pipex_to_stdin(t_pipex *pipex)
{
	dup2(pipex->fd[1], STDIN_FILENO);
	close(pipex->fd[1]);
}