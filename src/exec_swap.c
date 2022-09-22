/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:16:41 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/22 09:35:39 by gussoare         ###   ########.fr       */
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

void	ft_exec_rx(int *x)
{
	int temp;
	int i;

	i = 0;
	temp = x[0];
	while (x[i + 1])
	{
		x[i] = x[i + 1];
		i++;
	}
	x[i] = temp;
	x[i + 1] = '\0';
}

void ft_exec_rrx(int *x, int len)
{
	int temp;
	int i;

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
	int a[4];

	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = '\0';

	ft_exec_rrx(a, 2);
	int i;
	i = 0;
	while (a[i])
	{
		printf("a[%d]--> %d\n", i, a[i]);
		i++;
	}
	return (0);
}*/
