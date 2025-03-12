/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:53:44 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/12 16:58:36 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

// void	ft_error_env(int pid)
// {
// 	if (pid < 0)
// }

void	ft_error_file(int *fd)
{
	if (fd < 0)
	{
		close(fd[1]);
		close(fd[0]);
		perror("Error");
		exit(1);
	}
}