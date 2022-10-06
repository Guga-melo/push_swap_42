/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:16:41 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/03 13:25:47 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_exec_sx(t_nlist *x)
{
	int temp;
	
	temp = x->n[0];
	x->n[0] = x->n[1];
	x->n[1] = temp;
}

void	ft_exec_px(t_nlist *x, t_nlist *y)
{
	x->len++;
	y->len--;
	y->nbr = y->n[0];
	if (x->len == 1 && x->init == 0)
	{
		x->n = malloc(sizeof(int));
		x->init = 1;
	}
	ft_get_top(y);
	if (x->len > 1)
		ft_push_to_fit(x);
	x->n[0] = y->nbr;
}

void	ft_exec_rx(t_nlist *x)
{
	int temp;
	int	len;
	int i;

	len = x->len - 1;
	i = 0;
	temp = x->n[0];
	while (i < len)
	{
		x->n[i] = x->n[i + 1];
		i++;
	}
	x->n[i] = temp;
}

void ft_exec_rrx(t_nlist *x)
{
	int temp;
	int len;

	len = x->len - 1;
	temp = x->n[len];
	while (len > 0)
	{
		x->n[len] = x->n[len - 1];
		len--;
	}
	x->n[0] = temp;
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
