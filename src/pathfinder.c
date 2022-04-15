/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:49:36 by seb               #+#    #+#             */
/*   Updated: 2022/04/14 14:23:32 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

static t_moves	get_least_moves(t_moves a, t_moves b)
{
	int	a_total;
	int	b_total;

	if (a.dir == RA_RB)
		a_total = max(a.ra, a.rb);
	else if (a.dir == RA_RRB)
		a_total = a.ra + a.rrb;
	else if (a.dir == RRA_RRB)
		a_total = max(a.rra, a.rrb);
	else
		a_total = max(a.rra, a.rb);
	if (b.dir == RA_RB)
		b_total = max(b.ra, b.rb);
	else if (b.dir == RA_RRB)
		b_total = b.ra + b.rrb;
	else if (b.dir == RRA_RRB)
		b_total = max(b.rra, b.rrb);
	else
		b_total = max(b.rra, b.rb);
	if (a_total < b_total)
		return (a);
	else
		return (b);
}

void	get_lis(t_stacks *s, t_list **lis_start, t_list **lis_end)
{
	t_list	*node;
	t_list	*tmp_lis_start;
	t_list	*tmp_lis_end;

	node = *(s->a);
	tmp_lis_start = node;
	tmp_lis_end = node;
	while (node)
	{
		if (*((int *)node->content) > *((int *)tmp_lis_end->content))
			tmp_lis_end = node;
		else
		{
			if (!*lis_start)
			{
				*lis_start = tmp_lis_start;
				*lis_end = tmp_lis_end;
			}
			else if (ft_lstsize(tmp_lis_start) - ft_lstsize(tmp_lis_end)
				> ft_lstsize(*lis_start) - ft_lstsize(*lis_end))
			{
				*lis_start = tmp_lis_start;
				*lis_end = tmp_lis_end;
			}
			tmp_lis_start = node;
			tmp_lis_end = node;
		}
		node = node->next;
	}
}

void	nn(t_stacks *s, t_list **ops)
{
	t_stacks	tmp;
	t_moves		curr_moves;
	t_moves		least_moves;
	t_list		*target;

	tmp.a = s->a;
	tmp.b = s->b;
	curr_moves.dir = 0;
	least_moves.dir = 0;
	while (*(tmp.b))
	{
		curr_moves.rrb = ft_lstsize(*(tmp.b));
		curr_moves.rb = ft_lstsize(*(s->b)) - curr_moves.rrb;
		target = get_target(&tmp);
		curr_moves.rra = ft_lstsize(target);
		curr_moves.ra = ft_lstsize(*(s->a)) - curr_moves.rra;
		curr_moves.dir = get_best_direction(curr_moves);
		if (*(tmp.b) == *(s->b))
			least_moves = curr_moves;
		else
			least_moves = get_least_moves(curr_moves, least_moves);
		tmp.b = &((*(tmp.b))->next);
	}
	do_multi_ops(s, ops, least_moves);
	do_op(s, ops, PUSH_A);
}
