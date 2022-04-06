/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:21:11 by seb               #+#    #+#             */
/*   Updated: 2022/04/06 17:29:26 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	print_list(char *format, t_list *head)
{
	while (head)
	{
		ft_printf(format, *((int *)head->content));
		head = head->next;
	}
}
