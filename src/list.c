/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:27:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 22:18:36 by seb              ###   ########.fr       */
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

void	ft_lstadd_before(t_list **list, t_list *node, t_list *elem)
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
		elem->next = curr;
		prev->next = elem;
	}
}

void	ft_lstclone(t_list **list, t_list **clone)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (!*clone)
			*clone = ft_lstnew(tmp->content);
		else
			ft_lstadd_back(clone, ft_lstnew(tmp->content));
		tmp = tmp->next;
	}
}

int	ft_lstsmallest(t_list **list)
{
	int		ret;
	t_list	*tmp;

	tmp = *list;
	ret = *((int *)tmp->content);
	while (tmp)
	{
		if (*((int *)tmp->content) < ret)
			ret = *((int *)tmp->content);
		tmp = tmp->next;
	}
	return (ret);
}
