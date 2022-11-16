/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:39:02 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/14 15:40:04 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	word_count(char *str, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			count++;
		}
		if (!str[i])
			break ;
		i++;
	}
	return (count);
}

char	*word_allocate(char *str, char c)
{
	int			i;
	char		*str_malloc;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	str_malloc = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_malloc)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		str_malloc[i] = str[i];
		i++;
	}
	str_malloc[i] = '\0';
	return (str_malloc);
}

char	**ft_split(char *str, char c)
{
	size_t	i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (word_count(str, c) + 1));
	if (!arr)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
		{
			arr[i] = word_allocate(str, c);
			if (!arr[i])
				return (NULL);
			i++;
		}
		while (*str && *str != c)
			str++;
	}
	arr[i] = NULL;
	return (arr);
}
