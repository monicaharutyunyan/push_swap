/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharutyu <mharutyu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:42 by monicaharut       #+#    #+#             */
/*   Updated: 2022/11/18 15:52:41 by mharutyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				index;
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

char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *str, char c);
int			ft_strlen(char *str);
long long	ft_atoi(char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
t_list		*ft_lstadd_back(t_list *lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int data);
void		fill_lst(t_list **lst, t_struct *info);
void		fii_lst(t_list **lst, t_struct *info);
void		fill(t_struct *info);
void		before_indexing(t_list **lst);
void		indexing(t_list **lst, t_struct *info);
void		ft_error(void);
#endif
