/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <tumolabs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:13:42 by monicaharut       #+#    #+#             */
/*   Updated: 2022/12/23 13:34:09 by tumolabs         ###   ########.fr       */
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
	int		step;
	int		b_size;
	int		a_size;
	int		ac;
	int		len;
	int		index;
	int		*numbers;
	char	**av;
	char	*str;
	char	**matrix;
}	t_struct;

int			is_sorted(t_list *a);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *str, char c);
int			ft_strlen(char *str);
int			ft_lst_size(t_list *listik);
long long	ft_atoi(char *str);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_lstadd_front(t_list **listik, t_list *new);
t_list		*ft_lstadd_back(t_list *lst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(int data);
int			find_pos(t_list *lst, int x);
int			sab(t_list *lst, int flag);
int			rab(t_list **lst, int flag);
int			rrab(t_list **lst, int flag);
int			pab(t_list **a, t_list **b, int flag);
int			checking_sort(t_struct *info, t_list **listik);
void		ft_error(void);
void		fill(t_struct *info);
void		alg_three(t_list **a);
void		before_indexing(t_list **lst);
void		fii_lst(t_list **lst, t_struct *info);
void		fill_lst(t_list **lst, t_struct *info);
void		indexing(t_list **lst, t_struct *info);
void		alg_five(t_list **a, t_list **b, t_struct *info);
void		titernik(t_struct *info, t_list **a, t_list **b);
#endif
