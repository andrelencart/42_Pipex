/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:00:03 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/13 14:27:40 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	child_process(char **av, char **env, int *fd)
{
	int infile;
	
	infile = open("Includes/infile.txt", O_RDWR, 0777);
	if (infile == -1)
		ft_error_file(&infile);
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[1]);
	execve(, av, );
}

// void	parent_process(int *fd)
// {
	
// }


	// (void)fd;
	// printf("The original fd: %d\n", file_d);
	// if (file_d < 0)
	// 	printf("FUNCK\n");
	// dup2(file_d, STDOUT_FILENO);
	// ft_printf("The duplicate fd: %d\n", file_d);
	// ft_printf("Done\n");
	// close(file_d);
