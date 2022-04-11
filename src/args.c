/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:07:11 by seb               #+#    #+#             */
/*   Updated: 2022/04/09 13:10:25 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

static int	safe_int_add(unsigned int nb, int add, int sign)
{
	if ((nb + add > 2147483647 && sign == 1)
		|| (nb + add > 2147483648 && sign == -1))
		error();
	return (nb + add);
}

static int	parse_arg(char *arg)
{
	int				i;
	long int		nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (arg[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			nb = safe_int_add(nb * 10, arg[i] - '0', sign);
		else
			error();
		i++;
	}
	return (nb * sign);
}


static void	check_dup(int *values, int size, int nb)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (values[i] == nb)
			error();
		i++;
	}
}

int	*parse_args(char **values, int size)
{
	int		i;
	int		value;
	int		*args;

	i = 0;
	args = malloc(sizeof(int) * size);
	if (!args)
		error();
	while (i < size)
	{
		value = parse_arg(values[i]);
		if (i > 0)
			check_dup(args, i, value);
		args[i] = value;
		i++;
	}
	return (args);
}
