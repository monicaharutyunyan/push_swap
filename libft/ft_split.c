/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:28:22 by monicaharut       #+#    #+#             */
/*   Updated: 2022/04/23 15:13:41 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_of_words(const char *string, char del)
{
	size_t	count;

	count = 0;
	while (*string != '\0')
	{
		if (*string != del && (*(string + 1) == del || *(string + 1) == '\0'))
			count++;
		string++;
	}
	return (count);
}

static char	**fill_string(char **store, const char *s, char del)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		if (*s != del)
		{
			len = 0;
			while (*s != '\0' && *s != del)
			{
				len++;
				s++;
			}
			store[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	store[i] = 0;
	return (store);
}

char	**ft_split(const char *string, char del)
{
	char	**str_arr;
	size_t	count;

	if (!string)
		return (NULL);
	count = count_of_words(string, del);
	str_arr = malloc(sizeof(char *) * (count + 1));
	if (!str_arr)
		return (NULL);
	str_arr = fill_string(str_arr, string, del);
	return (str_arr);
}
