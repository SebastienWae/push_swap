/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/12 20:38:05 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	t_list		*ops;

	if (argc-- > 1)
	{
		stacks.a = malloc(sizeof(t_list *));
		*(stacks.a) = NULL;
		stacks.b = NULL;
		parse_args(&argv[1], argc, &stacks);
		ops = sort_stacks(&stacks);
		flush_ops(ops);
		exit_success(&stacks);
	}
	exit_error(NULL);
}
