/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:37:48 by aaleassa          #+#    #+#             */
/*   Updated: 2026/02/23 13:10:18 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_add_front_stack(t_stack *head, int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->index = 0;
	new->value = number;
	new->prev = NULL;
	new->next = head;
	if (head)
		head->prev = new;
	head = new;
	return (head);
}

int	is_repeate(t_stack *stack_a, int number)
{
	while (stack_a)
	{
		if (number == stack_a->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	ft_exit_isdigit(int c)
{
	if (c < '0' || c > '9')
		is_error(1);
}

int	ft_atoi2(char *nptr, int i, int sign)
{
	long	result;

	result = 0;
	while (nptr[i])
	{
		ft_exit_isdigit(nptr[i]);
		result = (result * 10) + (nptr[i] - '0');
		if ((result > 2147483647 && sign == 1)
			|| (result > 2147483648 && sign == -1))
		{
			is_error(1);
		}
		i++;
	}
	return (result);
}

int	ft_pws_atoi(const char *nptr)
{
	int		sign;
	size_t	i;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
		if (nptr[i] == '\0')
			is_error(1);
	}
	return (ft_atoi2((char *)nptr, i, sign) * sign);
}
