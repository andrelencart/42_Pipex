/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:47:11 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/13 14:38:24 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/wait.h>
# include "../Includes/Libft/libft.h"

// typedef struct s_pipex
// {
// 	char **cmds;
	
// }			t_pipex;


//PARSE FUNC
// void	check_args(int ac, char **av, char **env);

// ERROR FUNC
void	ft_error_file(int *fd);

// PROCESS FUNC
void	child_process(char **av, char **env, int *fd);
void	parent_process(char **av, char **env, int *fd);

// GET FUNC
char	**get_cmds(char **av);

#endif //PIPEX_H