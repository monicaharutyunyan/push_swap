/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:51:27 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/17 22:21:41 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*ptr;

	ptr = lst;
	if (!ptr)
		return (new);
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	return (lst);
}

