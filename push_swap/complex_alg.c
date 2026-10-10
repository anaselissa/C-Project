/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 11:33:10 by aaleassa          #+#    #+#             */
/*   Updated: 2026/02/23 12:46:34 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index(t_stack *stack_a)
{
	int	max;

	if (!stack_a)
		return (0);
	max = stack_a->index;
	while (stack_a)
	{
		if (max < stack_a->index)
			max = stack_a->index;
		stack_a = stack_a->next;
	}
	return (max);
}

int	size_place(t_stack *stack_a)
{
	int	i;
	int	max;

	max = max_index(stack_a);
	if (max == 0)
		return (1);
	i = 0;
	while (max != 0)
	{
		max /= 2;
		i++;
	}
	return (i);
}

void	complex_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	vs;

	i = 0;
	size = size_place(*stack_a);
	while (size != 0)
	{
		vs = volume_size(stack_a);
		while (vs != 0)
		{
			if ((*stack_a)->index >> i & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			vs--;
		}
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
		size--;
	}
}
