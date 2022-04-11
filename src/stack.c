/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:26:58 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/09 18:27:34 by seb              ###   ########.fr       */
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

//TODO: remove
#include <math.h>
void	sort_stack(t_list *stack_a)
{
	t_list	*stack_b;
	t_list	*node; int		size;
	int		i;
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	int		c_ra;
	int		c_rb;
	int		c_rra;
	int		c_rrb;
	int     sm;
	t_list	*start;
	t_list	*end;
	t_list	*start2;
	t_list	*end2;
	
	stack_b = NULL;
	size = ft_lstsize(stack_a);
	i = 0;
	ra = 0;
	rb = size;
	rra = 0;
	rrb = size;
	node = stack_a;
	start = node;
	end = node;
	start2 = node;
	end2 = node;
	while (node)
	{
		if (*((int *)node->content) > *((int *)end->content))
			end = node;
		else
		{
			if (ft_lstsize(start) - ft_lstsize(end) > ft_lstsize(start2) - ft_lstsize(end2))
			{
				start2 = start;
				end2 = end;
			}
			start = node;
			end = node;	
		}
		node = node->next;
	}
	node = stack_a;
	while (node)
	{
		if (*((int *)node->content) > *((int *)end->content))
			end = node;
		else
		{
			if (ft_lstsize(start) - ft_lstsize(end) > ft_lstsize(start2) - ft_lstsize(end2))
			{
				start2 = start;
				end2 = end;
			}
			start = node;
			end = node;	
		}
		node = node->next;
	}
	while (*((int *)stack_a->content) != *((int *)start2->content))
		do_op(&stack_a, &stack_b, PUSH_B);
	i = ft_lstsize(start2) - ft_lstsize(end2);
	while (i)
	{
		do_op(&stack_a, &stack_b, ROTATE_A);
		i--;
	}
	while (*((int *)stack_a->content) != *((int *)start2->content))
		do_op(&stack_a, &stack_b, PUSH_B);
	while (stack_b)
	{
		node = stack_b;
		while (node)
		{
			get_r(stack_a, stack_b, node, &c_ra, &c_rb, &c_rra, &c_rrb);		
			if (min(max(ra, rb), max(rra, rrb)) >= min(max(c_ra, c_rb), max(c_rra, c_rrb)))
			{
				ra = c_ra;
				rb = c_rb;
				rra = c_rra;
				rrb = c_rrb;
			}
			node = node->next;
		}
		if (max(ra, rb) >= max(rra, rrb))
			smart_reverse_rotate(&stack_a, &stack_b, rra, rrb);
		else
			smart_rotate(&stack_a, &stack_b, ra, rb);
		do_op(&stack_a, &stack_b, PUSH_A);
		ra = 0;
		rb = size;
		rra = 0;
		rrb = size;
	}
	i = 0;
	sm = *((int *)stack_a->content);
	node = stack_a;
	while (node)
	{
		if (sm > *((int *)node->content))
			sm = *((int *)node->content);
		i++;
		node = node->next;
	}
	while (*((int *)stack_a->content) != sm)
		do_op(&stack_a, &stack_b, ROTATE_A);
}

/*

	while (stack_a)
	{
		node = stack_a; 
		smallest = node;
		while (node)
		{
			if (*((int *)node->content) < *((int *)smallest->content))
				smallest = node;
			node = node->next;
		}
		if (reverse(stack_a, smallest))
		{
			while (*((int *)stack_a->content) != *((int *)smallest->content))
				do_op(&stack_a, &stack_b, REVERSE_ROTATE_A);
		}
		else
		{
			while (*((int *)stack_a->content) != *((int *)smallest->content))
				do_op(&stack_a, &stack_b, ROTATE_A);
		}
		do_op(&stack_a, &stack_b, PUSH_B);
	}
	while (stack_b)
		do_op(&stack_a, &stack_b, PUSH_A);
		if ((*(int *)stack_b->content) > (*(int *)stack_a->content))
 Run a loop for 'n' times(n is size of array)
   having the following :
   2.a. Keep on pushing elements in the 2nd 
        stack till the top of second stack is 
        smaller than element being pushed from 
        1st stack.
   2.b. If the element being pushed is smaller 
        than top of 2nd stack  then swap them
        (as in bubble sort)
   *Do above steps alternatively



void sort(stack s) {
    if (!IsEmpty(s)) {
        int x = Pop(s);
        sort(s);
        insert(s, x);
    }
}

void insert(stack s, int x) {
    if (!IsEmpty(s)) {  
        int y = Top(s);
        if (x < y) {
            Pop(s);
            insert(s, x);
            Push(s, y);
        } else {
            Push(s, x);
        }
    } else {
        Push(s, x); 
    }
}
*/
