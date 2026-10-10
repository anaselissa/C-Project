/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:55:56 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/30 15:13:07 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	form(va_list ap, const char *s)
{
	int	count;

	count = 0;
	if (*s == 'c')
		count += ft_putchar_fd(va_arg(ap, int), 1);
	else if (*s == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*s == 'd' || *s == 'i')
		count += ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*s == 'u')
		count += ft_putunnum(va_arg(ap, unsigned int));
	else if (*s == '%')
		count += write(1, s, 1);
	else if (*s == 'x')
		count += ft_puthex(va_arg(ap, unsigned int));
	else if (*s == 'X')
		count += ft_putcaphex(va_arg(ap, unsigned int));
	else if (*s == 'p')
		count += ft_putptr(va_arg(ap, void *));
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			count += form(ap, &s[i]);
		}
		else
			count += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
/*
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret_ft = ft_printf("Mine: %s | %d | %x\n", "Hello", 123, 255);
    int ret_or = printf("Orig: %s | %d | %x\n", "Hello", 123, 255);

    printf("My Return: %d\n", ret_ft);
    printf("Or Return: %d\n", ret_or);
}*/
