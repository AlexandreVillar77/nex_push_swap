/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:11:24 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 11:11:32 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_rev_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] > tab[i])
			return (1);
		i++;
	}
	return (0);
}

int	next_isrevsort(int *tab, int size)
{
	if (size == 0)
		return (0);
	if (tab[0] > tab[1] && size > 0)
		return (0);
	return (1);
}

int	next_issorted(int *tab, int size)
{
	/*if (tab[0] == 100 || tab[0] == 75)
		ft_printf("size = %d\n", size);*/
	if (size == 0)
		return (0);
	if (tab[0] < tab[1] && size > 0)
		return (0);
	return (1);
}
