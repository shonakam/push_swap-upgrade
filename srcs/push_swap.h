/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 04:48:51 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 01:25:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./ft_printf/ft_printf.h"

typedef struct s_stack {
	struct s_stack	*prev_node;
	struct s_stack	*next_node;
	struct s_stack	*null_node;
	unsigned int	c_val;
	int				value;
	char			*name;
}				t_stack;

// handle_error
void			check_number(const char *s);
void			check_range(char *s);
void			check_samenum(int ac, char **av);

// list fx
unsigned int	ft_listsize(t_stack **stack);
void			ft_manage_node(t_stack **stack, int val);
void			init_stack(t_stack **stack);
void			all_node_free(t_stack **head);

// utils, supports
void			ft_compress(t_stack **a_stack, unsigned int c_val);
int				is_sorted(t_stack **a);
char			**ft_parse_args(char **av);
size_t			ft_arraysize(char **arr);
void			compare_three_value_a(t_stack *head, t_stack *second);
void			compare_three_value_b(t_stack *head, t_stack *second);

// sort_algorithm
void			ft_radixsort(t_stack **a, t_stack **b);
void			handle_shorts(t_stack **a, t_stack **b);
void			do_swap(t_stack **stack, char *action);
void			do_push(t_stack **from_s, t_stack **to_s, char *action);
void			do_rotate(t_stack **stack, char *action);
void			do_rev_rotate(t_stack **stack, char *action);
void			do_rotate_both(t_stack **a, t_stack **b, char *action);
void			handle_ops(char *action);

#endif
