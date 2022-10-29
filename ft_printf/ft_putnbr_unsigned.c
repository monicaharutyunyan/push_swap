/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:54:59 by monicaharut       #+#    #+#             */
/*   Updated: 2022/05/05 23:32:35 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned long long number, unsigned int base, int type)
{
	int	res;

	res = 0;
	if (number > base - 1)
		res += ft_putnbr_unsigned(number / base, base, type);
	number = number % base;
	if (number < 10)
		res += ft_putchar(number + 48);
	else if (number >= 10 && type == 0)
		res += ft_putchar(number + 87);
	else if (number >= 10 && type == 1)
		res += ft_putchar(number + 55);
	return (res);
}
