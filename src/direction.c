/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:00:04 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 12:06:04 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

enum e_dir	get_best_direction(t_moves moves)
{
	int	ra_rb;
	int	ra_rrb;
	int	rra_rrb;
	int	rra_rb;

	ra_rb = max(moves.ra, moves.rb);
	ra_rrb = moves.ra + moves.rrb;
	rra_rrb = max(moves.rra, moves.rrb);
	rra_rb = moves.rra + moves.rb;
	if (ra_rb <= ra_rrb && ra_rb <= rra_rrb && ra_rb <= rra_rb)
		return (RA_RB);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rrb && ra_rrb <= rra_rb)
		return (RA_RRB);
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
		return (RRA_RRB);
	else
		return (RRA_RB);
}

void	smart_RA_RB(t_stacks *stacks, t_moves moves)
{
	while (moves.ra > 0 && moves.rb > 0)
	{
		do_op(stacks, ROTATE_AB);
		moves.ra--;
		moves.rb--;
	}
	while (moves.ra > 0)
	{
		do_op(stack_a, stack_b, ROTATE_A);
		moves.ra--;
	}
	while (moves.rb > 0)
	{
		do_op(stack_a, stack_b, ROTATE_B);
		moves.rb--;
	}
}

void	do_smart_moves(t_list **stack_a, t_list **stack_b, t_moves moves)
{
	if (moves.dir == RA_RB)
	{
	}
	else if (moves.dir == RA_RRB)
	{
		while (moves.ra > 0)
		{
			do_op(stack_a, stack_b, ROTATE_A);
			moves.ra--;
		}
		while (moves.rrb > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_B);
			moves.rrb--;
		}
	}
	else if (moves.dir == RRA_RRB)
	{
		while (moves.rra > 0 && moves.rrb > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_AB);
			moves.rra--;
			moves.rrb--;
		}
		while (moves.rra > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_A);
			moves.rra--;
		}
		while (moves.rrb > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_B);
			moves.rrb--;
		}
	}
	else if (moves.dir == RRA_RB)
	{
		while (moves.rra > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_A);
			moves.rra--;
		}
		while (moves.rb > 0)
		{
			do_op(stack_a, stack_b, ROTATE_B);
			moves.rb--;
		}
	}
}
