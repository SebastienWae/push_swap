/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:49:36 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 13:52:00 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	place_in_queue(t_state *s, t_moves moves, t_list **queue)
{
	enum e_dir	direction;
	int			op_count;
	t_list		*tmp_queue;

	direction = get_best_direction(moves);
	do_multi_ops(s, moves, direction);
	op_count = ft_lstsize(*s->ops);
	tmp_queue = *queue;
	while (ft_lstsize(*(((t_state *)tmp_queue->content)->ops)) < op_count)
		tmp_queue = tmp_queue->next;
	ft_lstadd_before(queue, tmp_queue);
}

void	prioritize(t_state *state, t_list **queue)
{
	t_state		*new_state;
	t_stacks	tmp_stacks;
	t_moves		moves;

	tmp_stacks = init_stacks();
	tmp_stacks.a = state->stacks->b;
	tmp_stacks.b = state->stacks->b;
	while (*(tmp_stacks.b))
	{
		moves.rrb = ft_lstsize(*(tmp_stacks.b));
		moves.rb = ft_lstsize(*(state->stacks->b)) - moves.rrb;
		while (*(tmp_stacks.a))
		{
			new_state = clone_state(state);
			moves.rra = ft_lstsize(*(tmp_stacks.a));
			moves.ra = ft_lstsize(*(state->stacks->a)) - moves.rra;
			place_in_queue(new_state, moves, queue);
			*(tmp_stacks.a) = (*tmp_stacks.a)->next;
		}
		*(tmp_stacks.b) = (*tmp_stacks.b)->next;
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
