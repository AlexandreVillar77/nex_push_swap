/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:08:52 by avillar           #+#    #+#             */
/*   Updated: 2022/06/13 13:03:38 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	sort_3a(t_swap *swap)
{
	int	i;

	i = 0;
	if (is_rev_sorted(swap->a, swap->asize))
	{
		sa(swap);
		rra(swap);
	}
	if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2]
		&& swap->a[1] < swap->a[2])
		sa(swap);
	if (swap->a[0] > swap->a[1] && swap->a[0] > swap->a[2]
		&& swap->a[1] < swap->a[2])
		ra(swap);
	if (swap->a[2] < swap->a[0] && swap->a[1] > swap->a[0])
		rra(swap);
}