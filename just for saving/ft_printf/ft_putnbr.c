/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:48:11 by monicaharut       #+#    #+#             */
/*   Updated: 2022/05/05 22:54:38 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, unsigned int base, int type)
{
	unsigned int	number;
	int				res;

	res = 0;
	if (n < 0)
	{
		res += ft_putchar('-');
		number = n * -1;
	}
	else
		number = n;
	if (number > base - 1)
		res += ft_putnbr(number / base, base, type);
	number = number % base;
	if (number < 10)
		res += ft_putchar(number + 48);
	else if (number >= 10 && type == 0)
		res += ft_putchar(number + 87);
	else if (number >= 10 && type == 1)
		res += ft_putchar(number + 55);
	return (res);
}
