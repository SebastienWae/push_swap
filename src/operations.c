/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:47:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/07 15:40:33 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// push
// Take the first element at the top of src and put it at the top of dst.
void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*head;

	head = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_lstadd_front(stack_dst, head);
}

// rotate
// The first element becomes the last one.
void	rotate(t_list **stack)
{
	t_list	*head;

	head = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, head);
	head->next = NULL;
}

// reverse rotate
// The last element becomes the first one.
void	reverse_rotate(t_list **stack)
{
	t_list	*cur;
	t_list	*prev;

	cur = (*stack)->next;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	ft_lstadd_front(stack, cur);
}
