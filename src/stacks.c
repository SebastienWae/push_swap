/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:14:53 by seb               #+#    #+#             */
/*   Updated: 2022/04/12 20:40:43 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
		free(s->a);
	}
}

t_list	*sort_stacks(t_stacks *s)
{
	t_list	*ops;
	int	*i;

	(void)s;
	i = malloc(sizeof(int));
	*i = PUSH_A;
	ops = ft_lstnew(i);
	return (ops);
}
