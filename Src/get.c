/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:28:09 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/13 14:50:28 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

char	**get_cmds(char *av)
{
	char	**cmds;

	cmds = ft_split(av, ' ');
	if (!cmds)
	{
		perror("Error Split Commands!");
		exit(1);
	}
	return (cmds);
}

char	*get_path()