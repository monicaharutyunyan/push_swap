/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 02:25:31 by monicaharut       #+#    #+#             */
/*   Updated: 2022/04/22 19:23:22 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	altdst;
	size_t	lsrc;
	size_t	i;

	if (size == 0)
		return (ft_strlen((char *)src));
	lsrc = ft_strlen((char *)src);
	i = 0;
	while (dst[i] && i < size)
	i++;
	altdst = i;
	while (src[i - altdst] && i < size - 1)
	{
	dst[i] = src[i - altdst];
	i++;
	}
	if (altdst < size)
		dst[i] = '\0';
	return (altdst + lsrc);
}
