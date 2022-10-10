/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:49:46 by gussoare          #+#    #+#             */
/*   Updated: 2022/10/10 13:35:50 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_find_mid(int *n, int len)
{
	int i;
	int aux;
	int *temp;

	temp = ft_intdup(n, len);
	while (!ft_check_sort(temp, len))
	{
		i = 0;
		while (i < len - 1)
		{
			if (temp[i] > temp[i + 1])
			{
				aux = temp[i];
				temp[i] = temp[i + 1];
				temp[i + 1] = aux;
			}
			i++;
		}
	}
	len -= 1;
	aux = temp[len / 2];
	free(temp);
	return (aux);
}

int	ft_check_sort(int *n, int len)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (n[i] > n[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int *ft_intdup(int *n, int len)
{
	int i;
	int *temp;

	temp = malloc((len) * sizeof(int));
	i = 0;
	while (i < len)
	{
		temp[i] = n[i];
		i++;
	}
	return(temp);
}

void	ft_get_top(t_nlist *y)
{
	int i;
	int *n_temp;

	i = 0;
	n_temp = malloc(y->len * sizeof(int));
	while (i < y->len)
	{
		n_temp[i] = y->n[i + 1];
		i++;
	}
	free(y->n);
	y->n = ft_intdup(n_temp, y->len);
	free(n_temp);
}

void	ft_push_to_fit(t_nlist *x)
{
	int i;
	int *n_temp;

	i = 0;
	n_temp = malloc((x->len) * sizeof(int));
	while (i < x->len - 1)
	{
		n_temp[i + 1] = x->n[i];
		i++;
	}
	free(x->n);
	x->n = ft_intdup(n_temp, x->len);
	free(n_temp);
}

