/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:21:03 by seb               #+#    #+#             */
/*   Updated: 2022/04/12 22:23:07 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// swap
// Swap the first 2 elements at the top of the stack.
static void	swap(t_list **stack)
{
	t_list	*head;

	if (*stack)
	{
		head = *stack;
		*stack = (*stack)->next;
		head->next = (*stack)->next;
		(*stack)->next = head;
	}
}

void	swap_a(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	swap(stack_a);
}

void	swap_b(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	swap(stack_b);
}

void	swap_ab(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
