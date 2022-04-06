/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:39:29 by swaegene          #+#    #+#             */
/*   Updated: 2022/04/06 17:38:17 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <libft.h>
#include <ft_printf.h>
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
		if (!values)
			error();
		stack = create_stack(values, argc);
		if (!stack)
			error(); //TODO: free
		sort_stack(stack, instructions);
		if (!instructions)
			error(); //TODO: free
		else
			print_list("%s\n", instructions); //TODO free
		return (0);
	}
	return (1);
}
