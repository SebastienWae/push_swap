/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:27:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 13:59:40 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstpop(t_list **list)
{
	t_list	*node;

	node = *list;
	*list = node->next;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_before(t_list **list, t_list *node, t_list *new)
{
	t_list	*curr;
	t_list	*prev;

	curr = *list;
	prev = NULL;
	while (curr && curr != node)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev)
	{
		new->next = curr;
		prev->next = new;
	}
}
