/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithem.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:22:52 by aaleassa          #+#    #+#             */
/*   Updated: 2026/02/17 18:03:53 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_medium(t_stack **stack_a, t_stack **stack_b, int idx)
{
	int	x;
	int	size;

	x = search(*stack_b, idx);
	size = volume_size(stack_b);
	if (x <= (size / 2))
	{
		x = search(*stack_b, idx);
		while (x > 0)
		{
			rb(stack_b);
			x--;
		}
	}
	else
	{
		while (x < size)
		{
			rrb(stack_b);
			x++;
		}
	}
	pa(stack_a, stack_b);
}

void	re_push(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	volum_size;

	volum_size = volume_size(stack_b);
	i = volum_size - 1;
	while (i >= 0)
	{
		move_medium(stack_a, stack_b, i);
		i--;
	}
}

int	chunke_f(int vs)
{
	int	chunke;

	chunke = 0;
	while ((chunke * chunke) <= vs)
		chunke++;
	return (chunke - 1);
}

void	main_mediam(t_stack **stack_a, t_stack **stack_b, int min, int vs)
{
	int	max;
	int	x;
	int	chunke;

	chunke = chunke_f(vs);
	max = chunke;
	while (*stack_a)
	{
		x = vs;
		x -= min;
		while (x)
		{
			if ((*stack_a)->index >= min && (*stack_a)->index < max)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			x--;
		}
		max += chunke;
		min += chunke;
	}
	re_push(stack_a, stack_b);
}
