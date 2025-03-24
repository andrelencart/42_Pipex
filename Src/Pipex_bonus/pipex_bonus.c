/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:55:58 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/24 18:30:26 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/pipex_bonus.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex_b;

	if (ac < 5)
		ft_error("Error Argument Count");
	ft_bzero((void *)&pipex_b, sizeof(t_pipex));
	alloc_pid(ac - 6, &pipex_b);
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		is_here_doc(&pipex_b);
}
