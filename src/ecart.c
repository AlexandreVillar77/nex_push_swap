/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ecart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:39:42 by avillar           #+#    #+#             */
/*   Updated: 2022/06/03 10:45:22 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	find_ecart_min(t_swap *swap)
{
	int	i;
	int	min;

	i = 0;
	min = find_min(swap->a, swap->asize);
	while (i < swap->asize && i != min)
		i++;
	return (i);
}

int	find_ecart_max(t_swap *swap)
{
	int	i;
	int	max;

	i = 0;
	max = find_max(swap->a, swap->asize);
	while (i < swap->asize && i != max)
		i++;
	return (i);
}
