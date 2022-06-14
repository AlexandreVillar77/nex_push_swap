/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:38:52 by avillar           #+#    #+#             */
/*   Updated: 2022/06/14 12:29:30 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	s_to_ss(t_swap *swap, int num)
{
	if (swap->asize > 1 && swap->bsize > 1)
	{
		if ((swap->bchunk->size > 1 && swap->b[0] < swap->b[1])
			&& swap->achunk->size > 1 && swap->a[0] > swap->a[1])
			ss(swap);
		else if ((swap->bchunk->size == 2 && swap->b[0] < swap->b[1])
			&& (swap->asize == 2 && is_sorted(swap->a, swap->asize) == 1))
			ss(swap);
	}
	else if (num == 0)
		sa(swap);
	else if (num == 1)
		sb(swap);
}