/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/06 19:06:49 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <unistd.h>

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*instructions;
	int		*values;

	if (argc > 1)
	{
		argc--;
		instructions = NULL;
		values = parse_args(&argv[1], argc);
		stack = create_stack(values, argc);
		sort_stack(stack, instructions);
		print_list("%s\n", instructions);
		return (0);
	}
	return (1);
}
