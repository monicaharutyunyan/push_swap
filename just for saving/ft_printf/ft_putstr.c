/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:44:15 by monicaharut       #+#    #+#             */
/*   Updated: 2022/05/05 23:29:57 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	res;

	res = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		res += ft_putchar(*s);
		s++;
	}
	return (res);
}
