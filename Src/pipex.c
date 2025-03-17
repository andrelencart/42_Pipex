/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/17 18:40:32 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	
	
	if (ac == 5)
	{
		file_parse();
		pipex.cmds = get_cmds(av);
		pipex.path = get_paths(pipex.cmds, env);
		if (!pipex.path)
		ft_error("Error\n");
		if(pipe(pipex.fd) == -1)
			ft_error_file(pipex.fd);
		pipex.pid1 = fork();
		if (pipex.pid1 < 0)
			perror("Error");
		if (pipex.pid1 == 0)
			write_to_pipe(env, &pipex);
		waitpid(pipex.pid1, NULL, 0);
		pipex_to_stdin();
		pipex.pid2 = fork();
		
		// parent_process(av, env, fd);
	}
	return(0);
}
