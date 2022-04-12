/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:47:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/12 18:23:36 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ft_printf.h>

static void	print_op(void *value)
{
	char	*op_str[8];

	op_str[PUSH_A] = "pa";
	op_str[PUSH_B] = "pb";
	op_str[ROTATE_A] = "ra";
	op_str[ROTATE_B] = "rb";
	op_str[ROTATE_AB] = "rr";
	op_str[REVERSE_ROTATE_A] = "rra";
	op_str[REVERSE_ROTATE_B] = "rrb";
	op_str[REVERSE_ROTATE_AB] = "rrr";
	ft_printf("%s\n", op_str[*((int *)value)]);
}

void	flush_ops(t_list *ops)
{
	ft_lstiter(ops, print_op);
	ft_lstclear(&ops, NULL);
}

void	do_op(t_stacks *s, enum e_op op)
{
	t_op	ops[8];

	ops[PUSH_A] = push_a;
	ops[PUSH_B] = push_b;
	ops[ROTATE_A] = rotate_a;
	ops[ROTATE_B] = rotate_b;
	ops[ROTATE_AB] = rotate_ab;
	ops[REVERSE_ROTATE_A] = reverse_rotate_a;
	ops[REVERSE_ROTATE_B] = reverse_rotate_b;
	ops[REVERSE_ROTATE_AB] = reverse_rotate_ab;
	ops[op](s->a, s->b);
}
