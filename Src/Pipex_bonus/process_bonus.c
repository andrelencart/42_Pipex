/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:19:00 by andcarva          #+#    #+#             */
/*   Updated: 2025/04/01 11:47:18 by andcarva         ###   ########.fr       */
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

// void	write_to_pipe_hdfd(char **av, t_pipex_b *pipex_b, int n)
// {
// 	printf("HERE_DOC\n");
// 	pipex_b->cmds = ft_split_pipe(av[n], ' ');
// 	if (!pipex_b->cmds || !pipex_b->cmds[0])
// 		ft_error_file_bonus(pipex_b ,"Error Cmds In");
// 	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
// 	if (!pipex_b->path)
// 		ft_error_file_bonus(pipex_b, "Error Path In");
// 	printf("Command[0]: %s\n", pipex_b->cmds[0]);
// 	printf("Path[0]: %s\n", pipex_b->path);
// 	pipex_b->hdfd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0644);
// 	if (pipex_b->hdfd == -1)
// 		ft_error_file_bonus(pipex_b, "Error Heredoc");
// 	dup2(pipex_b->hdfd, STDIN_FILENO);
// 	dup2(pipex_b->fd[1], STDOUT_FILENO);
// 	close(pipex_b->hdfd);
// 	close(pipex_b->fd[1]);
// 	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
// 		ft_error_execve_bonus(pipex_b ,"Error Exec In");
// }

// void	the_pipe_bonus(char **av, t_pipex_b *pipex_b, int n, int i)
// {
// 	printf("PIPE\n");
// 	close(pipex_b->fd[0]);
// 	pipex_b->cmds = ft_split_pipe(av[n + 1], ' ');
// 	if (!pipex_b->cmds || !pipex_b->cmds[0])
// 		ft_error_file_bonus(pipex_b ,"Error Cmds Pipe");
// 	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
// 	if (!pipex_b->path)
// 		ft_error_file_bonus(pipex_b, "Error Path Pipe");
// 	printf("Command[%d]: %s\n", i, pipex_b->cmds[0]);
// 	printf("Path[%d]: %s\n", i, pipex_b->path);
// 	// dup2(pipex_b->fd[1], STDIN_FILENO);
// 	dup2(pipex_b->fd[1], STDOUT_FILENO);
// 	// master_close();
// 	close(pipex_b->fd[1]);
// 	// close(pipex_b->fd[0]);
// 	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
// 		ft_error_execve_bonus(pipex_b ,"Error Exec Pipe");
// }

// void	the_output(char **av, t_pipex_b *pipex_b, int n, int i)
// {
// 	printf("THE_OUTPUT\n");
// 	pipex_b->cmds = ft_split_pipe(av[n + 1], ' ');
// 	if (!pipex_b->cmds || !pipex_b->cmds[0])
// 		ft_error_file_bonus(pipex_b ,"Error Cmds Out");
// 	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
// 	if (!pipex_b->path)
// 		ft_error_file_bonus(pipex_b, "Error Path Out");
// 	printf("Command[%d]: %s\n", i, pipex_b->cmds[0]);
// 	printf("Path[%d]: %s\n", i, pipex_b->path);
// 	pipex_b->outfile = open(av[n + 2], O_RDWR | O_TRUNC | O_CREAT, 0644);
// 	if (pipex_b->outfile == -1)
// 		ft_error_file_bonus(pipex_b, "Error Out");
// 	// close(pipex_b->fd[1]);
// 	// dup2(pipex_b->fd[0], STDIN_FILENO);
// 	dup2(pipex_b->outfile, STDOUT_FILENO);
// 	master_close();
// 	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
// 		ft_error_execve_bonus(pipex_b ,"Error Exec Out");
// }

// void	write_to_pipe_bonus(char **av, t_pipex_b *pipex_b, int n)
// {
// 	printf("NO HERE DOC\n");
// 	close(pipex_b->fd[0]);
// 	pipex_b->cmds = ft_split_pipe(av[n], ' ');
// 	if (!pipex_b->cmds || !pipex_b->cmds[0])
// 		ft_error_file_bonus(pipex_b ,"Error Cmds In");
// 	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
// 	if (!pipex_b->path)
// 		ft_error_file_bonus(pipex_b, "Error Path In");
// 	printf("Command[0]: %s\n", pipex_b->cmds[0]);
// 	printf("Path[0]: %s\n", pipex_b->path);
// 	pipex_b->infile = open(av[1], O_RDWR, 0644);
// 	if (pipex_b->infile == -1)
// 		ft_error_file_bonus(pipex_b, "Error Heredoc");
// 	dup2(pipex_b->hdfd, STDIN_FILENO);
// 	dup2(pipex_b->fd[1], STDOUT_FILENO);
// 	// master_close();
// 	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
// 		ft_error_execve_bonus(pipex_b ,"Error Exec In");
// }

// void	loop_pipes(t_pipex_b *pipex_b, char **av, int flag)
// {
// 	int	i;
// 	int	n;
	
// 	i = 0;
// 	n = 3;
// 	if (pipe(pipex_b->fd) == -1)
// 		ft_error_file_bonus(pipex_b, "Error Pipe");
// 	create_fork(pipex_b, i);
// 	if (pipex_b->pid[i] == 0)
// 		if_here_doc(pipex_b, av, flag, n++);
// 	while (++i < pipex_b->cmdn - 1)
// 	{
// 		if (pipe(pipex_b->fd) == -1)
// 			ft_error_file_bonus(pipex_b, "Error Pipe");
// 		create_fork(pipex_b, i);
// 		if (pipex_b->pid[i] == 0)
// 		{
// 			printf("n: %d\n", n);
// 			the_pipe_bonus(av, pipex_b, n, i);
// 		}
// 		close(pipex_b->fd[1]);
// 		dup2(pipex_b->fd[0], STDIN_FILENO);
// 		close(pipex_b->fd[0]);
// 		n++;
// 	}
// 	create_fork(pipex_b, i);
// 	if (pipex_b->pid[i] == 0)
// 		the_output(av, pipex_b, n, i);
// }
