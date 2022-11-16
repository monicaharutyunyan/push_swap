/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:17:02 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/14 22:15:29 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error", 2);
	exit(0);
}

int	main(int ac, char **av)
{
	t_struct	*info;
	t_list		*a;
	t_list		*b;

	info = malloc(sizeof(t_struct));
	if (!info)
		ft_error();
	if (ac < 2)
		ft_error();
	info->ac = ac;
	info->av = av;
	fill(info);
	
}
