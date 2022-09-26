/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:20:42 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/26 13:26:06 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

typedef struct s_list
{
	int *a;
	int next;
}				t_list;

void	ft_exec_sx(int *x);
void	ft_exec_px(int *x, int *y);
void	ft_exec_rx(int *x);
void	ft_exec_rrx(int *x);
int		ft_intlen(int *n);
int		ft_get_top(int *y);
void	ft_push_to_fit(int *x);
int		swap_three_case(int *a);
int		swap_five_case(int *a, int *b, int len_a);

#endif
