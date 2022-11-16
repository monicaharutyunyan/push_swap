/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: monicaharutyunyan <monicaharutyunyan@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:42 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/14 22:09:47 by monicaharut      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_struct
{
	int		ac;
	int		len;
	int		*numbers;
	char	**av;
	char	*str;
	char	**matrix;
}	t_struct;

void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		fill(t_struct *info);
void		ft_error(void);
int			ft_strlen(const char *str);
char		**ft_split(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
long long	ft_atoi(char *str);

#endif