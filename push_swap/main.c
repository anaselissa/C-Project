/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:41:14 by aaleassa          #+#    #+#             */
/*   Updated: 2026/03/03 15:17:10 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_flags(char **argv, int *algo, int *is_bench)
{
	int	i;
	int	flag;

	*is_bench = 0;
	*algo = 4;
	i = 0;
	while (++i <= 2 && argv[i])
	{
		flag = test_flage(argv[i]);
		if (!ft_pws_strncmp("--bench", argv[i]))
			*is_bench = 1;
		else if (flag != 0 && flag != 5)
			*algo = flag;
		else
			break ;
	}
}

void	sort_dispatcher(char **argv, t_stack **s_a, t_stack **s_b, float dis)
{
	int	algo;
	int	is_bench;

	parse_flags(argv, &algo, &is_bench);
	if (algo == 4 && volume_size(s_a) <= 5)
	{
		selection_main(s_a, s_b, volume_size(s_a));
		if (is_bench)
			bench(dis, "Adaptive / O(n^2)");
		return ;
	}
	set_alg(algo, s_a, s_b);
	if (is_bench)
		bench(dis, name_alg(algo, dis));
}

t_stack	*pars_argc2(t_stack *stack_a, char **str)
{
	int	i;
	int	number;

	i = 0;
	while (str[i])
	{
		number = ft_pws_atoi(str[i]);
		if (is_error(2) || is_repeate(stack_a, number))
		{
			free_error_node_str(stack_a, str);
			return (NULL);
		}
		stack_a = ft_add_front_stack(stack_a, number);
		i++;
	}
	return (stack_a);
}

t_stack	*pars_argc(int argc, char **argv, int skipp)
{
	char	**str;
	t_stack	*stack_a;

	stack_a = NULL;
	while (argc > 1 + skipp)
	{
		str = ft_reverse_split(argv[argc - 1], 0, 0, 0);
		if (!str)
		{
			free_node(stack_a);
			return (NULL);
		}
		stack_a = pars_argc2(stack_a, str);
		if (!stack_a)
			return (NULL);
		ft_free_str(str);
		argc--;
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = pars_argc(argc, argv, skip(argv));
	if (!stack_a)
		return (0);
	set_index(stack_a);
	check_sorted_and_exit(stack_a, compute_disorder(stack_a), argv[1]);
	sort_dispatcher(argv, &stack_a, &stack_b, compute_disorder(stack_a));
	free_node(stack_a);
	free_node(stack_b);
	return (0);
}
