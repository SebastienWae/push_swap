/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:47:33 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/12 22:23:14 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <ft_printf.h>

static void	print_op(void *value)
{
	ft_printf("%s\n", (char *)value);
}

static char	*get_op_str(enum e_op op)
{
	char	*op_str[11];

	op_str[SWAP_A] = "sa";
	op_str[SWAP_B] = "sb";
	op_str[SWAP_AB] = "ss";
	op_str[PUSH_A] = "pa";
	op_str[PUSH_B] = "pb";
	op_str[ROTATE_A] = "ra";
	op_str[ROTATE_B] = "rb";
	op_str[ROTATE_AB] = "rr";
	op_str[REVERSE_ROTATE_A] = "rra";
	op_str[REVERSE_ROTATE_B] = "rrb";
	op_str[REVERSE_ROTATE_AB] = "rrr";
	return (op_str[op]);
}

void	flush_ops(t_list **ops)
{
	ft_lstiter(*ops, print_op);
	free(ops);
}

void	do_op(t_stacks *s, t_list **ops, enum e_op op)
{
	t_op	ops_f[11];

	ops_f[SWAP_A] = swap_a;
	ops_f[SWAP_B] = swap_b;
	ops_f[SWAP_AB] = swap_ab;
	ops_f[PUSH_A] = push_a;
	ops_f[PUSH_B] = push_b;
	ops_f[ROTATE_A] = rotate_a;
	ops_f[ROTATE_B] = rotate_b;
	ops_f[ROTATE_AB] = rotate_ab;
	ops_f[REVERSE_ROTATE_A] = reverse_rotate_a;
	ops_f[REVERSE_ROTATE_B] = reverse_rotate_b;
	ops_f[REVERSE_ROTATE_AB] = reverse_rotate_ab;
	ops_f[op](s->a, s->b);
	if (*ops)
		ft_lstadd_back(ops, ft_lstnew(get_op_str(op)));
	else
		*ops = ft_lstnew(get_op_str(op));
}
