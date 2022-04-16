/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:56:26 by seb               #+#    #+#             */
/*   Updated: 2022/04/16 09:57:16 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	median(int array[], int size)
{
	int	median;

	if (size % 2 == 0)
		median = (array[(size - 1) / 2] + array[size / 2]) / 2;
	else
		median = array[size / 2];
	return (median);
}
