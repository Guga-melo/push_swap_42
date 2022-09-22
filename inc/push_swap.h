/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:20:42 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/22 12:40:49 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

void	ft_exec_sx(int *x);
void	ft_exec_px(int *x, int *y);
void	ft_exec_rx(int *x);
void	ft_exec_rrx(int *x, int len);
int		ft_intlen(int *n);
int		ft_get_top(int *y);
void	ft_push_to_fit(int *x);

#endif
