/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:47:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/07 18:10:31 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <push_swap.h>

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

// rotate
// The first element becomes the last one.
static void	rotate(t_list **stack)
{
	t_list	*head;

	head = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, head);
	head->next = NULL;
}

// reverse rotate
// The last element becomes the first one.
static void	reverse_rotate(t_list **stack)
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

void	do_op(t_list **stack_a, t_list **stack_b, char *op)
{
	if (!ft_strncmp(op, "pa", ft_strlen(op)))
		push(stack_a, stack_b);
	else if (!ft_strncmp(op, "pb", ft_strlen(op)))
		push(stack_b, stack_a);
	else if (!ft_strncmp(op, "ra", ft_strlen(op)))
		rotate(stack_a);
	else if (!ft_strncmp(op, "rb", ft_strlen(op)))
		rotate(stack_b);
	else if (!ft_strncmp(op, "rr", ft_strlen(op)))
		rotate(stack_a);
	else if (!ft_strncmp(op, "rra", ft_strlen(op)))
		reverse_rotate(stack_a);
	else if (!ft_strncmp(op, "rrb", ft_strlen(op)))
		reverse_rotate(stack_b);
	else if (!ft_strncmp(op, "rrr", ft_strlen(op)))
		reverse_rotate(stack_a);
	ft_printf("%s\n", op);
}
