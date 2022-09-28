/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:08:39 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/28 13:19:50 by gussoare         ###   ########.fr       */
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
