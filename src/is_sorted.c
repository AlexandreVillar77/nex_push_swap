/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:11:24 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:05:32 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	f_sorta(t_swap *swap)
{
	int	*fact;
	int	i;
	int	rtn;

	fact = ft_numtabcpy(swap->a, swap->achunk->size);
	i = 0;
	if (!fact)
		return (0);
	while (is_sorted(fact, swap->achunk->size) == 1
		&& i < swap->achunk->size - 1)
	{
		if (fact[i] > fact[i + 1])
		{	
			ft_swap(&(fact[i]), &(fact[i + 1]));
			i = -1;
		}
		i++;
	}
	rtn = catchmid(fact, swap->achunk->size);
	if (fact)
		free(fact);
	return (rtn);
}

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
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
	while (i < size - 1 && tab[i])
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
	if (size == 0)
		return (0);
	if (tab[0] < tab[1] && size > 0)
		return (0);
	return (1);
}
