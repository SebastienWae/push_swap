/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:43 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/15 11:58:33 by seb              ###   ########.fr       */
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
	REVERSE_ROTATE_AB
};
enum e_dir {
	RA_RB,
	RA_RRB,
	RRA_RRB,
	RRA_RB
};

typedef struct s_stacks	t_stacks;
typedef struct s_arg	t_arg;
typedef struct s_state	t_state;
typedef struct s_moves	t_moves;
typedef void			(*t_op)(t_list **, t_list **);
typedef void			(*t_multi_op)(t_stacks *, t_list **, t_moves);

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
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	enum e_dir	dir;
};

t_stacks	*init_stacks(void);
void		free_stacks(t_stacks *s);
t_list		**sort_stacks(t_stacks *s);

void		get_lis(t_stacks *s, t_list **lis_start, t_list **lis_end);
void		nn(t_stacks *s, t_list **ops);

void		sort_two(t_stacks *s, t_list **ops);
void		sort_three(t_stacks *s, t_list **ops);
void		sort_small(t_stacks *s, t_list **ops);
void		sort_big(t_stacks *s, t_list **ops);

void		parse_args(char **args, int size, t_stacks *stacks);

void		flush_ops(t_list **ops);
void		do_op(t_stacks *s, t_list **ops, enum e_op op);
void		do_multi_ops(t_stacks *s, t_list **ops, t_moves moves);

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

void		ra_rb(t_stacks *s, t_list **ops, t_moves moves);
void		ra_rrb(t_stacks *s, t_list **ops, t_moves moves);
void		rra_rrb(t_stacks *s, t_list **ops, t_moves moves);
void		rra_rb(t_stacks *s, t_list **ops, t_moves moves);

enum e_dir	get_best_direction(t_moves moves);

t_list		*ft_lstsmallest(t_list **list);
t_list		*ft_lstgetindex(t_list **list, int index);

void		exit_error(t_stacks *s);
void		exit_success(t_stacks *s);

int			min(int a, int b);
int			max(int a, int b);

#endif
