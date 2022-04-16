/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 13:22:56 by seb               #+#    #+#             */
/*   Updated: 2022/04/16 21:26:09 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>

static void	get_pivots(t_list **list, int pivots[2])
{
	int		p[3];
	t_list	*o;

	o = ft_lstclone(list);
	merge_sort(&o);
	p[0] = *((int *)(o)->content);
	p[1] = *((int *)(ft_lstgetindex(&o, ft_lstsize(o) / 4))->content);
	p[2] = *((int *)(ft_lstgetindex(&o, ft_lstsize(o) / 2))->content);
	pivots[0] = median(p, 3);
	p[0] = *((int *)(ft_lstgetindex(&o, ft_lstsize(o) / 2))->content);
	p[1] = *((int *)(ft_lstgetindex(&o, ft_lstsize(o) / 4 * 3))->content);
	p[2] = *((int *)(ft_lstgetindex(&o, ft_lstsize(o)))->content);
	pivots[1] = median(p, 3);
	ft_lstclear(&o, NULL);
}

void	chunk(t_stacks *s, t_list **ops)
{
	int		pivots[2];
	int		size;

	get_pivots(s->a, pivots);
	size = ft_lstsize(*(s->a));
	while (size--)
	{
		if (*((int *)(*(s->a))->content) < pivots[0])
		{
			do_op(s, ops, PUSH_B);
			do_op(s, ops, ROTATE_B);
		}
		else if (*((int *)(*(s->a))->content) < pivots[1])
		{
			do_op(s, ops, PUSH_B);
		}
		else
			do_op(s, ops, ROTATE_A);
	}
}
