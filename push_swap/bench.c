/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 17:02:35 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/23 12:44:21 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	*get_stats(void)
{
	static t_cost	count;

	return (&count);
}

void	reset_stats(void)
{
	t_cost	*count;

	count = get_stats();
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->total = 0;
}

void	bench(float disorder, char *algorithm)
{
	t_cost		*stats;
	float		x;

	stats = get_stats();
	x = (float)(disorder * 100);
	ft_printf("[bench] disorder: %f%%\n", x);
	ft_printf("[bench] strategy: %s\n", algorithm);
	ft_printf("[bench] total_ops: %i\n", stats->total);
	ft_printf("[bench] sa:  %d  sb:  %d  ss:  %d ",
		stats->sa, stats->sb, stats->ss);
	ft_printf("pa:  %d  pb:  %d\n", stats->pa, stats->pb);
	ft_printf("[bench] ra:  %d  rb:  %d  rr:  %d ",
		stats->ra, stats->rb, stats->rr);
	ft_printf("rra: %d  rrb: %d  rrr: %d\n",
		stats->rra, stats->rrb, stats->rrr);
}
