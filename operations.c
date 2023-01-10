/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:52:02 by monicaharut       #+#    #+#             */
/*   Updated: 2022/12/23 14:00:39 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sab(t_list *lst, int flag)
{
	t_list	*temp;

	temp = lst;
	if (temp && temp->next)
	{
		temp->index = temp->index + temp->next->index;
		temp->next->index = temp->index - temp->next->index;
		temp->index = temp->index - temp->next->index;
		temp->data = temp->data + temp->next->data;
		temp->next->data = temp->data - temp->next->data;
		temp->data = temp->data - temp->next->data;
		if (flag == 1)
			write(1, "sa\n", 3);
		else if (flag == 0)
			write(1, "sb\n", 3);
		return (1);
	}
	return (0);
}

int	pab(t_list **a, t_list **b, int flag)
{
	t_list	*add;
	t_list	*next_b;

	add = malloc(sizeof(t_list));
	next_b = (*b)->next;
	if (!add)
		return (0);
	add->data = (*b)->data;
	add->index = (*b)->index;
	ft_lstadd_front(a, add);
	free((*b));
	(*b) = next_b;
	if (flag == 1)
		write(1, "pa\n", 3);
	else if (flag == 0)
		write(1, "pb\n", 3);
	return (1);
}

int	rab(t_list **lst, int flag)
{
	t_list	*new;
	t_list	*temp;

	temp = *lst;
	new = malloc(sizeof(t_list));
	if (!(*lst))
		return (0);
	if (!new)
		return (0);
	new->data = (*lst)->data;
	new->index = (*lst)->index;
	*lst = ft_lstadd_back(*lst, new);
	*lst = (*lst)->next;
	free(temp);
	new->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 0)
		write(1, "rb\n", 3);
	return (1);
}

int	rrab(t_list **lst, int flag)
{
	t_list	*new;
	t_list	*head;
	t_list	*last;

	head = *lst;
	if (!*lst)
		return (0);
	while (*lst && (*lst)->next && (*lst)->next->next)
		*lst = (*lst)->next;
	last = *lst;
	new = (*lst)->next;
	*lst = head;
	ft_lstadd_front(lst, new);
	last->next = NULL;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 0)
		write(1, "rrb\n", 4);
	return (1);
}
