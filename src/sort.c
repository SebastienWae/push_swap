/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:34:42 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 16:01:47 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	sort_two(t_stacks *s, t_list **ops)
{
	int	top;
	int	btm;

	top = *((int *)(*s->a)->content);
	btm = *((int *)(*s->a)->next->content);
	if (top > btm)
		do_op(s, ops, ROTATE_A);
}

void	sort_three(t_stacks *s, t_list **ops)
{
	int	top;
	int	mid;
	int	btm;

	top = *((int *)(*s->a)->content);
	mid = *((int *)(*s->a)->next->content);
	btm = *((int *)(*s->a)->next->next->content);
	if (top > mid && mid > btm && top > btm)
	{
		do_op(s, ops, SWAP_A);
		do_op(s, ops, REVERSE_ROTATE_A);
	}
	else if (top > mid && btm > mid && top > btm)
		do_op(s, ops, ROTATE_A);
	else if (mid > top && mid > btm && btm > top)
	{
		do_op(s, ops, SWAP_A);
		do_op(s, ops, ROTATE_A);
	}
	else if (top > mid && btm > mid && btm > top)
		do_op(s, ops, SWAP_A);
	else if (mid > top && mid > btm && top > btm)
		do_op(s, ops, REVERSE_ROTATE_A);
}

void	sort_big(t_stacks *s, t_list **ops)
{
	t_state	inital_state;
	t_list	*priority_list;
	t_state	*top;

	while ((*s->a)->next)
		do_op(s, ops, PUSH_B);
	inital_state.stacks = s;
	inital_state.ops = ops;
	priority_list = ft_lstnew(&inital_state);
	while (*(((t_state *)priority_list->content)->stacks->b))
	{
		top = (t_state *)ft_lstpop(&priority_list)->content;
		prioritize(top, &priority_list);
	}
	*ops = *((t_state *)priority_list->content)->ops;
}
