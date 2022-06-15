/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:06:17 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:07:17 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	*ft_numtabcpy(int *src, int size)
{
	int	i;
	int	*dst;

	i = 0;
	dst = malloc(sizeof(int) * size);
	if (!dst)
		return (0);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	catchmid(int *tab, int size)
{
	return (tab[size / 2]);
}

int	find_min(int *x, int size)
{
	int	i;
	int	min;

	i = 0;
	min = x[i];
	while (i < size)
	{
		if (min > x[i])
			min = x[i];
		i++;
	}
	return (min);
}

void	free_swap(t_swap *swap)
{
	if (swap->a)
		free(swap->a);
	if (swap->b)
		free(swap->b);
	if (swap)
		free(swap);
}
