/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:24:57 by monicaharut       #+#    #+#             */
/*   Updated: 2022/05/05 22:43:46 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char *format, va_list *args)
{
	int	done;

	done = 0;
	if (*format == 'c')
		done += ft_putchar(va_arg(*args, int));
	else if (*format == 's')
		done += ft_putstr(va_arg(*args, char *));
	else if (*format == 'd')
		done += ft_putnbr(va_arg(*args, int), 10, 0);
	else if (*format == 'i')
		done += ft_putnbr(va_arg(*args, int), 10, 0);
	else if (*format == 'p')
		done += ft_putptr(va_arg(*args, void *));
	else if (*format == 'u')
		done += ft_putnbr_unsigned(va_arg(*args, unsigned int), 10, 0);
	else if (*format == 'x')
		done += ft_putnbr_unsigned(va_arg(*args, unsigned int), 16, 0);
	else if (*format == 'X')
		done += ft_putnbr_unsigned(va_arg(*args, unsigned int), 16, 1);
	else if (*format == '%')
		done += ft_putchar('%');
	return (done);
}
