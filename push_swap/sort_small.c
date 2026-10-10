/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 21:27:46 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/14 22:18:06 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	volume_size(t_stack **stack)
{
	t_stack	*x;
	int		size;

	size = 0;
	x = *stack;
	while (x)
	{
		x = x->next;
		size++;
	}
	return (size);
}

int	search(t_stack *stack, int idx)
{
	int	x;

	x = 0;
	while (stack)
	{
		if (stack->index == idx)
			return (x);
		stack = stack->next;
		x++;
	}
	return (-1);
}

void	move(t_stack **stack_a, t_stack **stack_b, int idx)
{
	int	x;
	int	size;

	x = search(*stack_a, idx);
	size = volume_size(stack_a);
	if (x <= (size / 2))
	{
		while (x > 0)
		{
			ra(stack_a);
			x--;
		}
	}
	else
	{
		while (x < size)
		{
			rra(stack_a);
			x++;
		}
	}
	pb(stack_a, stack_b);
}
