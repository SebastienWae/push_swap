/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/07 17:03:20 by swaegene         ###   ########.fr       */
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
	t_list	*ops;
	int		*values;

	if (argc > 1)
	{
		argc--;
		ops = NULL;
		values = parse_args(&argv[1], argc);
		stack = create_stack(values, argc);
		sort_stack(stack, ops);
		print_list("%s\n", ops);
		return (0);
	}
	return (1);
}
