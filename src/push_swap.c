/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:21:51 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/10 13:49:55 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int ft_push_swap(t_nlist *a, t_nlist *b)
{
	if (!ft_check_sort(a->n, a->len))
	{
		if (a->len == 2 && a->n[0] > a->n[1])
			ft_exec_sx(a, 'a');
		else if (a->len == 3)
			swap_three_case(a);
		else
		{
			while (!ft_check_sort(a->n, a->len))
			{
				swap_random_case(a, b);
				if (a->n[0] > a->n[1])
					ft_exec_sx(a, 'a');
				/*
				int i = 0;
				ft_printf("\n***Stack A before swap back***\n");
				while (i < a->len)
				{
					ft_printf("a[%d]--> %d\n", i, a->n[i]);
					i++;
				}
				i = 0;
				ft_printf("\n***Stack B before swap back***\n");
				while (i < b->len)
				{
					ft_printf("b[%d]--> %d\n", i, b->n[i]);
					i++;
				}
				*/
				swap_back_random_case(a, b);
				/*
				i = 0;
				ft_printf("\n***Stack A after swap back***\n");
				while (i < a->len)
				{
					ft_printf("a[%d]--> %d\n", i, a->n[i]);
					i++;
				}
				i = 0;
				ft_printf("\n***Stack B after swap back***\n");
				while (i < b->len)
				{
					ft_printf("b[%d]--> %d\n", i, b->n[i]);
					i++;
				}
				*/
			}
		}
		/*
		else if (a->len > 3 && a->len < 100)
			swap_five_case(a, b);
		*/
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_nlist a;
	t_nlist b;
	int	i;

	if (argc >= 2)
	{
		i = 0;
		a.len = argc - 1;
		b.len = 0;
		b.init = 0;
		b.n_chunk = 0;
		a.n = malloc((a.len) * sizeof(int));
		while (i < a.len)
		{
			a.n[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		ft_push_swap(&a, &b);
		/*
		int i = 0;
		ft_printf("\n***Stack A***\n");
		while (i < a.len)
		{
			ft_printf("a[%d]--> %d\n", i, a.n[i]);
			i++;
		}
		i = 0;
		ft_printf("\n***Stack B***\n");
		while (i < b.len)
		{
			ft_printf("b[%d]--> %d\n", i, b.n[i]);
			i++;
		}
		*/
		free(a.n);
		free(b.n);
		free(b.chunk);
	}
	return (0);
}
