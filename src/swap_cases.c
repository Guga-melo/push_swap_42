/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:51:27 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/10 09:55:45 by gussoare         ###   ########.fr       */
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
	int size;

	size = a->len;
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
				if (a->n[0] > mid)
				{
					ft_exec_rx(a);
					ft_printf("ra\n");
				}
				else if (a->n[0] < mid && a->n[0] > a->n[1])
				{
					ft_exec_sx(a);
					ft_printf("sa\n");
				}
				else 
				{
					ft_exec_px(b, a);
					ft_printf("pb\n");
				}
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

	i = 0;
	while (b->n_chunk)
	{
		j = 0;
		y = 0;
		mid = ft_find_mid(b->n, b->chunk[i]);
		ft_printf("mid back--> %d\n", mid);
		ft_printf("chunk[%d]--> %d\n", i, b->chunk[i]);
		if (b->chunk[i] == 1)
		{
			ft_exec_px(a, b);
			ft_printf("pa\n");
		}
		else if (b->chunk[i] == 2)
		{
			if (b->n[0] < b->n[1])
			{
				ft_exec_sx(b);
				ft_printf("sb\n");
			}
			else
			{
				ft_exec_px(a, b);
				ft_exec_px(a, b);
				ft_printf("pa\npa\n");
			}
		}
		else if(ft_ishigher(mid, b, b->chunk[i]))
		{
			mid = ft_find_mid(b->n, b->chunk[i]);
			ft_printf("mid back--> %d\n", mid);
			while (1)
			{
				if (b->n[0] > mid)
				{
					ft_exec_px(a, b);
					ft_printf("pa\n");
					j++;
				}
				else if(b->n[1] > mid)
				{
					ft_exec_sx(b);
					ft_printf("sb\n");
				} 
				else if (b->n[b->len - 1] > mid && b->n_chunk == 1)
				{
					ft_exec_rrx(b);
					ft_printf("rrb\n");
				}
				else if (ft_ishigher(mid,b, b->chunk[i] - j))
				{
					ft_exec_rx(b);
					ft_printf("rb\n");
				}
				else
				{
					ft_update_chunk(b, i, j);
					return (swap_back_random_case(a, b));
				}
					
			}
		}
		i++;
		b->n_chunk--;
	}
	while (b->len != 0)
	{
		if (b->n[0] < b->n[1])
		{
			ft_exec_sx(b);
			ft_printf("sb\n");
		}
		else
		{
			ft_exec_px(a, b);
			ft_printf("pa\n");
		}
	}
	return (0);
}
