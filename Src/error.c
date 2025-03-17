/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:53:44 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/17 18:18:33 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

// void	ft_error_env(int pid)
// {
// 	if (pid < 0)
// }

void	ft_error_file(t_pipex *pipex)
{
	int	i;
	
	i = 0;
	if (pipex->fd[i] < 0)
	{
		close(pipex->fd[1]);
		close(pipex->fd[0]);
		perror("Error");
		exit(1);
	}
}

void	ft_error(char *s)
{
	perror(s);
	exit(1);
}