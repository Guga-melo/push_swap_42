/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:08:39 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/06 12:04:41 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_islower(int mid, t_nlist *x)
{
	int i;
	int len;

	i = 0;
	len = x->len;
	while (i < len)
	{
		if (x->n[i] < mid)
			return (1);
		i++;
	}
	return (0);
}

int	ft_ishigher(int mid, t_nlist *x, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (x->n[i] > mid)
			return (1);
		i++;
	}
	return (0);
}

void	ft_chunk_size(t_nlist *x, int len)
{
	x->n_chunk++;
	if (x->n_chunk == 1)
		x->chunk = malloc(1 * sizeof(int));
	if (x->n_chunk > 1)
		ft_create_chunk(x);
	x->chunk[0] = len;
	int y = 0;
	while (y < x->n_chunk)
	{
		ft_printf("chunk[%d]--> %d\n", y, x->chunk[y]);
		y++;
	}
}

void ft_create_chunk(t_nlist *x)
{
	int i;
	int *n_temp;

	i = 0;
	n_temp = malloc(x->n_chunk * sizeof(int));
	while (i < x->n_chunk - 1)
	{
		n_temp[i + 1] = x->chunk[i];
		i++;
	}
	free(x->chunk);
	x->chunk = ft_intdup(n_temp, x->n_chunk);
	free(n_temp);
}

void ft_update_chunk(t_nlist *b, int i, int j)
{
	int *temp;
	int x;

	x = 0;
	temp = malloc(b->n_chunk * sizeof(int));
	if (b->n_chunk > 1)
	{
		while (x < b->n_chunk - 1)
		{
			temp[x + 1] = b->chunk[i + 1];
			x++;
		}
	}
	temp[0] = b->chunk[i] - j;
	free(b->chunk);
	b->chunk = ft_intdup(temp, b->n_chunk);
	free(temp);
	int y = 0;
	while (y < b->n_chunk)
	{
		ft_printf("chunk[%d]--> %d\n", y, b->chunk[y]);
		y++;
	}
}
