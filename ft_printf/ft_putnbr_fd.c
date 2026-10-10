/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:51:44 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/14 16:57:43 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	int		count;
	char	c;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		count += ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}
