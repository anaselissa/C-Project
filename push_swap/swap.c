/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:52:51 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/15 20:59:18 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*x;
	t_stack	*y;

	if (!*stack || !(*stack)->next)
		return ;
	x = *stack;
	y = x->next;
	x->next = y->next;
	if (y->next)
		y->next->prev = x;
	y->prev = NULL;
	x->prev = y;
	y->next = x;
	*stack = y;
}

void	sa(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
	write(1, "sa\n", 3);
	get_stats()->sa++;
	get_stats()->total++;
}

void	sb(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
	write(1, "sb\n", 3);
	get_stats()->sb++;
	get_stats()->total++;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	get_stats()->ss++;
	get_stats()->total++;
}
