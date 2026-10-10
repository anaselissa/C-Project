/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:25:28 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/25 13:15:45 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunnum(unsigned int n)
{
	char	r;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putunnum(n / 10);
	r = (n % 10) + '0';
	count += write(1, &r, 1);
	return (count);
}
