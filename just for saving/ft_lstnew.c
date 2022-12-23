/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:58:48 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/17 21:51:04 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}
