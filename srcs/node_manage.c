/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:36:27 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:10:25 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*ft_create_node(int val)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
	{
		ft_printf("\e[31mError[m1]: \e[0mmalloc error\n");
		exit(1);
	}
	new_node->value = val;
	new_node->c_val = UINT_MAX;
	new_node->prev_node = NULL;
	new_node->next_node = NULL;
	return (new_node);
}

void	init_stack(t_stack **stack)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_printf("\e[31mError[m1]: \e[0mmalloc error\n");
		exit(1);
	}
	(*stack)->value = 0;
	(*stack)->c_val = UINT_MAX;
	(*stack)->prev_node = (*stack);
	(*stack)->next_node = (*stack);
	(*stack)->null_node = (*stack);
}

void	all_node_free(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (head)
	{
		tmp = tmp->next_node;
		free(tmp->prev_node);
	}
}

void	ft_manage_node(t_stack **stack, int val)
{
	t_stack	*node;
	t_stack	*tail_node;

	node = ft_create_node(val);
	tail_node = (*stack)->null_node->prev_node;
	node->null_node = (*stack);
	tail_node->next_node = node;
	node->prev_node = tail_node;
	node->next_node = (*stack)->null_node;
	(*stack)->null_node->prev_node = node;
}
