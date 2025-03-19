/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:00:03 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/19 16:48:03 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	write_to_pipe(char **av, char **env, t_pipex *pipex)
{
	close(pipex->fd[0]);
	pipex->cmds = ft_split_pipe(av[2], ' ');
	if (!pipex->cmds || !pipex->cmds[0])
		ft_error_file(pipex ,"Error Cmds In");
	pipex->path = get_path(pipex->cmds[0], env);
	if (!pipex->path)
		ft_error_file(pipex, "Error Path In");
	printf("Command[0]: %s\n", pipex->cmds[0]);
	printf("Path[0]: %s\n", pipex->path);
	pipex->infile = open(av[1], O_RDWR, 0644);
	if (pipex->infile == -1)
		ft_error_file(pipex, "Error In");
	dup2(pipex->fd[1], STDOUT_FILENO);
	dup2(pipex->infile, STDIN_FILENO);
	master_close();
	if (execve(pipex->path, pipex->cmds, env) == -1)
		ft_error_file(pipex ,"Error Exec In");
}

void	the_pipe(char **av, char **env, t_pipex *pipex)
{
	close(pipex->fd[1]);
	pipex->cmds = ft_split_pipe(av[3], ' ');
	if (!pipex->cmds || !pipex->cmds[0])
		ft_error_file(pipex ,"Error Cmds Out");
	pipex->path = get_path(pipex->cmds[0], env);
	if (!pipex->path)
		ft_error_file(pipex, "Error Path Out");
	printf("Command[1]: %s\n", pipex->cmds[0]);
	printf("Path[1]: %s\n", pipex->path);
	pipex->outfile = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex->outfile == -1)
		ft_error_file(pipex, "Error Out");
	dup2(pipex->fd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	master_close();
	if (execve(pipex->path, pipex->cmds, env) == -1)
		ft_error_file(pipex ,"Error Exec Out");
}

char	*get_path(char *cmds, char **env)
{
	char	**path;
	char 	*final_line;
	char	*bar;
	int		i;
	
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	if (!env)
		return (NULL);
	path = ft_split_pipe(env[i] + 5, ':');
	if (!path)
		ft_error("Error");
	i = 0;
	while (path[i])
	{
		bar = ft_strjoin(path[i], "/");
		final_line = ft_strjoin(bar, cmds);
		free(bar);
		if (access(final_line, F_OK) == 0)
			return (free_split(path), final_line);
		free(final_line);
		i++;
	}
	free_split(path);
	return (NULL);
}
