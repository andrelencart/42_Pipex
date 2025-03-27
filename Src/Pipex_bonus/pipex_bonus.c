/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:55:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/27 13:03:22 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex_b	pipex_b;

	if (ac < 5)
		ft_error("Error Argument Count");
	ft_bzero((void *)&pipex_b, sizeof(t_pipex));
	pipex_b.env = env;
	pipex_b.cmdn = ac - 3;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
	{
		
		alloc_pid_bonus(ac - 4, &pipex_b);
		is_here_doc(&pipex_b, av);
	}
	else 
	{
		alloc_pid_bonus(ac - 3, &pipex_b);
	}
}
