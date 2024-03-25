/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:56:48 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:17:05 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_ops(char *action)
{
	ft_printf("%s\n", action);
}

size_t	ft_arraysize(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		i++;
	return (i + 1);
}

unsigned int	ft_listsize(t_stack **stack)
{
	t_stack			*tmp_node;
	unsigned int	i;

	tmp_node = (*stack)->null_node->next_node;
	i = 1;
	while (tmp_node != (*stack)->null_node)
	{
		tmp_node = tmp_node->next_node;
		i++;
	}
	return (i - 1);
}

static int	search_minimal_value(t_stack *node)
{
	int	tmp_val;

	tmp_val = INT_MAX;
	while (node != node->null_node)
	{
		if (node->value < tmp_val && node->c_val == UINT_MAX)
		{
			tmp_val = node->value;
		}
		node = node->next_node;
	}
	return (tmp_val);
}

void	ft_compress(t_stack **stack, unsigned int c_val)
{
	int				min_val;
	t_stack			*tmp_node;

	while (ft_listsize(stack) > c_val)
	{
		tmp_node = (*stack)->null_node->next_node;
		min_val = search_minimal_value(tmp_node);
		while (tmp_node != tmp_node->null_node)
		{
			if (tmp_node->value == min_val && tmp_node->c_val == UINT_MAX)
			{
				tmp_node->c_val = c_val;
				break ;
			}
			tmp_node = tmp_node->next_node;
		}
		c_val++;
	}
}
