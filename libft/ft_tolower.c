/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:28:53 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/09 12:29:38 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
#include <unistd.h>
#include <stdio.h>

int main()
{
	int c;

	c = ft_tolower('R');
	write(1, &c, 1);
	c = ft_tolower('a');
	write(1, &c, 1);
	c = ft_tolower('5');
	write(1, &c, 1);
	return (0);
}
*/
