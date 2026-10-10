/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:05:50 by aabtah            #+#    #+#             */
/*   Updated: 2026/03/03 15:16:27 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_cost
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	bench_mode;
}	t_cost;

int		skip(char **argv);
char	*name_alg(int num, float disorder);
int		test_flage(char *nptr);
int		is_bunch_or_flage(char *first_arg);
int		is_flage(char *second_arg);
void	set_alg(int num, t_stack **stack_a, t_stack **stack_b);
void	free_error_stack_a(t_stack *stack_a);
void	ft_exit_isdigit(int c);
int		ft_pws_atoi(const char *nptr);
t_stack	*ft_add_front_stack(t_stack *head, int number);
char	**ft_reverse_split(char *str, int i, int k, int j);
void	free_error_node_str(t_stack *stack_a, char **str);
void	ft_free_str(char **str);
int		is_repeate(t_stack *stack_a, int number);
int		is_error(int num);
void	selection_main(t_stack **stack_a, t_stack **stack_b, int volum_size);
void	free_all(t_stack *stack_a, t_stack *stack_b, char **str);
size_t	ft_strlen(const char *s);
int		ft_pws_strncmp(const char *s1, const char *s2);
void	sort_tow(t_stack **stack_a);
int		max_index(t_stack *stack_a);
int		size_place(t_stack *stack_a);
void	complex_algorithm(t_stack **stack_a, t_stack **stack_b);
void	main_mediam(t_stack **stack_a, t_stack **stack_b, int min, int vs);
void	free_node(t_stack *head);
float	compute_disorder(t_stack *stack_a);
int		volume_size(t_stack **stack);
int		search(t_stack *stack, int idx);
void	move(t_stack **stack_a, t_stack **stack_b, int idx);
t_cost	*get_stats(void);
void	reset_stats(void);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	set_index(t_stack *stack_a);
void	sort_three(t_stack **stack_a);
void	bench(float disorder, char *algorithem);
void	adaptive_sort(t_stack **stack_a, t_stack **stack_b);
void	check_sorted_and_exit(t_stack *stack_a, int dis, char *argv);
void	free_node_str(t_stack *stack_a, char **str);

#endif