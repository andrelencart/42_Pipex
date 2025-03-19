/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:53:44 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/19 17:30:23 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	ft_error_file(t_pipex *pipex, char *s)
{
		perror(s);
		master_close();
		free_split(pipex->cmds);
		free(pipex->path);
		exit(1);
}

void	ft_error(char *s)
{
	perror(s);
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