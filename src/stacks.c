/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:14:53 by seb               #+#    #+#             */
/*   Updated: 2022/04/12 21:05:33 by seb              ###   ########.fr       */
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

t_list	*sort_stacks(t_stacks *s)
{
	t_list	*ops;
	int		*i;

	(void)s;
	i = malloc(sizeof(int));
	*i = PUSH_A;
	ops = ft_lstnew(i);
	return (ops);
}
