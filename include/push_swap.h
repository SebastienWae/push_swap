/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:43 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/07 15:10:52 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

void	error(void);

t_list	*create_stack(int *values, int size);
void	sort_stack(t_list *stack, t_list *ops);

void	print_list(char *format, t_list *head);
void	free_list(t_list *head);

int		*parse_args(char **args, int size);

void	push(t_list **stack_dst, t_list **stack_src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);

#endif
