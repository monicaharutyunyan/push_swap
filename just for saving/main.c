/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:49:05 by mharutyu          #+#    #+#             */
/*   Updated: 2022/11/05 15:23:48 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_checking(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			if((av[i][j] == '+' || av[i][j] == '-'))
			{
				++j;
				while(av[i][j] >= '0' && av[i][j] <= '9')
					++j;
				printf("after while j: %d\n", j);
				if(av[i][j] != ' ' || av[i][j] )
					return (0);
			}
			++j;
		}
		++i;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int res;

	i = 0;
	if (ac < 2)
	{
		ft_printf("Error!");
		exit(0);
	}
	res = ft_checking(ac, av);
	printf("%d\n", res);
}
