/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/10 17:47:55 by andcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

int	main(int ac, char **av)
{
	int id;
	int n;
	int i;

	(void)ac;
	(void)av;
	id = fork();
	// printf("id: %d\n", id);
	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if (id != 0)
		wait(NULL);
	i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		i++;
	}
	printf("\n");
	return(0);
}