/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:32:05 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/27 18:12:14 by andcarva         ###   ########.fr       */
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
		free_split(pipex_b->fd);
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
		free_split(pipex_b->cmds);
		free(pipex_b->path);
		free(pipex_b->pid);
		exit(127);
	}
	else if (access(pipex_b->path, X_OK) < 0)
	{
		free_split(pipex_b->cmds);
		free(pipex_b->path);
		free(pipex_b->pid);
		exit(126);
	}
}