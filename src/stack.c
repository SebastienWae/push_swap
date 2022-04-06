/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:26:58 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/06 17:24:12 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

t_list	*create_stack(int *values, int size)
{
	t_list	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		ft_lstadd_back(&stack, ft_lstnew(&values[i]));
		if (!stack)
			return (NULL);
		i++;
	}
	return (stack);
}

void	sort_stack(t_list *stack, t_list *instructions)
{
	t_list	*tmp_stack;

	(void)tmp_stack;
	(void)instructions;
	print_list("%d\n", stack);
}
