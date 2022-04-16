/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:34:27 by seb               #+#    #+#             */
/*   Updated: 2022/04/16 10:26:18 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	rotate(t_list **stack)
{
	t_list	*head;

	if (*stack)
	{
		head = *stack;
		if (head->next)
		{
			*stack = (*stack)->next;
			ft_lstadd_back(stack, head);
			head->next = NULL;
		}
	}
}

void	rotate_a(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	rotate(stack_a);
}

void	rotate_b(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	rotate(stack_b);
}

void	rotate_ab(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
