/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:21:51 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/26 13:08:08 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int ft_push_swap(int *a, int *b, int n_nbr)
{
	if (n_nbr == 2 && a[0] > a[1])
	{
		ft_exec_sx(a);
		ft_printf("sa\n");
	}
	else if (n_nbr == 3)
		swap_three_case(a);
	else if (n_nbr > 3 && n_nbr < 100)
		swap_five_case(a, b, n_nbr);
	return (0);
}

int	main(int argc, char **argv)
{
	int	*a;
	int	*b;
	int	i;
	int	len;

	if (argc >= 2)
	{
		i = 0;
		a = NULL;
		b = NULL;
		len = argc - 1;
		a = malloc((len) * sizeof(int));
		b = malloc((len) * sizeof(int));
		while (i < len)
		{
			a[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		ft_push_swap(a, b, len);
		int i = 0;
		while (i < len)
		{
			ft_printf("a[%d]--> %d | b[%d]--> %d\n", i, a[i], i, b[i]);
			i++;
		}
		free(a);
		free(b);
	}
	return (0);
}
