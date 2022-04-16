/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:36:35 by seb               #+#    #+#             */
/*   Updated: 2022/04/16 10:26:24 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	reverse_rotate(t_list **stack)
{
	t_list	*cur;
	t_list	*prev;

	if (*stack)
	{
		cur = *stack;
		prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		if (prev)
		{
			prev->next = NULL;
			ft_lstadd_front(stack, cur);
		}
	}
}

void	reverse_rotate_a(t_list **stack_a, t_list **stack_b)
{
	(void)stack_b;
	reverse_rotate(stack_a);
}

void	reverse_rotate_b(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	reverse_rotate(stack_b);
}

void	reverse_rotate_ab(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
