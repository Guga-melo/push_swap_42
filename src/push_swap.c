/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 13:21:51 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/22 09:56:49 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int ft_check_swap(int *a, int *b, int len)
{
	int	i;

	i = 0;
	if (a[i] && !*b)
	{
		while (a[i] && i < len)
		{
			if (a[i] < a[i + 1] && a[i + 1] != '\0')
				i++;
			else
				break ;
		}
		if (a[i + 1] == '\0')
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
		if (a[0] > a[1] && b[0] > b[1])
		{
			ft_exec_sx(a);
			ft_exec_sx(b);
			ft_printf("ss\n");
		}
		else if (a[0] > a[1])
		{
			ft_exec_sx(a);
			ft_printf("sa\n");
		}
		else if (b[0] > b[1])
		{
			ft_exec_sx(b);
			ft_printf("sb\n");
		}
		else if (a[0] > a[len - 1] && b[0] > b[len - 1])
		{
			ft_exec_rx(a);
			ft_exec_rx(b);
			ft_printf("rr\n");
		}
		else if (a[0] > a[len - 1])
		{
			ft_exec_rx(a);
			ft_printf("ra\n");
		}
		else if (b[0] > b[len - 1])
		{
			ft_exec_rx(b);
			ft_printf("rb\n");
		}
		else if (a[0] < a[len - 1] && b[0] < b[len])
		{
			ft_exec_rrx(a, len - 1);
			ft_exec_rrx(b, len - 1);
			ft_printf("rrr\n");
		}
		else if (a[0] < a[len - 1])
		{
			ft_exec_rrx(a, len - 1);
			ft_printf("rra\n");
		}	
		else if (b[0] < b[len])
		{
			ft_exec_rrx(b, len - 1);
			ft_printf("rrb\n");
		}

		else
			break ;
	}
}

static int n_nbr(char **nbr)
{
	int i;

	i = 0;
	while (nbr[i + 1])
		i++;
	return (i);
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
			i++;
		}
		a[i] = '\0';
		ft_push_swap(a, b, len);
		int i = 0;
		while (a[i])
		{
			ft_printf("a[%d]--> %d\n", i, a[i]);
			i++;
		}
		free(a);
		free(b);
	}
	return (0);
}
