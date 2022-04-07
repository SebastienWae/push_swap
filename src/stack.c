/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:26:58 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/07 18:39:02 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <ft_printf.h>

t_list	*create_stack(int *values, int size)
{
	t_list	*stack;
	t_list	*node;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		node = ft_lstnew(&values[i]);
		if (!node)
			error();
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (stack);
}

void	sort_stack(t_list *stack_a)
{
	t_list	*stack_b;

	stack_b = NULL;
	do_op(&stack_a, &stack_b, PA);
	do_op(&stack_a, &stack_b, PB);
	do_op(&stack_a, &stack_b, RA);
	do_op(&stack_a, &stack_b, RB);
	do_op(&stack_a, &stack_b, RR);
	do_op(&stack_a, &stack_b, RRA);
	do_op(&stack_a, &stack_b, RRB);
	do_op(&stack_a, &stack_b, RRR);
	ft_printf("-------\n");
	print_list("%d\n", stack_a);
	ft_printf("-------\n");
	print_list("%d\n", stack_b);
}
