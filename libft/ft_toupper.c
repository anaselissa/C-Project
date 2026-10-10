/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:28:00 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/09 12:28:25 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*
#include <unistd.h>
#include <stdio.h>

int main()
{
	int c;

	c = ft_toupper('r');
	write(1, &c, 1);
	c = ft_toupper('A');
	write(1, &c, 1);
	c = ft_toupper('5');
	write(1, &c, 1);
	return (0);
}
*/
