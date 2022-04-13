/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:00:04 by seb               #+#    #+#             */
/*   Updated: 2022/04/13 13:23:13 by swaegene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

enum e_dir	get_best_direction(t_moves moves)
{
	int	ra_rb;
	int	ra_rrb;
	int	rra_rrb;
	int	rra_rb;

	ra_rb = max(moves.ra, moves.rb);
	ra_rrb = moves.ra + moves.rrb;
	rra_rrb = max(moves.rra, moves.rrb);
	rra_rb = moves.rra + moves.rb;
	if (ra_rb <= ra_rrb && ra_rb <= rra_rrb && ra_rb <= rra_rb)
		return (RA_RB);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rrb && ra_rrb <= rra_rb)
		return (RA_RRB);
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
		return (RRA_RRB);
	else
		return (RRA_RB);
}
