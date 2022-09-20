/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:21:51 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/20 14:38:29 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int ft_check_swap(int *a, int *b, int len)
{
	int	i;

	i = 0;
	if (*a && b == 0)
	{
		while (a[i] && i < len)
		{
			if (a[i] < a[i + 1] && a[i + 1] != 0)
				i++;
			else
				break ;
		}
		if (a[i + 1] == 0)
			return (1);
	}
	return (0);
}

static void ft_push_swap(int *a, int *b, int len)
{
	while (42)
	{
		if (ft_check_swap(a, b, len))
		{
			ft_printf("FINISHED!!\n");
			break ;
		}
		if (a[0] > a[1])
			ft_exec_sx(a);
		else if (b[0] > b[1])
			ft_exec_sx(b);
	}
}

static int n_nbr(char **nbr)
{
	int i;

	i = 0;
	while (nbr[i])
		i++;
	return (i - 1);
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
		len = n_nbr(argv);
		a = malloc((len + 1) * sizeof(int));
		b = ft_calloc((len + 1), sizeof(int));
		while (i < len)
		{
			a[i] = ft_atoi(argv[i + 1]);
			ft_printf("%d\n", a[i]);
			i++;
		}
		a[i] = 0;
		ft_push_swap(a, b, len);
	}
	return (0);
}
