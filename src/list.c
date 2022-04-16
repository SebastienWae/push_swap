/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:27:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/16 12:47:42 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstsmallest(t_list **list)
{
	t_list	*ret;
	t_list	*tmp;

	tmp = *list;
	ret = tmp;
	while (tmp)
	{
		if (*((int *)tmp->content) < *((int *)ret->content))
			ret = tmp;
		tmp = tmp->next;
	}
	return (ret);
}

t_list	*ft_lstgetindex(t_list **list, int index)
{
	t_list	*tmp;
	int		i;

	tmp = *list;
	i = 1;
	while (tmp)
	{
		if (index == i)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

t_list	*ft_lstclone(t_list **src)
{
	t_list	*tmp;
	t_list	*clone;

	tmp = *src;
	clone = NULL;
	while (tmp)
	{
		if (clone)
			ft_lstadd_back(&clone, ft_lstnew(tmp->content));
		else
			clone = ft_lstnew(tmp->content);
		tmp = tmp->next;
	}
	return (clone);
}

int	ft_lstissorted(t_list **list)
{
	t_list	*node;
	t_list	*prev;

	node = *list;
	prev = node;
	while (node)
	{
		if (*((int *)prev->content) > *((int *)node->content))
			return (0);
		prev = node;
		node = node->next;
	}
	return (1);
}
