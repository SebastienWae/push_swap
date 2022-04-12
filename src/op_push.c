/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:32:39 by seb               #+#    #+#             */
/*   Updated: 2022/04/12 17:33:25 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// push
// Take the first element at the top of src and put it at the top of dst.
static void	push(t_list **stack_dst, t_list **stack_src)
{
	t_list	*head;

	if (*stack_src)
	{
		head = *stack_src;
		*stack_src = (*stack_src)->next;
		ft_lstadd_front(stack_dst, head);
	}
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}
