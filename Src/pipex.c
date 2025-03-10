/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:51:57 by andcarva          #+#    #+#             */
/*   Updated: 2025/03/10 17:34:43 by andcarva         ###   ########.fr       */
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
	// printf("id:%d\n", id);
	// if (id != 0)
	// {
	// 	fork();
	// 	printf("Hello from Main!\n");
	// }
	// else
	// 	printf("Hello from Child\n");
	return(0);
}