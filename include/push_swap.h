/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:43 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/12 22:23:18 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

enum e_op {
	SWAP_A,
	SWAP_B,
	SWAP_AB,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_AB,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_AB,
};

typedef struct s_stacks	t_stacks;
typedef struct s_arg	t_arg;
typedef void			(*t_op)(t_list **, t_list **);

struct	s_stacks
{
	t_list	**a;
	t_list	**b;
};
struct	s_arg
{
	int			error:1;
	long int	value;
};

t_stacks	init_stacks(void);
void		free_stacks(t_stacks *s);
t_list		**sort_stacks(t_stacks *s);

void		sort_small(t_stacks *s, t_list **ops);
void		sort_big(t_stacks *s, t_list **ops);

void		parse_args(char **args, int size, t_stacks *stacks);

void		do_op(t_stacks *s, t_list **ops, enum e_op op);
void		flush_ops(t_list **ops);

void		swap_a(t_list **stack_a, t_list **stack_b);
void		swap_b(t_list **stack_a, t_list **stack_b);
void		swap_ab(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_a, t_list **stack_b);
void		rotate_a(t_list **stack_a, t_list **stack_b);
void		rotate_b(t_list **stack_a, t_list **stack_b);
void		rotate_ab(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_a(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_b(t_list **stack_a, t_list **stack_b);
void		reverse_rotate_ab(t_list **stack_a, t_list **stack_b);

void		exit_error(t_stacks *s);
void		exit_success(t_stacks *s);

#endif
