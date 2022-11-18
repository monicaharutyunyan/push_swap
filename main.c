/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:17:02 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/18 15:59:49 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	fill_lst(t_list **lst, t_struct *info)
{
	int	i;

	i = 0;
	while (i < info->len)
	{
		*lst = ft_lstadd_back(*lst, ft_lstnew(info->numbers[i]));
		i++;
	}
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
	fill_lst(&a, info);
	indexing(&a, info);

	while (a)
	{
		printf("index: %d\n", a->index);
		a = a->next;
	}
}
