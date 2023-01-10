/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:39:06 by mharutyu          #+#    #+#             */
/*   Updated: 2022/12/23 15:39:10 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_three(t_list **a)
{
	int	pos;

	pos = find_pos(*a, 2);
	if (pos == 1)
		rrab(a, 1);
	else if (!pos)
		rab(a, 1);
	if (!is_sorted(*a))
		sab(*a, 1);
}

void	kesy(t_list **a, t_list **b, t_struct *info)
{
	alg_three(a);
	info->b_size = ft_lst_size(*b);
	if (info->b_size > 1 && (*b)->index > (*b)->next->index)
		sab(*b, 0);
	while (info->b_size)
	{
		pab(a, b, 1);
		rab(a, 1);
		info->b_size--;
	}
}

void	alg_five(t_list **a, t_list **b, t_struct *info)
{
	int	i1;
	int	i;

	i1 = -1;
	info->a_size = info->len;
	while (++i1 < 2)
	{
		i = -1;
		info->index = find_pos(*a, info->a_size - 1);
		if (info->index <= info->a_size / 2)
			while (++i < info->index)
				rab(a, 1);
		else
			while (++i < info->a_size - info->index)
				rrab(a, 1);
		pab(b, a, 0);
		info->a_size--;
	}
	kesy(a, b, info);
}
