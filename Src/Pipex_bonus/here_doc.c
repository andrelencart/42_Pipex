/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:47:18 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/24 18:49:13 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	is_here_doc(t_pipex *pipex_b, char **av)
{
	char	*cancer_line;
	int		herefd;

	herefd = open("here_doc", O_RDWR | O_TRUNC | O_CREAT, 0644);
	while(1)
	{
		cancer_line = get_next_line(0);
		if (ft_strncmp(av[2], cancer_line, ft_strlen(av[2])))
			break ;
		ft_putendl_fd(cancer_line, herefd);
	}
}
