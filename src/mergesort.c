/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:57:08 by seb               #+#    #+#             */
/*   Updated: 2022/04/16 13:24:15 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_list	*sorted_merge(t_list *a, t_list *b)
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (*((int *)a->content) <= *((int *)b->content))
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

static void	front_back_split(t_list *source, t_list **start, t_list **end)
{
	t_list	*fast;
	t_list	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*start = source;
	*end = slow->next;
	slow->next = NULL;
}

void	merge_sort(t_list **list)
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *list;
	if ((head == NULL) || (head->next == NULL))
		return ;
	front_back_split(head, &a, &b);
	merge_sort(&a);
	merge_sort(&b);
	*list = sorted_merge(a, b);
}
