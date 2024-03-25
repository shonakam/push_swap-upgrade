/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_shorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:10:44 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:19:10 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	send_half_to_b(t_stack **a, t_stack **b)
{
	unsigned int	pivot;
	unsigned int	size;

	size = ft_listsize(a);
	pivot = (size / 2u);
	while (size / 2u > ft_listsize(b))
	{
		if (pivot > (*a)->null_node->next_node->c_val)
			do_push(a, b, "pb");
		else
			do_rotate(a, "ra");
	}
}

static void	send_to_a(t_stack **a, t_stack **b)
{
	if (ft_listsize(b) <= 2u)
	{
		if ((*b)->next_node->c_val < (*b)->next_node->next_node->c_val)
			do_swap(b, "sb");
	}
	else if (ft_listsize(b) == 3u)
		compare_three_value_b((*b)->next_node, (*b)->next_node->next_node);
	while (ft_listsize(b))
		do_push(b, a, "pa");
}

static void	sort_a(t_stack **a, t_stack **b)
{
	if (ft_listsize(a) <= 2u)
	{
		if ((*a)->next_node->c_val > (*a)->next_node->next_node->c_val)
			do_swap(a, "sa");
	}
	else if (ft_listsize(a) == 3u)
		compare_three_value_a((*a)->next_node, (*a)->next_node->next_node);
	send_to_a(a, b);
}

void	handle_shorts(t_stack **a, t_stack **b)
{
	if (3u < ft_listsize(a) && ft_listsize(a) < 6u)
	{
		send_half_to_b(a, b);
		sort_a(a, b);
	}
	else if (3u == ft_listsize(a))
		compare_three_value_a((**a).next_node, (**a).next_node->next_node);
	else
		if ((**a).next_node->c_val > (**a).next_node->next_node->c_val)
			do_swap(a, "sa");
}
