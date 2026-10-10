/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 11:34:07 by aaleassa          #+#    #+#             */
/*   Updated: 2026/02/23 14:28:13 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tow(t_stack **stack_a)
{
	int	x;
	int	y;

	x = (*stack_a)->index;
	y = (*stack_a)->next->index;
	if (x > y)
		sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	int	x;
	int	y;
	int	v;

	x = (*stack_a)->index;
	y = (*stack_a)->next->index;
	v = (*stack_a)->next->next->index;
	if (x > y && y < v && x > v)
		ra(stack_a);
	else if (x > y && y < v && x < v)
		sa(stack_a);
	else if (x > y && y > v && x > v)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (x < y && y > v && x < v)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (x < y && y > v && x > v)
		rra(stack_a);
}

void	selection_main(t_stack **stack_a, t_stack **stack_b, int volum_size)
{
	int	i;

	i = 0;
	while (i < (volum_size - 3))
	{
		move(stack_a, stack_b, i);
		i++;
	}
	i = 0;
	if (volum_size == 2)
		sort_tow(stack_a);
	else
		sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
