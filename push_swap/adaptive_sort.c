/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:01:39 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/23 12:34:01 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_stack **stack_a, t_stack **stack_b)
{
	float	disorder;
	int		vs;

	if (!stack_a || !*stack_a)
		return ;
	vs = volume_size(stack_a);
	disorder = compute_disorder(*stack_a);
	if (disorder < 0.2)
		selection_main(stack_a, stack_b, vs);
	else if (disorder >= 0.2 && disorder <= 0.5)
		main_mediam(stack_a, stack_b, 0, vs);
	else
		complex_algorithm(stack_a, stack_b);
}
