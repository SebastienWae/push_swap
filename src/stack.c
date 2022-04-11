/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:26:58 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/11 17:17:40 by swaegene         ###   ########.fr       */
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

int	reverse(t_list *stack, t_list *smallest)
{
	int	size;
	int	i;

	size = ft_lstsize(stack);
	i = ft_lstsize(smallest);

	if (size - i > size / 2)
		return (1);
	else
		return (0);
}

void	get_r(t_list *stack_a, t_list *stack_b, t_list *node, int *ra, int *rb, int *rra, int *rrb)
{
	int	size_b;
	int	pos;
	t_list	*tmp;
	t_list	*prev;

	size_b = ft_lstsize(stack_b);
	pos = ft_lstsize(node);
	*rb = size_b - pos;
	if (stack_b->next)
		*rrb = pos;
	else
		*rrb = 0;
	tmp = stack_a;	
	prev = NULL;
	while (tmp)
	{
		if (!prev && *((int *)tmp->content) > *((int *)node->content))
			prev = tmp;
		else if (prev && *((int *)tmp->content) < *((int *)prev->content) && *((int *)tmp->content) > *((int *)node->content))
			prev = tmp;
		tmp = tmp->next;
	}
	if (prev)
	{
		*ra = ft_lstsize(stack_a) - ft_lstsize(prev);
		*rra = ft_lstsize(prev);
	}
	else
	{
		tmp = stack_a;	
		prev = tmp;
		while (tmp)
		{
			if (*((int *)tmp->content) > *((int *)prev->content))
				prev = tmp;
			tmp = tmp->next;
		}
		*ra = ft_lstsize(stack_a) - ft_lstsize(prev) + 1;
		*rra = ft_lstsize(prev) - 1;
	}
}

void	smart_reverse_rotate(t_list **stack_a, t_list **stack_b, int rra, int rrb)
{
	while (rra > 0 && rrb > 0)
	{
		do_op(stack_a, stack_b, REVERSE_ROTATE_AB);
		rra--;
		rrb--;
	}
	while (rra > 0)
	{
		do_op(stack_a, stack_b, REVERSE_ROTATE_A);
		rra--;
	}
	while (rrb > 0)
	{
		do_op(stack_a, stack_b, REVERSE_ROTATE_B);
		rrb--;
	}
}

void	smart_rotate(t_list **stack_a, t_list **stack_b, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		do_op(stack_a, stack_b, ROTATE_AB);
		ra--;
		rb--;
	}
	while (ra > 0)
	{
		do_op(stack_a, stack_b, ROTATE_A);
		ra--;
	}
	while (rb > 0)
	{
		do_op(stack_a, stack_b, ROTATE_B);
		rb--;
	}
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_moves	better_move(t_moves best, t_moves curr)
{
	int	ra_rb;
	int	ra_rrb;
	int	rra_rrb;
	int	rra_rb;
	int	best_low;
	int curr_low;

	ra_rb = max(best.ra, best.rb);
	ra_rrb =best.ra + best.rrb;
	rra_rrb = max(best.rra, best.rrb);
	rra_rb = best.rra + best.rb;
	if (ra_rb <= ra_rrb && ra_rb <= rra_rrb && ra_rb <= rra_rb)
	{
		best_low = ra_rb;
		best.dir = RA_RB;
	}
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rrb && ra_rrb <= rra_rb)
	{
		best_low = ra_rrb;
		best.dir = RA_RRB;
	}
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
	{
		best_low = rra_rrb;
		best.dir = RRA_RRB;
	}
	else
	{
		best_low = rra_rb;
		best.dir = RRA_RB;
	}
	ra_rb = max(curr.ra, curr.rb);
	ra_rrb =curr.ra + curr.rrb;
	rra_rrb = max(curr.rra, curr.rrb);
	rra_rb = curr.rra + curr.rb;
	if (ra_rb <= ra_rrb && ra_rb <= rra_rrb && ra_rb <= rra_rb)
	{
		curr_low = ra_rb;
		curr.dir = RA_RB;
	}
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rrb && ra_rrb <= rra_rb)
	{
		curr_low = ra_rrb;
		curr.dir = RA_RRB;
	}
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
	{
		curr_low = rra_rrb;
		curr.dir = RRA_RRB;
	}
	else
	{
		curr_low = rra_rb;
		curr.dir = RRA_RB;
	}
	if (best_low >= curr_low)
		return (curr);
	return (best);
}

