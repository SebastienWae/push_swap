/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:49:36 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 12:03:54 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	place_in_queue(t_stacks *stack, t_moves moves, t_list **queue)
{
	enum e_dir	direction;

	direction = get_best_direction(moves);
}

void	prioritize(t_state *state, t_list **queue)
{
	t_stacks	new_stacks;
	t_moves		moves;

	new_stacks = init_stacks();
	new_stacks.a = state->stacks->b;
	new_stacks.b = state->stacks->b;
	while (*(new_stacks.b))
	{
		moves.rrb = ft_lstsize(*(new_stacks.b));
		moves.rb = ft_lstsize(*(state->stacks->b)) - moves.rrb;
		while (*(new_stacks.a))
		{
			moves.rra = ft_lstsize(*(new_stacks.a));
			moves.ra = ft_lstsize(*(state->stacks->a)) - moves.rra;
			place_in_queue(&new_stacks, moves, queue);
			*(new_stacks.a) = (*new_stacks.a)->next;
		}
		*(new_stacks.b) = (*new_stacks.b)->next;
	}
}

/*
	- prioritized list of state (stacks + ops)
	- take first state
	- if done return
	- remove from list
	- calculate all new possible states
	- place them in order in list
	- get next item from list
*/
