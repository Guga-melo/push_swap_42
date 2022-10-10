/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:51:27 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/10 13:50:18 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int swap_three_case(t_nlist *a)
{
	//case 1
	if (a->n[0] > a->n[1] && a->n[1] < a->n[2] && a->n[0] < a->n[2])
		ft_exec_sx(a, 'a');
	//case 2
	else if (a->n[0] > a->n[1] && a->n[1] > a->n[2] && a->n[0] > a->n[2])
	{
		ft_exec_sx(a, 'a');
		ft_exec_rrx(a, 'a');
	}
	//case 3
	else if (a->n[0] > a->n[1] && a->n[1] < a->n[2] && a->n[0] > a->n[2])
		ft_exec_rx(a, 'a');
	//case 4
	else if (a->n[0] < a->n[1] && a->n[1] > a->n[2] && a->n[0] < a->n[2])
	{
		ft_exec_sx(a, 'a');
		ft_exec_rx(a, 'a');
	}
	//case 5;
	else 
		ft_exec_rrx(a, 'a');
	return (0);
}

void swap_five_case(t_nlist *a, t_nlist *b)
{
	while (a->len != 3)
		ft_exec_px(b, a, 'b');
	swap_three_case(a);
	while (b->len)
		ft_exec_px(a, b, 'a');
}

void	swap_random_case(t_nlist *a, t_nlist *b)
{
	int mid;
	int size;

	size = a->len;
	mid = ft_find_mid(a->n, a->len);
	//ft_printf("\nmid point--> %d\n", mid);
	while (ft_islower(mid, a) && a->len != 2)
	{
		if (a->n[1] < mid && a->n[1] < a->n[0])
			ft_exec_sx(a, 'a');
		else if (a->n[0] < mid)
			ft_exec_px(b, a, 'b');
		else if (a->n[a->len - 1] < mid)
		{
			while (a->n[a->len - 1] < mid && ft_islower(mid, a) && a->len != 2)
			{
				ft_exec_rrx(a, 'a');
				ft_exec_px(b, a, 'b');
			}
		}
		else
		{
			while (ft_islower(mid, a) && a->len != 2)
			{
				if (a->n[0] > mid)
					ft_exec_rx(a, 'a');
				else if (a->n[0] < mid && a->n[0] > a->n[1])
					ft_exec_sx(a, 'a');
				else 
					ft_exec_px(b, a, 'b');
			}
		}
	}
	ft_chunk_size(b, size - a->len);
	if (a->len != 2)
		swap_random_case(a, b);
}

int swap_back_random_case(t_nlist *a, t_nlist *b)
{
	
	int i;
	int mid;
	int j;
	int y;

	while (b->n_chunk)
	{
		i = 0;
		j = 0;
		y = 0;
		mid = ft_find_mid(b->n, b->chunk[i]);
		/*
		ft_printf("mid back--> %d\n", mid);
		ft_printf("n_chunk --> %d\n", b->n_chunk);
		while (j < b->n_chunk)
		{
			ft_printf("chunk[%d]--> %d\n", j, b->chunk[j]);
			j++;
		}
		j = 0;
		*/
		if (b->chunk[i] == 1)
			ft_exec_px(a, b, 'a');
		else if (b->chunk[i] == 2)
		{
			if (b->n[0] < b->n[1])
				ft_exec_sx(b, 'b');
			else
			{
				ft_exec_px(a, b, 'a');
				ft_exec_px(a, b, 'a');
			}
		}
		else if(ft_ishigher(mid, b, b->chunk[i]))
		{
			mid = ft_find_mid(b->n, b->chunk[i]);
			//ft_printf("mid back--> %d\n", mid);
			while (1)
			{
				if(b->n[1] > b->n[0] && b->n[1] > mid)
					ft_exec_sx(b, 'b');
				else if (b->n[0] > mid)
				{
					ft_exec_px(a, b, 'a');
					j++;
				}
				else if (b->n[b->len - 1] > mid && b->n_chunk == 1)
					ft_exec_rrx(b, 'b');
				else if (ft_ishigher(mid, b, b->chunk[i] - j))
				{
					ft_exec_rx(b, 'b');
					y++;
				}
				else
				{
					while (y--)
						ft_exec_rrx(b, 'b');
					ft_update_chunk(b, i, j);
					return (swap_back_random_case(a, b));
				}
			}
		}
		i++;
		b->n_chunk--;
		ft_update_chunk(b, i, j);
	}
	while (b->len != 0)
	{
		if (b->n[0] < b->n[1])
			ft_exec_sx(b, 'b');
		else
			ft_exec_px(a, b, 'a');
	}
	return (0);
}
