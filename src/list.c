/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:27:59 by seb               #+#    #+#             */
/*   Updated: 2022/04/14 08:48:19 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
