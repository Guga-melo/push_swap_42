/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:51:27 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/28 14:26:06 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int swap_three_case(t_nlist *a)
{
	//case 1
	if (a->n[0] > a->n[1] && a->n[1] < a->n[2] && a->n[0] < a->n[2])
	{
		ft_exec_sx(a);
		ft_printf("sa\n");
	}
	//case 2
	else if (a->n[0] > a->n[1] && a->n[1] > a->n[2] && a->n[0] > a->n[2])
	{
		ft_exec_sx(a);
		ft_exec_rrx(a);
		ft_printf("sa\nrra\n");
	}
	//case 3
	else if (a->n[0] > a->n[1] && a->n[1] < a->n[2] && a->n[0] > a->n[2])
	{
		ft_exec_rx(a);
		ft_printf("ra\n");
	}
	//case 4
	else if (a->n[0] < a->n[1] && a->n[1] > a->n[2] && a->n[0] < a->n[2])
	{
		ft_exec_sx(a);
		ft_exec_rx(a);
		ft_printf("sa\nra\n");
	}
	//case 5;
	else 
	{
		ft_exec_rrx(a);
		ft_printf("rra\n");
	}
	return (0);
}

void swap_five_case(t_nlist *a, t_nlist *b)
{
	while (a->len != 3)
	{
		ft_exec_px(b, a);
		ft_printf("pb\n");
	}
	swap_three_case(a);
	while (b->len)
	{
		ft_exec_px(a, b);
		ft_printf("pa\n");
	}
}

void	swap_random_case(t_nlist *a, t_nlist *b)
{
	int mid;
	mid = ft_find_mid(a->n, a->len);
	ft_printf("\nmid point--> %d\n", mid);
	while (ft_islower(mid, a) && a->len != 2)
	{
		if (a->n[0] < mid)
		{
			ft_exec_px(b, a);
			ft_printf("pb\n");
		}
		else if (a->n[a->len - 1] < mid)
		{
			while (a->n[a->len - 1] < mid && ft_islower(mid, a) && a->len != 2)
			{
				ft_exec_rrx(a);
				ft_printf("rra\n");
				ft_exec_px(b, a);
				ft_printf("pb\n");
			}
		}
		else
		{
			while (ft_islower(mid, a) && a->len != 2)
			{
				if (a->n[0] >= mid)
				{
					ft_exec_rx(a);
					ft_printf("ra\n");
				}
				else
				{
					ft_exec_px(b, a);
					ft_printf("pb\n");
				}
			}
		}
	}
	if (a->len != 2)
		swap_random_case(a, b);

}
