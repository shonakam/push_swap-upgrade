/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radixsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:12:59 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/22 21:06:01 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	print_bits(unsigned int num) {
// 	int bit_count = sizeof(unsigned int) * 8;

// 	for (int i = bit_count - 1; i >= 0; i--) {
// 		printf("%d", (num >> i) & 1);
// 	}
// 	printf("\n");
// }

// static int	find_leftbit_position(t_stack **a)
// {
// 	unsigned int	max;
// 	int				position;

// 	max = ft_listsize(a) - 1;
// 	position = 0;
// 	while (0 < max)
// 	{
// 		position++;
// 		max = max >> 1;
// 	}
// 	return (position);
// }

// stack: a == bit1, b == bit0
void	ft_radixsort(t_stack **a, t_stack **b)
{
	unsigned int	size;
	unsigned int	shifter;

	shifter = 0u;
	while (!is_sorted(a))
	{
		size = ft_listsize(a);
		while (size--)
		{
			if (((*a)->null_node->next_node->c_val >> shifter & 1) == 0)
				do_push(a, b, "pb");
			else
				do_rotate(a, "ra");
		}
		while (ft_listsize(b))
			do_push(b, a, "pa");
		shifter++;
	}
}
