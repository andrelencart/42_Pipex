/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:32:05 by andcarva          #+#    #+#             */
/*   Updated: 2025/04/01 16:38:15 by andcarva         ###   ########.fr       */
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
		free(pipex_b->path);
		free(pipex_b->pid);
		exit(126);
	}
}

void	if_here_doc(t_pipex_b *pipex_b, char **av, int ac, int *i)
{
	pipex_b->outfile = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex_b->outfile == -1)
		return (free(pipex_b->pid), ft_error("Error Outfile"));
	
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		pipex_b->cmdn = ac - 4;
		is_here_doc(pipex_b, av);
		*i = 2;
	}
	else
	{
		pipex_b->cmdn = ac - 3;
		alloc_pid_bonus(pipex_b->cmdn - 1, pipex_b);
		pipex_b->infile = open(av[1], O_RDWR, 0644);
		if (pipex_b->infile == -1)
			ft_error_file_bonus(pipex_b, "Error infile");
		*i = 1;
		printf("not here doc\n");
	}	
}

void	wait_pid_bonus(t_pipex_b *pipex_b)
{
	printf("pid[0]; %d\n", pipex_b->pid[0]);
	waitpid(pipex_b->pid[0], NULL, 0);
	waitpid(pipex_b->pid[1], &pipex_b->status, 0);
}