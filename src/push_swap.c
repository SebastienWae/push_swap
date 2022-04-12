/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/12 20:50:51 by seb              ###   ########.fr       */
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
		stacks = init_stacks();
		parse_args(&argv[1], argc, &stacks);
		ops = sort_stacks(&stacks);
		flush_ops(ops);
		exit_success(&stacks);
	}
	exit_error(NULL);
}
