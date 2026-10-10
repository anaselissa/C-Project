/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabtah <aabtah@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:55:27 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/03 15:56:32 by aabtah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putfloat(double n, int precision)
{
	int		count;
	long	int_part;
	int		digit;

	count = 0;
	if (n < 0)
	{
		count += ft_printchar('-');
		n = -n;
	}
	int_part = (long)n;
	count += ft_printnbr(int_part);
	if (precision > 0)
	{
		count += ft_printchar('.');
		n -= (double)int_part;
		while (precision--)
		{
			n *= 10;
			digit = (int)n;
			count += ft_printchar(digit + '0');
			n -= digit;
		}
	}
	return (count);
}
