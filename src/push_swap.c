/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 08:48:41 by avillar           #+#    #+#             */
/*   Updated: 2022/06/15 10:06:31 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	main(int argc, char **argv)
{
	t_swap	*swap;

	if (argc < 2)
		return (0);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || swap == NULL || parse_nodup(swap) == 1)
	{
		write(2, "Error\n", 7);
		if (swap)
			free_swap(swap);
		return (1);
	}
	if (is_sorted(swap->a, swap->asize) == 1)
		algo_manage(swap);
	free_swap(swap);
	return (0);
}
