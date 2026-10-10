/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 11:04:47 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/25 12:45:03 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **from_stack, t_stack **to_stack)
{
	t_stack	*x;

	if (!from_stack || !*from_stack)
		return ;
	x = *from_stack;
	*from_stack = x->next;
	if (*from_stack)
		(*from_stack)->prev = NULL;
	x->next = *to_stack;
	if (*to_stack)
		(*to_stack)->prev = x;
	*to_stack = x;
	x->prev = NULL;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
	get_stats()->pa++;
	get_stats()->total++;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
	get_stats()->pb++;
	get_stats()->total++;
}
