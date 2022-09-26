/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:51:27 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/26 13:25:12 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int swap_three_case(int *a)
{
	//case 1
	if (a[0] > a[1] && a[1] < a[2])
	{
		ft_exec_sx(a);
		ft_printf("sa\n");
	}
	//case 2
	else if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
	{
		ft_exec_sx(a);
		ft_exec_rrx(a);
		ft_printf("sa\nrra\n");
	}
	//case 3
	else if (a[0] > a[1] && a[1] < a[2])
	{
		ft_exec_rx(a);
		ft_printf("ra\n");
	}
	//case 4
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
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

int swap_five_case(int *a, int *b, int len_a)
{
	int len_b
	ft_printf("len-> %d\n", len_a);
	while (len_a != 3)
	{
		ft_exec_px(b, a);
		ft_printf("pb\n");
	}
	ft_printf("a[0]-> %d | b[0]-> %d\n", a[0], b[0]);
	ft_printf("a[1]-> %d | b[1]-> %d\n", a[1], b[1]);
	ft_printf("a[2]-> %d | b[2]-> %d\n", a[2], b[2]);
	ft_printf("a[3]-> %d | b[3]-> %d\n", a[3], b[3]);
	ft_printf("\n");
	return (0);
}
