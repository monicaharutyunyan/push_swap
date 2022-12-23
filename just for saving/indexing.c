/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:21:42 by mharutyu          #+#    #+#             */
/*   Updated: 2022/11/19 14:05:24 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	before_indexing(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (*lst)
	{
		(*lst)->index = -1;
		(*lst) = (*lst)->next;
	}
	*lst = ptr;
}

t_list	*finding_min(t_list **lst, t_list *min)
{
	t_list	*ptr;
	static	int		count = 0;

	ptr = *lst;
	while ((*lst))
	{
		if ((*lst)->index == -1 && (min->data > (*lst)->data))
			min = *lst;
		*lst = (*lst)->next;
	}
	*lst = ptr;
	min->index = count;
	while (*lst)
	{
		if ((*lst)->index == -1)
		{
			min = *lst;
			break ;
		}
		(*lst) = (*lst)->next;
	}
	count++;
	return (min);
}

void	indexing(t_list **lst, t_struct *info)
{
	int		i;
	t_list	*min;
	t_list	*ptr;

	i = 0;
	ptr = *lst;
	min = *lst;
	before_indexing(lst);
	while (i < info->len)
	{
		min = finding_min(lst, min);
		*lst = ptr;
		++i;
	}
}
