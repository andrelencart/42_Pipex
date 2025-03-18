/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:53:44 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/18 18:20:12 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_error_file(t_pipex *pipex, char *s)
{
		master_close(pipex);
		perror(s);
		exit(1);
}

void	ft_error(char *s)
{
	perror(s);
	exit(1);
}

void	master_close(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->fd[i])
	{
		close(pipex->fd[i]);
		i++;
	}
}