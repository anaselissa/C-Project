/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabtah <aabtah@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:24:49 by aabtah            #+#    #+#             */
/*   Updated: 2025/12/21 12:10:10 by aabtah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	long	nb;
	int		len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		len += ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += ft_printnbr(nb / 10);
		len += ft_printchar((nb % 10) + '0');
	}
	else
		len += ft_printchar(nb + '0');
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_printunsigned(n / 10);
		len += ft_printunsigned(n % 10);
	}
	else
	{
		len += ft_printchar(n + '0');
	}
	return (len);
}
