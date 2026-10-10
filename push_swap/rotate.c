/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:37:28 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/03 19:54:07 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)

{
	t_stack	*first;
	t_stack	*list;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	list = *stack;
	while (list->next != NULL)
		list = list->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	list->next = first;
	first->prev = list;
	first->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	get_stats()->ra++;
	get_stats()->total++;
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	get_stats()->rb++;
	get_stats()->total++;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	get_stats()->rr++;
	get_stats()->total++;
}
