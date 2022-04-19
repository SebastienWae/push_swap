/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:07:11 by seb               #+#    #+#             */
/*   Updated: 2022/04/19 08:30:30 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdlib.h>

static t_arg	safe_add(t_arg n, int add, int sign)
{
	if ((n.value * 10 + add > INT_MAX && sign == 1)
		|| (n.value * 10 + add > INT_MIN * -1 && sign == -1))
		n.error = 1;
	else
	{
		n.value *= 10;
		n.value += add;
	}
	return (n);
}

static t_arg	parse_arg(char *arg)
{
	int			i;
	int			sign;
	t_arg		res;

	i = 0;
	sign = 1;
	if (arg[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (arg[i] == '+')
		i++;
	res.value = 0;
	res.error = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			res = safe_add(res, arg[i] - '0', sign);
		else
			res.error = 1;
		i++;
	}
	res.value *= sign;
	return (res);
}

static int	is_in_list(t_list **list, int value)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (*((int *)tmp->content) == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	parse_args(char **values, int size, t_stacks *stacks)
{
	t_list	*node;
	int		*content;
	t_arg	arg;

	while (size--)
	{
		arg = parse_arg(values[size]);
		if ((arg.error)
			|| (*(stacks->a) && is_in_list(stacks->a, arg.value)))
			return (0);
		content = malloc(sizeof(int));
		if (!content)
			return (0);
		*content = arg.value;
		node = ft_lstnew(content);
		ft_lstadd_front(stacks->a, node);
	}
	return (1);
}

void	split_parse_arg(char *arg, t_stacks *stacks)
{
	char	**values;
	int		size;
	int		i;
	int		err;

	err = 0;
	values = ft_split(arg, ' ');
	size = 0;
	while (values[size])
		size++;
	if (!parse_args(values, size, stacks))
		err = 1;
	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
	if (err)
		exit_error(stacks);
}
