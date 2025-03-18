/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:28:09 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/18 19:26:57 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

char	**get_cmds(char **av)
{
	char	**cmds;
	int		i; 
	
	i = 1;
	while (av[i])
	{
		cmds = ft_split_pipe(av[i], ' ');
		if (!cmds)
		{
			free_split(cmds);
			ft_error("Error");
		}
		i++;
	}
	return (cmds);
}

char	*get_path(char *cmds, char **env)
{
	char	**path;
	char 	*final_line;
	char	*bar;
	int		i;
	
	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	path = ft_split_pipe(env[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		bar = ft_strjoin(path[i], "/");
		final_line = ft_strjoin(bar, cmds);
		if (access(final_line, F_OK) == 0)
			return (final_line);
		free(bar);
		free(final_line);
		i++;
	}
	free_split(path);
	return (NULL);
}

// int	main(int ac, char	**av, char	**env)
// {
// 	char *path;
// 	char **cmds;
	
// 	(void)ac;
// 	cmds = get_cmds(av);
// 	path = get_path(cmds[0], env);

// 	printf("Path: %s\n", path);
// }