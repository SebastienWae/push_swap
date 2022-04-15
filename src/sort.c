/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 21:34:42 by seb               #+#    #+#             */
/*   Updated: 2022/04/15 11:58:15 by seb              ###   ########.fr       */
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

void	sort_small(t_stacks *s, t_list **ops)
{
	int		size;
	t_list	*smallest;

	size = ft_lstsize(*(s->a));
	while (size > 2)
	{
		do_op(s, ops, PUSH_B);
		size--;
	}
	while (*(s->b))
		nn(s, ops);
	smallest = ft_lstsmallest(s->a);
	if (ft_lstsize(smallest) > ft_lstsize(*(s->a)) / 2)
	{
		while (*(s->a) != smallest)
			do_op(s, ops, ROTATE_A);
	}
	else
	{
		while (*(s->a) != smallest)
			do_op(s, ops, REVERSE_ROTATE_A);
	}
}

static int	median_three(int a, int b, int c)
{
	if ((a > b) ^ (a > c))
		return (a);
	else if ((b < a) ^ (b < c))
		return (b);
	else
		return (c);
}

void	sort_big(t_stacks *s, t_list **ops)
{
	t_list	*smallest;
	t_list	*top;
	t_list	*mid;
	t_list	*btm;
	int		pivot1;
	int		pivot2;
	int		tmp;
	int		size;

	top = *(s->a);
	mid = ft_lstgetindex(s->a, ft_lstsize(*(s->a)) / 4);
	btm = ft_lstgetindex(s->a, ft_lstsize(*(s->a)) / 2);
	pivot1 = median_three(*((int *)top->content), *((int *)mid->content), *((int *)btm->content));
	top = ft_lstgetindex(s->a, ft_lstsize(*(s->a)) / 2 + 1);
	mid = ft_lstgetindex(s->a, ft_lstsize(*(s->a)) / 4 * 3);
	btm = ft_lstgetindex(s->a, ft_lstsize(*(s->a)));
	pivot2 = median_three(*((int *)top->content), *((int *)mid->content), *((int *)btm->content));
	if (pivot2 > pivot1)
	{
		tmp = pivot1;
		pivot1 = pivot2;
		pivot2 = tmp;
	}
	size = ft_lstsize(*(s->a));
	while (size--)
	{
		if (*((int *)(*(s->a))->content) < pivot2)
		{
			do_op(s, ops, PUSH_B);
			do_op(s, ops, ROTATE_B);
		}
		else if (*((int *)(*(s->a))->content) < pivot1)
		{
			do_op(s, ops, PUSH_B);
		}
		else
			do_op(s, ops, ROTATE_A);
	}
	size = ft_lstsize(*(s->a));
	while (size > 3)
	{
		do_op(s, ops, PUSH_B);
		size--;
	}
	if (size == 3)
		sort_three(s, ops);
	while (*(s->b))
		nn(s, ops);
	smallest = ft_lstsmallest(s->a);
	if (ft_lstsize(smallest) > ft_lstsize(*(s->a)) / 2)
	{
		while (*(s->a) != smallest)
			do_op(s, ops, ROTATE_A);
	}
	else
	{
		while (*(s->a) != smallest)
			do_op(s, ops, REVERSE_ROTATE_A);
	}
}
