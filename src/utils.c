/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 10:49:46 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/22 12:38:32 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int ft_intlen(int *n)
{
	int i;

	i = 0;
	while (n[i])
		i++;
	return (i);
}

int	ft_get_top(int *y)
{
	int i;
	int nbr;

	i = 0;
	nbr = y[0];
	while (y[i + 1])
	{
		y[i] = y[i + 1];
		i++;
	}
	y[i] = '\0';
	return (nbr);
}

void	ft_push_to_fit(int *x)
{
	int i;
	int len;

	i = 0;
	len = ft_intlen(x);
	while (len >= 0)
	{
		x[len + 1] = x[len];
		len--;
	}
}
