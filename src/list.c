/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:27:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/15 11:45:14 by seb              ###   ########.fr       */
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
