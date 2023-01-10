/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:02:05 by monicaharut       #+#    #+#             */
/*   Updated: 2022/12/23 13:35:35 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_size(t_list *listik)
{
	t_list	*list;
	int		count;

	count = 0;
	list = listik;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

int	find_pos(t_list *lst, int x)
{
	int		i;
	t_list	*move;

	i = 0;
	move = lst;
	while (move)
	{
		if (move->index == x)
			return (i);
		move = move->next;
		i++;
	}
	return (0);
}

void	ft_lstadd_front(t_list **listik, t_list *new)
{
	new->next = *listik;
	*listik = new;
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
