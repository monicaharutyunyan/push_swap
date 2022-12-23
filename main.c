/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:17:02 by monicaharut       #+#    #+#             */
/*   Updated: 2022/12/23 00:01:17 by monicaharut      ###   ########.fr       */
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

int	is_sorted(t_list *a)
{
	t_list	*temp;

	temp = a;
	while (temp->next)
	{
		if(temp->index > temp->next->index)
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
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	my_free(t_list **a, t_list **b, t_struct *info)
{
	int	i;

	i = -1;
	free(info->numbers);
	free(info->str);
	while (info->matrix[++i])
		free(info->matrix[i]);
	free(info->matrix);
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
