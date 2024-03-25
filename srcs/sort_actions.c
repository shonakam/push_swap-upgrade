/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:05:25 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:23:42 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	delete_node(t_stack *f_head)
{
	if (ft_listsize(&f_head) == 1u)
	{
		f_head->null_node->next_node = f_head->null_node;
		f_head->null_node->prev_node = f_head->null_node;
		return ;
	}
	f_head->next_node->prev_node = f_head->null_node;
	f_head->null_node->next_node = f_head->next_node;
}

void	do_push(t_stack **from_s, t_stack **to_s, char *action)
{
	t_stack	*f_head;
	t_stack	*t_head;

	f_head = (*from_s)->null_node->next_node;
	t_head = (*to_s)->null_node->next_node;
	delete_node(f_head);
	f_head->next_node = t_head;
	f_head->prev_node = (*to_s)->null_node;
	f_head->null_node = (*to_s)->null_node;
	t_head->prev_node = f_head;
	(*to_s)->null_node->next_node = f_head;
	handle_ops(action);
}

void	do_swap(t_stack **stack, char *action)
{
	t_stack	*head;
	t_stack	*next;

	head = (*stack)->null_node->next_node;
	next = head->next_node;
	next->null_node->next_node = next;
	next->prev_node = next->null_node;
	next->next_node->prev_node = head;
	head->next_node = next->next_node;
	next->next_node = head;
	head->prev_node = next;
	handle_ops(action);
}

void	do_rotate(t_stack **stack, char *action)
{
	t_stack	*head;
	t_stack	*tail;

	head = (*stack)->null_node->next_node;
	tail = (*stack)->null_node->prev_node;
	tail->next_node = head;
	head->prev_node = tail;
	head->next_node->prev_node = head->null_node;
	head->null_node->next_node = head->next_node;
	head->null_node->prev_node = head;
	head->next_node = head->null_node;
	handle_ops(action);
}

void	do_rev_rotate(t_stack **stack, char *action)
{
	t_stack	*head;
	t_stack	*tail;

	head = (*stack)->null_node->next_node;
	tail = (*stack)->null_node->prev_node;
	tail->prev_node->next_node = (*stack)->null_node;
	(*stack)->null_node->prev_node = tail->prev_node;
	(*stack)->null_node->next_node = tail;
	tail->prev_node = (*stack)->null_node;
	tail->next_node = head;
	head->prev_node = tail;
	handle_ops(action);
}
