/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:31:27 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:24:07 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compare_three_value_b(t_stack *head, t_stack *second)
{
	t_stack	*third;

	third = second->next_node;
	if (head->c_val > second->c_val && head->c_val < third->c_val)
	{
		do_swap(&head, "sb");
	}
	else if (head->c_val > second->c_val && second->c_val < third->c_val)
	{
		do_rotate(&head, "rb");
	}
	else if (head->c_val < second->c_val && head->c_val > third->c_val)
	{
		do_rev_rotate(&head, "rrb");
	}
	else if (head->c_val > second->c_val && second->c_val > third->c_val)
	{
		do_swap(&head, "sb");
		do_rev_rotate(&head, "rrb");
	}
	else if (head->c_val < second->c_val && second->c_val > third->c_val)
	{
		do_swap(&head, "sb");
		do_rotate(&head, "rb");
	}
}

void	compare_three_value_a(t_stack *head, t_stack *second)
{
	t_stack	*third;

	third = second->next_node;
	if (head->c_val > second->c_val && head->c_val < third->c_val)
	{
		do_swap(&head, "sa");
	}
	else if (head->c_val > second->c_val && second->c_val < third->c_val)
	{
		do_rotate(&head, "ra");
	}
	else if (head->c_val < second->c_val && head->c_val > third->c_val)
	{
		do_rev_rotate(&head, "rra");
	}
	else if (head->c_val > second->c_val && second->c_val > third->c_val)
	{
		do_swap(&head, "sa");
		do_rev_rotate(&head, "rra");
	}
	else if (head->c_val < second->c_val && second->c_val > third->c_val)
	{
		do_swap(&head, "sa");
		do_rotate(&head, "ra");
	}
}

int	is_sorted(t_stack **a)
{
	t_stack			*head;
	unsigned int	c ;

	head = (*a)->null_node->next_node;
	c = head->c_val;
	while (head != (*a)->null_node)
	{
		head = head->next_node;
		if (c > head->c_val)
			return (0);
		c = head->c_val;
	}
	return (1);
}

void	do_rotate_both(t_stack **a, t_stack **b, char *action)
{
	if (ft_strncmp(action, "rr", ft_strlen(action)) == 0)
	{
		do_rotate(a, "ra");
		do_rotate(b, "rb");
	}
	else if (ft_strncmp(action, "rrr", ft_strlen(action)) == 0)
	{
		do_rev_rotate(a, "rra");
		do_rev_rotate(b, "rrb");
	}
}
