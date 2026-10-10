/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabtah <aabtah@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:34:07 by aabtah            #+#    #+#             */
/*   Updated: 2025/12/21 12:10:52 by aabtah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned int n, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		len += ft_printhex(n / 16, format);
		len += ft_printchar(base[n % 16]);
	}
	else
	{
		len += ft_printchar(base[n]);
	}
	return (len);
}

int	ft_putptr(unsigned long n)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789abcdef";
	if (n >= 16)
	{
		len += ft_putptr(n / 16);
		len += ft_putptr(n % 16);
	}
	else
	{
		len += ft_printchar(base[n]);
	}
	return (len);
}

int	ft_printptr(unsigned long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		return (write(2, "(nil)", 5));
	}
	len += write(2, "0x", 2);
	len += ft_putptr(ptr);
	return (len);
}
