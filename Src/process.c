/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:00:03 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/12 18:47:15 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	child_process(int *fd)
{
	int file_d = open("Includes/output.txt", O_RDWR);
	
	(void)fd;
	printf("The original fd: %d\n", file_d);
	if (file_d < 0)
		printf("FUNCK\n");
	dup2(file_d, STDOUT_FILENO);
	ft_printf("The duplicate fd: %d\n", file_d);
	ft_printf("Done\n");
	close(file_d);
	
}

// void	parent_process(int *fd)
// {
	
// }