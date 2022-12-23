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
	int counter;

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

void	alg_three(t_list **a, t_struct *info)
{
	int	pos;

	pos = find_pos(*a, 2);
	if (pos == 1)
		rrab(a, 1);
	else if (!pos)
		rab(a, 1);
	if (!checking_sort(info, a))
		sab(*a, 1);
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
	alg_three(a, info);
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


void	titernik(t_struct *info, t_list **a, t_list **b)
{
	if (info->len > 5)
	{
		fill_b(a, b, info);
		backfill(a, b, info);
	}
	else if (info->len == 3)
		alg_three(a, info);
	
	else
		alg_five(a, b, info);
}