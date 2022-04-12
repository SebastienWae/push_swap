/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:34:42 by seb               #+#    #+#             */
/*   Updated: 2022/04/12 22:42:38 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

void	sort_two(t_stacks *s, t_list **ops)
{
	int	top;
	int	btm;

	top = *((int *)(*s->a)->content);
	btm = *((int *)(*s->a)->next->next->content);
	if (btm > top)
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
	(void)s;
	(void)ops;
}
