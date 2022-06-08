/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:04:55 by avillar           #+#    #+#             */
/*   Updated: 2022/06/08 12:06:41 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	find_max(int *tab, int size)
{
	int	i;
	int	max;

	max = tab[0];
	i = 0;
	while (i < size)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}

int	find_nearest(t_swap *swap, int max)
{
	int	i;
	int	near[2];

	i = -1;
	near[0] = 0;
	near[1] = 0;
	while (++i < swap->asize / 2)
	{
		if (swap->a[i] < max && near[0] == 0)
			near[0] = i;
	}
	while (i < swap->asize)
	{
		if (swap->a[i] < max)
			near[1] = swap->asize - i;
		i++;
	}
	if  (near[0] < near[1] && near[0] != 0)
		return (0);
	else
		return (1);
}

int	ft_hereis(int *tab, int max, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (tab[i] < max)
			return (0);
	return (1);
}