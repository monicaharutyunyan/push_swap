/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:01:05 by monicaharut       #+#    #+#             */
/*   Updated: 2022/04/20 22:52:22 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*newnode;
	int		len;

	newnode = lst;
	len = 0;
	while (newnode != NULL)
	{
		len++;
		newnode = newnode->next;
	}
	return (len);
}
