/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:43 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/13 13:52:12 by swaegene         ###   ########.fr       */
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
enum e_dir {
	RA_RB,
	RA_RRB,
	RRA_RRB,
	RRA_RB,
};

typedef struct s_stacks	t_stacks;
typedef struct s_arg	t_arg;
typedef struct s_state	t_state;
typedef struct s_moves	t_moves;
typedef void			(*t_op)(t_list **, t_list **);
typedef void			(*t_multi_op)(t_state *, t_moves);

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
struct	s_state
{
	t_stacks	*stacks;
	t_list		**ops;
};
struct	s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
};

t_stacks	init_stacks(void);
void		free_stacks(t_stacks *s);
t_list		**sort_stacks(t_stacks *s);

void		prioritize(t_state *state, t_list **queue);

void		sort_two(t_stacks *s, t_list **ops);
void		sort_three(t_stacks *s, t_list **ops);
void		sort_big(t_stacks *s, t_list **ops);

void		parse_args(char **args, int size, t_stacks *stacks);

void		flush_ops(t_list **ops);
void		do_op(t_stacks *s, t_list **ops, enum e_op op);
void		do_multi_ops(t_state *s, t_moves m, enum e_dir d);

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

void		ra_rb(t_state *s, t_moves m);
void		ra_rrb(t_state *s, t_moves m);
void		rra_rrb(t_state *s, t_moves m);
void		rra_rb(t_state *s, t_moves m);

enum e_dir	get_best_direction(t_moves moves);

t_list		*ft_lstpop(t_list **list);
void		ft_lstadd_before(t_list **list, t_list *node);

void		exit_error(t_stacks *s);
void		exit_success(t_stacks *s);

t_state		*clone_state(t_state *state);

int			min(int a, int b);
int			max(int a, int b);

#endif
