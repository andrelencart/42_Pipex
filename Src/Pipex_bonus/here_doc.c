/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:47:18 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/24 16:30:06 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

void	is_here_doc(t_pipex *pipex_b)
{
	if(pipe(pipex_b->fd) == -1)
		ft_error_file(&pipex_b, "Error");
	while (1)
	{
		
	}
}
