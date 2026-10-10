/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_libft.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:08:58 by aaleassa          #+#    #+#             */
/*   Updated: 2026/02/23 14:23:45 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_pws_strncmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (1);
}

int	skip(char **argv)
{
	int	skipp;

	skipp = 0;
	if (argv[1])
		skipp += is_bunch_or_flage(argv[1]);
	if (argv[2])
		skipp += is_bunch_or_flage(argv[2]);
	return (skipp);
}

char	*name_alg(int num, float disorder)
{
	char	*name;

	if (num == 1)
		name = "Simple / O(n^2)";
	else if (num == 2)
		name = "Medium / O(n√n)";
	else if (num == 3)
		name = "Complex / O(n log n) ";
	else
	{
		if (disorder < 0.2)
			name = "Adaptive / O(n^2)";
		else if (disorder >= 0.2 && disorder < 0.5)
			name = "Adaptive / O(n√n)";
		else
			name = "Adaptive / O(n log n)";
	}
	return (name);
}
