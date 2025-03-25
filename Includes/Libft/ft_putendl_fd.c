/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:14:40 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/25 14:42:14 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!fd)
		return ;
	while (s && *s)
	{
		write(fd, &(*s), 1);
		s++;
	}
	write (fd, "\n", 1);
}
