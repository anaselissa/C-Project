/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:08:00 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/18 21:26:13 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*compare;
	int		i;

	if (!stack_a)
		return ;
	current = stack_a;
	while (current)
	{
		i = 0;
		compare = stack_a;
		while (compare)
		{
			if (compare->value < current->value)
				i++;
			compare = compare->next;
		}
		current->index = i;
		current = current->next;
	}
}
