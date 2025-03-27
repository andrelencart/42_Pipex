/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:19:00 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/27 19:16:50 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

// void	create_pipe(char **av, t_pipex_b *pipex_b, int i)
// {
// 	if (ft_strncmp(av[1], "here_doc", 9) == 0)
// 	{
// 		pipex_b->fd = (int **)ft_calloc((pipex_b->cmdn - 2), (sizeof(int *)));
// 		if (!pipex_b->fd)
// 			return ;
// 	}
// 	else
// 	{
// 		pipex_b->fd = malloc(sizeof(int *) * (pipex_b->cmdn - 1));
// 		if (!pipex_b->fd)
// 			return ;
// 	}
// 	if (pipe(pipex_b->fd[i]) == -1)
// 		ft_error_file_bonus(&pipex_b, "Error Pipe");
// }

void	write_to_pipe_hdfd(char **av, t_pipex_b *pipex_b, int n)
{
	close(pipex_b->fd[0]);
	pipex_b->cmds = ft_split_pipe(av[n], ' ');
	if (!pipex_b->cmds || !pipex_b->cmds[0])
		ft_error_file_bonus(pipex_b ,"Error Cmds In");
	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
	if (!pipex_b->path)
		ft_error_file_bonus(pipex_b, "Error Path In");
	printf("Command[%d]: %s\n", n, pipex_b->cmds[0]);
	printf("Path[%d]: %s\n", n, pipex_b->path);
	pipex_b->hdfd = open("here_doc", O_RDWR, 0644);
	if (pipex_b->hdfd == -1)
		ft_error_file_bonus(pipex_b, "Error Heredoc");
	dup2(pipex_b->fd[1], STDOUT_FILENO);
	dup2(pipex_b->hdfd, STDIN_FILENO);
	master_close(); // Pode dar problemas!!
	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
		ft_error_execve_bonus(pipex_b ,"Error Exec In");
}

void	write_to_pipe_bonus(char **av, t_pipex_b *pipex_b, int n)
{
	close(pipex_b->fd[0]);
	pipex_b->cmds = ft_split_pipe(av[n], ' ');
	if (!pipex_b->cmds || !pipex_b->cmds[0])
		ft_error_file_bonus(pipex_b ,"Error Cmds In");
	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
	if (!pipex_b->path)
		ft_error_file_bonus(pipex_b, "Error Path In");
	printf("Command[%d]: %s\n", n, pipex_b->cmds[0]);
	printf("Path[%d]: %s\n", n, pipex_b->path);
	pipex_b->infile = open(av[1], O_RDWR, 0644);
	if (pipex_b->infile == -1)
		ft_error_file_bonus(pipex_b, "Error Heredoc");
	dup2(pipex_b->fd[1], STDOUT_FILENO);
	dup2(pipex_b->hdfd, STDIN_FILENO);
	master_close(); // Pode dar problemas!!
	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
		ft_error_execve_bonus(pipex_b ,"Error Exec In");
}

void	the_pipe_bonus(char **av, t_pipex_b *pipex_b, int n)
{
	close(pipex_b->fd[0]);
	pipex_b->cmds = ft_split_pipe(av[n], ' ');
	if (!pipex_b->cmds || !pipex_b->cmds[0])
		ft_error_file_bonus(pipex_b ,"Error Cmds Out");
	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
	if (!pipex_b->path)
		ft_error_file_bonus(pipex_b, "Error Path Out");
	printf("Command[%d]: %s\n", n, pipex_b->cmds[0]);
	printf("Path[%d]: %s\n", n, pipex_b->path);
	dup2(pipex_b->fd[1], STDIN_FILENO);
	master_close();
	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
		ft_error_execve_bonus(pipex_b ,"Error Exec Pipe");
}

void	the_output(char **av, t_pipex_b *pipex_b, int n)
{
	pipex_b->cmds = ft_split_pipe(av[n], ' ');
	if (!pipex_b->cmds || !pipex_b->cmds[0])
		ft_error_file_bonus(pipex_b ,"Error Cmds Out");
	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
	if (!pipex_b->path)
		ft_error_file_bonus(pipex_b, "Error Path Out");
	printf("Command[%d]: %s\n", n, pipex_b->cmds[0]);
	printf("Path[%d]: %s\n", n, pipex_b->path);
	pipex_b->outfile = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex_b->outfile == -1)
		ft_error_file_bonus(pipex_b, "Error Out");
	dup2(pipex_b->outfile, STDOUT_FILENO);
	master_close();
	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
		ft_error_file_bonus(pipex_b ,"Error Exec Out");
}
