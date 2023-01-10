/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 12:26:22 by mharutyu          #+#    #+#             */
/*   Updated: 2022/12/23 13:58:47 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

char	*myus_kes(char *s1, char *s2, int *i, int *j)
{
	char	*dst;

	dst = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (!s1)
	{
		while (*j < ft_strlen(s2))
		{
			dst[*i] = s2[*j];
			*i += 1;
			*j += 1;
		}
		dst[*i] = '\0';
		return (dst);
	}
	dst[0] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	dst = myus_kes(s1, s2, &i, &j);
	if (dst && !dst[0])
	{
		while (s1 && i < ft_strlen(s1))
		{
			dst[i] = s1[i];
			i++;
		}
		while (j < ft_strlen(s2))
		{
			dst[i] = s2[j];
			i++;
			j++;
		}
		free(s1);
		dst[i] = '\0';
		return (dst);
	}
	return (dst);
}
