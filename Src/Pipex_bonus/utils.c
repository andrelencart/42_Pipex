/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrlencart <andrlencart@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:32:05 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/29 15:13:35 by andrlencart      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

void	alloc_pid_bonus(int size, t_pipex_b *pipex_b)
{
	pipex_b->pid = ft_calloc(size, sizeof(int));
	if (!pipex_b->pid)
		ft_error("Error Pid Alloc");
}

void	ft_error_file_bonus(t_pipex_b *pipex_b, char *s)
{
		perror(s);
		master_close();
		free_split(pipex_b->cmds);
		free(pipex_b->path);
		free(pipex_b->pid);
		exit(1);
}

void	ft_error_execve_bonus(t_pipex_b *pipex_b, char *s)
{
	perror(s);
	master_close();
	if (access(pipex_b->path, F_OK) < 0)
	{
		unlink("here_doc");
		free_split(pipex_b->cmds);
		free(pipex_b->path);
		free(pipex_b->pid);
		exit(127);
	}
	else if (access(pipex_b->path, X_OK) < 0)
	{
		unlink("here_doc");
		free_split(pipex_b->cmds);
		// free(pipex_b->path);
		free(pipex_b->pid);
		exit(126);
	}
}

void	if_here_doc(t_pipex_b *pipex_b, char **av, int flag, int n)
{
	if (flag == 1)
		write_to_pipe_hdfd(av, pipex_b, n++);
	if (flag == 0)
		write_to_pipe_bonus(av, pipex_b, n++);
}

void	wait_pid_bonus(t_pipex_b *pipex_b)
{
	waitpid(pipex_b->pid[0], NULL, 0);
	waitpid(pipex_b->pid[1], &pipex_b->status, 0);
}