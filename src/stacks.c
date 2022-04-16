/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:14:53 by seb               #+#    #+#             */
/*   Updated: 2022/04/16 21:30:09 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = malloc(sizeof(t_list *));
	if (!stacks->a)
	{
		free(stacks);
		return (NULL);
	}
	*(stacks->a) = NULL;
	stacks->b = malloc(sizeof(t_list *));
	if (!stacks->b)
	{
		free(stacks->a);
		free(stacks);
		return (NULL);
	}
	*(stacks->b) = NULL;
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
	free(s);
}

t_list	**sort_stacks(t_stacks *s)
{
	t_list	**ops;
	int		size;

	if (!ft_lstissorted(s->a))
	{
		ops = malloc(sizeof(t_list *));
		if (!ops)
			return (NULL);
		*ops = NULL;
		size = ft_lstsize(*(s->a));
		if (size == 2)
			sort_two(s, ops);
		else if (size == 3)
			sort_three(s, ops);
		else if (size < 10)
			sort_small(s, ops);
		else if (size > 1)
			sort_big(s, ops);
		return (ops);
	}
	return (NULL);
}
