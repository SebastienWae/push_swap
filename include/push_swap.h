/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:43 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/07 18:32:14 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

enum e_op {
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
};

void	error(void);

t_list	*create_stack(int *values, int size);
void	sort_stack(t_list *stack);

int		*parse_args(char **args, int size);

void	do_op(t_list **stack_a, t_list **stack_b, enum e_op op);

void	print_list(char *format, t_list *head);
void	free_list(t_list *head);

#endif
