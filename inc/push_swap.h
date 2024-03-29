/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:20:42 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/10 10:32:12 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_nlist
{
	int *n;
	int nbr;
	int mid;
	int init;
	int len;
	int *chunk;
	int n_chunk;
}				t_nlist;

void	ft_exec_sx(t_nlist *x, int c);
void	ft_exec_px(t_nlist *x, t_nlist *y, int c);
void	ft_exec_rx(t_nlist *x, int c);
void	ft_exec_rrx(t_nlist *x, int c);
void	ft_get_top(t_nlist *y);
void	ft_push_to_fit(t_nlist *x);
int		swap_three_case(t_nlist *a);
void	swap_five_case(t_nlist *a, t_nlist *b);
void	swap_random_case(t_nlist *a, t_nlist *b);
int		ft_find_mid(int *n, int len);
int		ft_check_sort(int *n, int len);
int		*ft_intdup(int *n, int len);
int		ft_islower(int mid, t_nlist *x);
int		ft_ishigher(int mid, t_nlist *x, int len);
int 	swap_back_random_case(t_nlist *a, t_nlist *b);
void	ft_chunk_size(t_nlist *x, int len);
void	ft_create_chunk(t_nlist *x);
void	ft_update_chunk(t_nlist *b, int i, int j);

#endif
