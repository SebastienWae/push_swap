/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:43 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/11 16:42:27 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

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
	NO_DIR,
};

typedef struct s_moves	t_moves;

struct	s_moves
{
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	enum e_dir	dir;	
};

void	error(void);

t_list	*create_stack(int *values, int size);
void	sort_stack(t_list *stack);

int		*parse_args(char **args, int size);

void	do_op(t_list **stack_a, t_list **stack_b, enum e_op op);

void	print_list(char *format, t_list *head);
void	free_list(t_list *head);

#endif
