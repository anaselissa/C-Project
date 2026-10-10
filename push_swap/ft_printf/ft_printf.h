/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabtah <aabtah@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:52:03 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/03 16:00:32 by aabtah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printchar(char c);
int		ft_printunsigned(unsigned int n);
int		ft_printhex(unsigned int n, char format);
int		ft_printptr(unsigned long ptr);
int		ft_putfloat(double n, int precision);

#endif
