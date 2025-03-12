/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/12 17:01:40 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (pipe(pipex.fd) == -1)
		ft_error_file(pipex.fd);
	pipex.pid = fork();
	if (pipex.pid < 0)
		perror("Error");
	if (pipex.pid == 0)
		child_process(pipex.fd);
	else
		parent_process(pipex.fd);
	return(0);
}