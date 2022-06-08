/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:06:17 by avillar           #+#    #+#             */
/*   Updated: 2022/06/08 10:10:59 by avillar          ###   ########.fr       */
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
	if (size % 2 == 0)
		return (tab[size / 2]);
	else
		return (tab[(size - 1) / 2]);
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