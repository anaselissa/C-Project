/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 19:27:43 by aaleassa          #+#    #+#             */
/*   Updated: 2026/02/18 21:18:34 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_node(t_stack *head)
{
	t_stack	*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	free_error_node_str(t_stack *stack_a, char **str)
{
	ft_free_str(str);
	free_node(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_error_stack_a(t_stack *stack_a)
{
	free_node(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_all(t_stack *stack_a, t_stack *stack_b, char **str)
{
	ft_free_str(str);
	free_node(stack_a);
	free_node(stack_b);
}
