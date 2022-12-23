/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:02:05 by monicaharut       #+#    #+#             */
/*   Updated: 2022/12/21 20:53:45 by monicaharut      ###   ########.fr       */
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


int	checking_sort(t_struct *info, t_list **listik) // 1 0 2
{
	int		i;
	t_list	*head;

	i = -1;
	head = *listik;
	if (!(*listik))
		return (1);
	while (++i < info->len && head && info->numbers[i] == head->data)
		head = head->next;
	if (i == info->len)
		return (1);
	return (0);
}