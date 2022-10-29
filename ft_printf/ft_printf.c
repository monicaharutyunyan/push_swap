/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 19:46:29 by monicaharut       #+#    #+#             */
/*   Updated: 2022/05/05 22:23:17 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	if (!format)
		return (0);
	result = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((*format == 's') || (*format == 'c') || (*format == 'i')
				|| (*format == 'd') || (*format == 'x') || (*format == 'X')
				|| (*format == 'p') || (*format == '%') || (*format == 'u'))
				result += ft_check(format, &args);
		}
		else
			result += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (result);
}
