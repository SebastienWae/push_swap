/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:12:29 by seb               #+#    #+#             */
/*   Updated: 2022/04/12 18:26:20 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <push_swap.h>
#include <unistd.h>

void	exit_error(t_stacks *s)
{
	if (s)
		free_stacks(s);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	exit_success(t_stacks *s)
{
	if (s)
		free_stacks(s);
	exit(EXIT_SUCCESS);
}
