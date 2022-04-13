/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:49:36 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 22:37:13 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	place_in_queue(t_state *s, t_moves moves, t_list **queue)
{
	enum e_dir	direction;
	int			op_count;
	t_list		*tmp;

	direction = get_best_direction(moves);
	do_multi_ops(s, moves, direction);
	do_op(s->stacks, s->ops, PUSH_A);
	op_count = ft_lstsize(*(s->ops));
	tmp = *queue;
	if (*queue)
	{
		if (ft_lstsize(*(((t_state *)tmp->content)->ops)) < op_count)
		{
			while (tmp
				&& ft_lstsize(*(((t_state *)tmp->content)->ops)) < op_count)
				tmp = tmp->next;
			ft_lstadd_before(queue, tmp, ft_lstnew(s));
		}
		else
			ft_lstadd_front(queue, ft_lstnew(s));
	}
	else
		*queue = ft_lstnew(s);
}

static t_list	*get_target(t_stacks *stacks)
{
	t_list	*stack_a;
	t_list	*target;
	t_list	*smallest;

	stack_a = *(stacks->a);
	target = NULL;
	smallest = stack_a;
	while (stack_a)
	{
		if (*((int *)(*(stacks->b))->content) <= *((int *)stack_a->content))
		{
			if (!target
				|| *((int *)stack_a->content) <= *((int *)target->content))
				target = stack_a;
		}
		if (*((int *)stack_a->content) <= *((int *)smallest->content))
			smallest = stack_a;
		stack_a = stack_a->next;
	}
	if (!target)
		target = smallest;
	return (target);
}

void	prioritize(t_state *state, t_list **queue)
{
	t_state		*new_state;
	t_stacks	*tmp_stacks;
	t_moves		moves;
	t_list		*target;

	tmp_stacks = init_stacks();
	ft_lstclone(state->stacks->a, tmp_stacks->a);
	ft_lstclone(state->stacks->b, tmp_stacks->b);
	while (*(tmp_stacks->b))
	{
		moves.rrb = ft_lstsize(*(tmp_stacks->b));
		moves.rb = ft_lstsize(*(state->stacks->b)) - moves.rrb;
		target = get_target(tmp_stacks);
		moves.rra = ft_lstsize(target);
		moves.ra = ft_lstsize(*(state->stacks->a)) - moves.rra;
		new_state = clone_state(state);
		place_in_queue(new_state, moves, queue);
		*(tmp_stacks->b) = (*tmp_stacks->b)->next;
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
