/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/12 16:04:50 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int ac, char **av)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_error_file(fd);
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
		child_process();
	else
		parent_process();
	printf("\n");
	return(0);
}