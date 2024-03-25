/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 04:45:30 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:24:25 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_err(int ac, char **arg)
{
	size_t	i;
	int		prev;

	i = 0;
	if (ft_arraysize(arg) == 2)
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit(1);
	}
	while (arg[i])
	{
		check_number(arg[i]);
		check_range(arg[i]);
		i++;
	}
	check_samenum(ac, arg);
	while (arg[--ac])
	{
		prev = ft_atoi(arg[ac - 1]);
		if (prev > ft_atoi(arg[ac]))
			break ;
		if (ac == 2)
			exit(0);
	}
}

static void	handle_initialize(t_stack **a_stack, t_stack **b_stack, char **ag)
{
	int	i;

	init_stack(a_stack);
	init_stack(b_stack);
	(*a_stack)->null_node->name = "-- A --";
	(*b_stack)->null_node->name = "-- B --";
	i = 0;
	while (ag[i])
	{
		ft_manage_node(a_stack, ft_atoi(ag[i]));
		i++;
	}
	ft_compress(a_stack, 0u);
}

static void	free_node(t_stack **n)
{
	t_stack	*next;
	t_stack	*current;

	current = (*n)->next_node;
	(*n)->next_node = NULL;
	while (current->next_node != NULL)
	{
		next = current->next_node;
		free(current);
		current = next;
	}
}

int	main(int ac, char **av)
{
	t_stack		*a_stack;
	t_stack		*b_stack;
	char		**new_arg;

	if (av[1] == NULL)
		exit(1);
	(void)ac;
	new_arg = ft_parse_args(av);
	if (new_arg)
		handle_err((int)ft_arraysize(new_arg), new_arg);
	handle_initialize(&a_stack, &b_stack, new_arg);
	if (ft_listsize(&a_stack) < 6u)
		handle_shorts(&a_stack, &b_stack);
	else
		ft_radixsort(&a_stack, &b_stack);
	free_node(&a_stack);
	free_node(&b_stack);
}

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q a.out");
// }
