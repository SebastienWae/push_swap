/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:14:53 by seb               #+#    #+#             */
/*   Updated: 2022/04/12 22:39:13 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stacks	init_stacks(void)
{
	t_stacks	stacks;

	stacks.a = malloc(sizeof(t_list *));
	*(stacks.a) = NULL;
	stacks.b = malloc(sizeof(t_list *));
	*(stacks.b) = NULL;
	return (stacks);
}

void	free_stacks(t_stacks *s)
{
	if (s->a)
	{
		ft_lstclear(s->a, free);
		free(s->a);
	}
	if (s->b)
	{
		ft_lstclear(s->b, free);
		free(s->b);
	}
}

t_list	**sort_stacks(t_stacks *s)
{
	t_list	**ops;
	int		size;

	ops = malloc(sizeof(t_list *));
	size = ft_lstsize(*(s->a));
	if (size == 1)
		*ops = NULL;
	else if (size == 2)
	{
		if (*((int *)(*s->a)->content) > *((int *)(*s->a)->next->content))
			do_op(s, ops, ROTATE_A);
	}
	else if (size == 3)
		sort_small(s, ops);
	else
		sort_big(s, ops);
	return (ops);
}
