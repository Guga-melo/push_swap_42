/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:16:41 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/26 10:55:55 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exec_sx(int *x)
{
	int temp;
	
	temp = x[0];
	x[0] = x[1];
	x[1] = temp;
}

void	ft_exec_px(int *x, int *y)
{
	int i;
	int temp;

	i = 0;
	temp = ft_get_top(y);
	ft_push_to_fit(x);
	x[0] = temp;
}

void	ft_exec_rx(int *x)
{
	int temp;
	int	len;
	int i;

	len = ft_intlen(x);
	i = 0;
	temp = x[0];
	while (i <= len)
	{
		x[i] = x[i + 1];
		i++;
	}
	x[i] = temp;
	x[i + 1] = '\0';
}

void ft_exec_rrx(int *x)
{
	int temp;
	int i;
	int len;

	len = ft_intlen(x) - 1;
	temp = x[len];
	i = len;
	while (i > 0)
	{
		x[i] = x[i - 1];
		i--;
	}
	x[0] = temp;
}

/*#include <stdio.h>

int main()
{
	int a[5];
	int b[5];

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 0;
	a[4] = 0;

	b[0] = 4;
	b[1] = 5;
	b[2] = 6;
	b[3] = 0;
	b[4] = 0;
	ft_exec_px(a, b);
	int i;
	i = 0;
	while (a[i] ||  b[i])
	{
		printf("a[%d]--> %d | b[%d]--> %d\n", i, a[i], i, b[i]);
		i++;
	}
	return (0);
}*/
