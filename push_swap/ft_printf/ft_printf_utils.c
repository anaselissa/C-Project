/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabtah <aabtah@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:10:36 by aabtah            #+#    #+#             */
/*   Updated: 2025/12/21 10:44:16 by aabtah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(2, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!str)
	{
		write(2, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		len += ft_printchar(str[i]);
		i++;
	}
	return (len);
}