void	do_smart_moves(t_list **stack_a, t_list **stack_b, t_moves moves)
{
	if (moves.dir == RA_RB)
	{
		while (moves.ra > 0 && moves.rb > 0)
		{
			do_op(stack_a, stack_b, ROTATE_AB);
			moves.ra--;
			moves.rb--;
		}
		while (moves.ra > 0)
		{
			do_op(stack_a, stack_b, ROTATE_A);
			moves.ra--;
		}
		while (moves.rb > 0)
		{
			do_op(stack_a, stack_b, ROTATE_B);
			moves.rb--;
		}
	}
	else if (moves.dir == RA_RRB)
	{
		while (moves.ra > 0 && moves.rrb > 0)
		{
			do_op(stack_a, stack_b, ROTATE_AB);
			moves.ra--;
			moves.rrb--;
		}
		while (moves.ra > 0)
		{
			do_op(stack_a, stack_b, ROTATE_A);
			moves.ra--;
		}
		while (moves.rrb > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_B);
			moves.rrb--;
		}
	}
	else if (moves.dir == RRA_RRB)
	{
		while (moves.rra > 0 && moves.rrb > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_AB);
			moves.rra--;
			moves.rrb--;
		}
		while (moves.rra > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_A);
			moves.rra--;
		}
		while (moves.rrb > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_B);
			moves.rrb--;
		}
	}
	else if (moves.dir == RRA_RB)
	{
		while (moves.rra > 0 && moves.rb > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_AB);
			moves.rra--;
			moves.rb--;
		}
		while (moves.rra > 0)
		{
			do_op(stack_a, stack_b, REVERSE_ROTATE_A);
			moves.rra--;
		}
		while (moves.rb > 0)
		{
			do_op(stack_a, stack_b, ROTATE_B);
			moves.rb--;
		}
	}
}

void	do_best_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_a_node;
	t_list	*stack_b_node;
	t_list	*target;
	t_list	*biggest;
	t_moves	best_moves;
	t_moves	curr_moves;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	stack_a_node = *stack_a;
	best_moves.dir = NO_DIR;
	while (stack_a_node)
	{
		curr_moves.rra = ft_lstsize(stack_a_node);
		curr_moves.ra = size_a - curr_moves.rra;
		if (size_b)
		{
			stack_b_node = *stack_b;
			target = NULL;
			biggest = stack_b_node;
			while (stack_b_node)
			{
				if (*((int *)stack_a_node->content) >= *((int *)stack_b_node->content)
					&& (!target || *((int *)stack_b_node->content) >= *((int *)target->content)))
					target = stack_b_node;
				if (*((int *)stack_b_node->content) >= *((int *)biggest->content))
					biggest = stack_b_node;
				stack_b_node = stack_b_node->next;
			}
			if (!target)
				target = biggest;	
			curr_moves.rrb = ft_lstsize(target);
			curr_moves.rb =  size_b - curr_moves.rrb;
		}
		else
		{
			curr_moves.rb = 0;
			curr_moves.rrb = 0;
		}
		if (best_moves.dir == NO_DIR)
			best_moves = curr_moves;
		else
			best_moves = better_move(best_moves, curr_moves);
		stack_a_node = stack_a_node->next;
	}
	do_smart_moves(stack_a, stack_b, best_moves);
}

void	sort_stack(t_list *stack_a)
{
	t_list	*stack_b;
	int		max_val;

	stack_b = NULL;
	max_val = *((int *)stack_a->content);
	while (stack_a)
	{
		if (*((int *)stack_a->content) > max_val)
			max_val = *((int *)stack_a->content);
		do_best_move(&stack_a, &stack_b);
		do_op(&stack_a, &stack_b, PUSH_B);
	}
	print_list("%d\n", stack_b);
	//while (*(int *)stack_b->content != max_val)
	//	do_op(&stack_a, &stack_b, ROTATE_B);
	//while (stack_b)
	//	do_op(&stack_a, &stack_b, PUSH_A);
	//print_list("%d\n", stack_a);
}
