/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 23:04:05 by monicaharut       #+#    #+#             */
/*   Updated: 2022/05/05 23:04:39 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	write(1, "0x", 2);
	count = 2;
	count += ft_putnbr_unsigned((unsigned long long)ptr, 16, 0);
	return (count);
}
