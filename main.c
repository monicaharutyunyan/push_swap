/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:49:05 by mharutyu          #+#    #+#             */
/*   Updated: 2022/10/28 16:52:54 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error!");
		exit(0);
	}
	(void)av;
	write(1, "HELLO\n", 6);
}