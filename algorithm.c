/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:36:53 by monicaharut       #+#    #+#             */
/*   Updated: 2022/12/23 00:00:50 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_b(t_list **a, t_list **b, t_struct *info)
{
	int	counter;

	counter = 0;
	if (info->len > 100)
		info->step = 30;
	else
		info->step = 15;
	while (counter < info->len)
	{
		if ((*a)->index <= counter)
		{
			pab(b, a, 0);
			rab(b, 0);
			counter++;
		}
		else if ((*(a))->index <= counter + info->step)
		{
			pab(b, a, 0);
			counter++;
		}
		else
			rab(a, 1);
	}
}

void	backfill(t_list **a, t_list **b, t_struct *info)
{
	int	i;

	while ((*b) && b)
	{
		i = -1;
		info->b_size = ft_lst_size(*b);
		info->index = find_pos(*b, info->b_size - 1);
		if (info->index <= info->b_size / 2)
		{
			while (++i < info->index)
				rab(b, 0);
		}
		else if (info->index > info->b_size / 2)
		{
			while (++i < info->b_size - info->index)
				rrab(b, 0);
		}
		if (!info->index)
			pab(a, b, 1);
	}
}

void	titernik(t_struct *info, t_list **a, t_list **b)
{
	if (info->len > 5)
	{
		fill_b(a, b, info);
		backfill(a, b, info);
	}
	else if (info->len == 2)
	{
		if ((*a)->data > (*a)->next->data)
			sab(*a, 1);
	}
	else if (info->len == 3)
		alg_three(a);
	else
		alg_five(a, b, info);
}
