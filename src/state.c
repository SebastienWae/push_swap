/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:40:32 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/13 16:49:21 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	clone_ops(t_list **ops, t_list **new_ops)
{
	t_list	*tmp;

	tmp = *ops;
	while (tmp)
	{
		if (*new_ops)
			ft_lstadd_back(new_ops, ft_lstnew(tmp->content));
		else
			*new_ops = ft_lstnew(tmp->content);
		tmp = tmp->next;
	}
}

static void	clone_stacks(t_stacks *stacks, t_stacks *new_stacks)
{
	ft_lstclone(stacks->a, new_stacks->a);
	ft_lstclone(stacks->b, new_stacks->b);
}

t_state	*clone_state(t_state *state)
{
	t_state		*new_state;
	t_list		**new_ops;
	t_stacks	*new_stacks;	

	new_state = malloc(sizeof(t_state));
	new_ops = malloc(sizeof(t_list *));
	*new_ops = NULL;
	new_stacks = init_stacks();
	clone_ops(state->ops, new_ops);
	clone_stacks(state->stacks, new_stacks);
	new_state->stacks = new_stacks;
	new_state->ops = new_ops;
	return (new_state);
}
