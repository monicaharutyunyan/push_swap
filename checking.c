/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:18:07 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/14 20:20:09 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		++i;
		if (str[i] == '0')
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
		++i;
	if (!str[i])
		return (1);
	return (0);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		++i;
	}
	free(matrix);
}

int	is_not_double(t_struct *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->len - 1)
	{
		j = i + 1;
		while (j < info->len)
		{
			if (info->numbers[i] == info->numbers[j])
				return (0);
			++j;
		}
		++i;
	}
	return (1);
}

void	fill(t_struct *info)
{
	int	i;
	int	j;

	info->str = NULL;
	i = 0;
	while (++i < info->ac)
	{
		info->str = ft_strjoin(info->str, info->av[i]);
		info->str = ft_strjoin(info->str, " ");
	}
	info->matrix = ft_split(info->str, ' ');
	i = -1;
	while (info->matrix[++i])
	{
		if (!is_integer(info->matrix[i]))
			ft_error();
	}
	info->numbers = malloc(sizeof(int) * i);
	j = -1;
	while (++j < i)
		info->numbers[j] = ft_atoi(info->matrix[j]);
	free_matrix(info->matrix);
	info->len = i;
	if (!is_not_double(info))
		ft_error();
}
