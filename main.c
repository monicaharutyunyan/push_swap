/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:17:02 by monicaharut       #+#    #+#             */
/*   Updated: 2022/12/23 13:35:32 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp && temp->next)
	{
		if (temp->index > temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	lst_free(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void	my_free(t_list **a, t_list **b, t_struct *info)
{
	free(info->numbers);
	free(info->str);
	free(info);
	lst_free(*a);
	lst_free(*b);
}

int	main(int ac, char **av)
{
	t_struct	*info;
	t_list		*a;
	t_list		*b;

	if (ac < 2)
		ft_error();
	info = malloc(sizeof(t_struct));
	a = NULL;
	b = NULL;
	if (!info)
		ft_error();
	info->ac = ac;
	info->av = av;
	fill(info);
	fill_lst(&a, info);
	indexing(&a, info);
	if (!is_sorted(a))
		titernik(info, &a, &b);
	my_free(&a, &b, info);
}
