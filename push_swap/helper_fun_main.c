/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:30:02 by aaleassa          #+#    #+#             */
/*   Updated: 2026/02/23 13:13:59 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	test_flage(char *nptr)
{
	int	return_num;

	return_num = 0;
	if (!ft_pws_strncmp("--simple", nptr))
		return_num = 1;
	else if (!ft_pws_strncmp("--medium", nptr))
		return_num = 2;
	else if (!ft_pws_strncmp("--complex", nptr))
		return_num = 3;
	else if (!ft_pws_strncmp("--adaptive", nptr))
		return_num = 4;
	return (return_num);
}

int	is_flage(char *second_arg)
{
	int	is_flg;

	is_flg = 0;
	if (test_flage(second_arg))
		is_flg = 1;
	return (is_flg);
}

int	is_bunch_or_flage(char *first_arg)
{
	int	is_bun;

	is_bun = 0;
	if (!ft_pws_strncmp("--bench", first_arg))
		is_bun = 1;
	else
		is_bun = is_flage(first_arg);
	return (is_bun);
}

int	is_error(int num)
{
	static int	staticnum = 0;

	if (!(num == 2))
		staticnum = num;
	return (staticnum);
}

void	set_alg(int num, t_stack **stack_a, t_stack **stack_b)
{
	if (num == 1)
		selection_main(stack_a, stack_b, volume_size(stack_a));
	else if (num == 2)
		main_mediam(stack_a, stack_b, 0, volume_size(stack_a));
	else if (num == 3)
		complex_algorithm(stack_a, stack_b);
	else if (num == 4)
		adaptive_sort(stack_a, stack_b);
}
