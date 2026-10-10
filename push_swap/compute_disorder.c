/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:52:29 by aabtah            #+#    #+#             */
/*   Updated: 2026/03/03 16:02:37 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack_a)
{
	t_stack	*i;
	t_stack	*j;
	int		total_pairs;
	int		mistakes;

	if (!stack_a || !stack_a->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->index > j->index)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((float)mistakes / (float)total_pairs);
}

void	check_sorted_and_exit(t_stack *stack_a, int dis, char *argv)
{
	t_stack	*curr;

	if (!stack_a || !stack_a->next)
		exit(0);
	curr = stack_a;
	while (curr->next)
	{
		if (curr->index > curr->next->index)
			return ;
		curr = curr->next;
	}
	if (argv && !ft_pws_strncmp("--bench", argv))
		bench(dis, "Adaptive");
	free_node(stack_a);
	exit(0);
}
