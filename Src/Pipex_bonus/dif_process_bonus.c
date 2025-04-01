/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dif_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:47:18 by andcarva          #+#    #+#             */
/*   Updated: 2025/04/01 16:39:26 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

void	is_here_doc(t_pipex_b *pipex_b, char **av)
{
	char	*cancer_line;

	alloc_pid_bonus(pipex_b->cmdn - 1, pipex_b);
	pipex_b->hdfd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (pipex_b->hdfd == -1)
		ft_error_file_bonus(pipex_b, "Error Heredoc");
	while(1)
	{
		ft_putstr_fd(">", 1);
		cancer_line = get_next_line(0);
		ft_putstr_fd(cancer_line, pipex_b->hdfd);
		if (ft_strncmp(av[2], cancer_line, ft_strlen(av[2])) == 0)
		break ;
		free(cancer_line);
	}
	if (cancer_line)
		free(cancer_line);
}

void	loop_pipes(t_pipex_b *pipex_b, char **av, int *i)
{
	int			var;
	static int	j;
	
	var = 0;
	if (pipe(pipex_b->fd) == -1)
		ft_error_file_bonus(pipex_b, "Error Pipe");
	create_fork(pipex_b, var);
	j++;
	if (pipex_b->pid[var] == 0)
	{
		close(pipex_b->fd[0]);
		dup2(pipex_b->fd[1], STDOUT_FILENO);
		close(pipex_b->fd[1]);
		dprintf(2, "loop, i: %d\n", *i);
		if (j == 1)
			if (access(av[1], F_OK | R_OK) < 0)
				return (ft_error_file_bonus(pipex_b, "Error Access av[1]\n"));
		exec_func(pipex_b, av, *i);
	}
	else
	{
		close(pipex_b->fd[1]);
		dup2(pipex_b->fd[0], STDIN_FILENO);
		close(pipex_b->fd[0]);
	}
}

void	exec_func(t_pipex_b *pipex_b, char **av, int i)
{
	
	pipex_b->cmds = ft_split_pipe(av[i], ' ');
	if (!pipex_b->cmds || !pipex_b->cmds[0])
		ft_error_file_bonus(pipex_b ,"Error Cmds In");
	pipex_b->path = get_path(pipex_b->cmds[0], pipex_b->env, 0);
	if (!pipex_b->path)
		ft_error_file_bonus(pipex_b, "Error Path In");
	dprintf(2, "Command: %s\n", pipex_b->cmds[0]);
	dprintf(2, "Path: %s\n", pipex_b->path);
	if (execve(pipex_b->path, pipex_b->cmds, pipex_b->env) == -1)
		ft_error_execve_bonus(pipex_b ,"Error Exec In");
}

void	create_fork(t_pipex_b *pipex_b, int i)
{
	pipex_b->pid[i] = fork();
	if (pipex_b->pid[i] < 0)
		ft_error("Error Pid");
}
