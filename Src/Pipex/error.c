/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:53:44 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/25 17:10:20 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex.h"

void	ft_error_file(t_pipex *pipex, char *s)
{
		perror(s);
		master_close();
		free_split(pipex->cmds);
		free(pipex->path);
		free(pipex->pid);
		exit(1);
}

void	ft_error(char *s)
{
	perror(s);
	master_close();
	exit(1);
}

void	master_close()
{
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

void	alloc_pid(int size, t_pipex *pipex)
{
	pipex->pid = ft_calloc(size, sizeof(int));
	if (!pipex->pid)
		ft_error("Error Pid Alloc");
}
