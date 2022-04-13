/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_multi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:18:39 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/13 13:34:11 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra_rb(t_state *s, t_moves moves)
{
	while (moves.ra > 0 && moves.rb > 0)
	{
		do_op(s->stacks, s->ops, ROTATE_AB);
		moves.ra--;
		moves.rb--;
	}
	while (moves.ra > 0)
	{
		do_op(s->stacks, s->ops, ROTATE_A);
		moves.ra--;
	}
	while (moves.rb > 0)
	{
		do_op(s->stacks, s->ops, ROTATE_B);
		moves.rb--;
	}
}

void	ra_rrb(t_state *s, t_moves moves)
{
	while (moves.ra > 0)
	{
		do_op(s->stacks, s->ops, ROTATE_A);
		moves.ra--;
	}
	while (moves.rrb > 0)
	{
		do_op(s->stacks, s->ops, REVERSE_ROTATE_B);
		moves.rrb--;
	}
}

void	rra_rrb(t_state *s, t_moves moves)
{
	while (moves.rra > 0 && moves.rrb > 0)
	{
		do_op(s->stacks, s->ops, REVERSE_ROTATE_AB);
		moves.rra--;
		moves.rrb--;
	}
	while (moves.rra > 0)
	{
		do_op(s->stacks, s->ops, REVERSE_ROTATE_A);
		moves.rra--;
	}
	while (moves.rrb > 0)
	{
		do_op(s->stacks, s->ops, REVERSE_ROTATE_B);
		moves.rrb--;
	}
}

void	rra_rb(t_state *s, t_moves moves)
{
	while (moves.rra > 0)
	{
		do_op(s->stacks, s->ops, REVERSE_ROTATE_A);
		moves.rra--;
	}
	while (moves.rb > 0)
	{
		do_op(s->stacks, s->ops, ROTATE_B);
		moves.rb--;
	}
}
