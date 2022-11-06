/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:31:58 by mharutyu          #+#    #+#             */
/*   Updated: 2022/04/16 15:47:37 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_min(int num, char *s)
{
	if (num == -2147483648)
	{
		num = -147483648;
		s[1] = '2';
	}
	return (num);
}

int	len(int n)
{
	int	l;

	l = 0;
	if (n < 0)
	l++;
	if (n == 0)
		return (l + 1);
	while (n != 0)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	long int	c;
	char		*s;
	int			num;

	num = n;
	c = len(n);
	s = (char *)malloc((c + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (num == 0)
		s[0] = '0';
	if (num < 0)
	{
		num = ft_int_min(num, s);
		s[0] = '-';
		num *= -1;
	}
	s[c] = '\0';
	while (num > 0)
	{
		s[c - 1] = num % 10 + '0';
		num = num / 10;
		c--;
	}
	return (s);
}
