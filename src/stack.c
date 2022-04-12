/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:26:58 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/12 11:19:29 by seb              ###   ########.fr       */
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
	ra_rrb = curr.ra + curr.rrb;
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

int	in_list(t_list *list, int value)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	same_list(t_list *list_a, t_list *list_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	tmp_a = list_a;
	tmp_b = list_b;
	if (ft_lstsize(list_a) != ft_lstsize(list_b))
		return (0);
	while (tmp_a && tmp_b)
	{
		if (*((int *)tmp_a->content) != *((int *)tmp_b->content))
			return (0);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	return (1);
}

void	do_best_move2(t_list **stack_a, t_list **stack_b)
{
	t_list	*stack_a_node;
	t_list	*stack_b_node;
	t_list	*target;
	t_list	*smallest;
	t_moves	best_moves;
	t_moves	curr_moves;
	int		size_a;
	int		size_b;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	stack_b_node = *stack_b;
	best_moves.ra = 999999;
	best_moves.rb = 999999;
	best_moves.rra = 999999;
	best_moves.rrb = 999999;
	while (stack_b_node)
	{
		curr_moves.rrb = ft_lstsize(stack_b_node);
		curr_moves.rb = size_b - curr_moves.rrb;
		stack_a_node = *stack_a;
		target = NULL;
		smallest = stack_a_node;
		while (stack_a_node)
		{
			// smallest bigger than b
			if (*((int *)stack_b_node->content) <= *((int *)stack_a_node->content))
			{
				if (!target || *((int *)stack_a_node->content) <= *((int *)target->content))
					target = stack_a_node;
			}
			if (*((int *)stack_a_node->content) <= *((int *)smallest->content))
				smallest = stack_a_node;
			stack_a_node = stack_a_node->next;
		}
		if (!target)
			target = smallest;	
		curr_moves.rra = ft_lstsize(target);
		curr_moves.ra =  size_a - curr_moves.rra;
		best_moves = better_move(best_moves, curr_moves);
		stack_b_node = stack_b_node->next;
	}
	do_smart_moves(stack_a, stack_b, best_moves);
}

void	do_best_move(t_list **stack_a, t_list **stack_b, t_list *lis)
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
	best_moves.ra = 999999;
	best_moves.rb = 999999;
	best_moves.rra = 999999;
	best_moves.rrb = 999999;
	while (stack_a_node)
	{
		if (same_list(stack_a_node, lis))
			break ;
		if (!in_list(lis, *((int *)stack_a_node->content)))
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
					if (*((int *)stack_a_node->content) >= *((int *)stack_b_node->content))
					{
						if (!target || *((int *)stack_b_node->content) >= *((int *)target->content))
							target = stack_b_node;
					}
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
			best_moves = better_move(best_moves, curr_moves);
		}
		stack_a_node = stack_a_node->next;
	}
	do_smart_moves(stack_a, stack_b, best_moves);
}

void	sort_stack(t_list *stack_a)
{
	t_list	*stack_b;
	t_list	*node;
	t_list	*min_val;
	t_list	*lis;
	t_list	*lis_big;
	t_list	*lis2;
	t_list	*lis2_big;

	stack_b = NULL;
	lis = NULL;
	lis2 = NULL;
	min_val = NULL;
	node = stack_a;
	while (node)
	{
		if (!lis)
		{
			ft_lstadd_back(&lis, ft_lstnew(node->content));
			lis_big = node;
		}
		else if (*((int *)node->content) > *((int *)lis_big->content))
		{
			ft_lstadd_back(&lis, ft_lstnew(node->content));
			lis_big = node;
		}
		else
		{
			if (!lis2)
			{
				lis2 = lis;
				lis2_big = lis_big;
			}
			else
			{
				if (ft_lstsize(lis) > ft_lstsize(lis2))
				{
					ft_lstclear(&lis2, NULL);
					lis2 = lis;
					lis2_big = lis_big;
				}
				else
				{
					ft_lstclear(&lis, NULL);
				}
			}
			lis = NULL;
			ft_lstadd_back(&lis, ft_lstnew(node->content));
		}
		node = node->next;
	}
	if (ft_lstsize(stack_a) > ft_lstsize(lis2))
	{
	//	while (stack_a)
	//	{
	//		if (same_list(stack_a, lis2))
	//			break ;
	//		do_best_move(&stack_a, &stack_b, lis2);
	//		do_op(&stack_a, &stack_b, PUSH_B);
	//	}
		if (ft_lstsize(lis2_big) > ft_lstsize(stack_a) / 2)
		{
			while (ft_lstsize(lis2_big) != 1)
				do_op(&stack_a, &stack_b, ROTATE_A);
		}
		else
		{
			while (ft_lstsize(lis2_big) != 1)
				do_op(&stack_a, &stack_b, REVERSE_ROTATE_A);
		}
		while (*((int *)stack_a->content) != *((int *)lis2->content))
			do_op(&stack_a, &stack_b, PUSH_B);
		while (stack_b)
		{
			do_best_move2(&stack_a, &stack_b);
			do_op(&stack_a, &stack_b, PUSH_A);
		}
	}
	node = stack_a;
	while (node)
	{
		if (!min_val
			|| (*((int *)node->content) < *((int *)min_val->content)))
			min_val = node;
		node = node->next;
	}
	if (ft_lstsize(min_val) > ft_lstsize(stack_a) / 2)
	{
		while (stack_a != min_val)
			do_op(&stack_a, &stack_b, ROTATE_A);
	}
	else
	{
		while (stack_a != min_val)
			do_op(&stack_a, &stack_b, REVERSE_ROTATE_A);
	}
}
