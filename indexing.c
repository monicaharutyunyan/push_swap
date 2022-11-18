/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:21:42 by mharutyu          #+#    #+#             */
/*   Updated: 2022/11/18 16:02:33 by mharutyu         ###   ########.fr       */
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

t_list	*finding_min(t_list **lst)
{
	t_list	*ptr;
	t_list	*min;
	static	int		count = 0;

	ptr = *lst;
	while ((*lst)->next)
	{
		if ((*lst)->data < (*lst)->next->data && (*lst)->index == -1)
			min = *lst;
		*lst = (*lst)->next;
	}
	*lst = min;
	(*lst)->index = count;
	count++;
	*lst = ptr;
	return (min);
}

void	indexing(t_list **lst, t_struct *info)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = *lst;
	before_indexing(lst);
	finding_min(lst);
	while (i < info->len)
	{
		finding_min(lst);
		++i;
	}
}
