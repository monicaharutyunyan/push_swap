/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:09:05 by sminasya          #+#    #+#             */
/*   Updated: 2022/05/05 23:17:03 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const char *format, ...);
int	ft_check(const char *format, va_list *args);

int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr(int n, unsigned int base, int type);
int	ft_putnbr_unsigned(unsigned long long n, unsigned int base, int type);
int	ft_putptr(void *ptr);

#endif
