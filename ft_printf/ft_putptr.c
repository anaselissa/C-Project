/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:08:37 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/30 15:00:25 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(unsigned long num)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (num >= 16)
		count += ft_print((num / 16));
	count += write(1, &hex[num % 16], 1);
	return (count);
}

int	ft_putptr(void *p)
{
	unsigned long	num;
	int				count;

	num = (unsigned long )p;
	count = 0;
	if (!p)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_print(num);
	return (count);
}
/*
#include <stdio.h> 
int main ()
{
    int s=4;
    void *d = NULL;
    int *p = &s;
    printf("        %d             \n",ft_putptr(p));
    printf("%d",ft_putptr(d));


}*/
