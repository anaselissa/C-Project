/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 17:10:16 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/30 14:33:58 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putcaphex(unsigned int num);
int	ft_putchar_fd(char c, int fd);
int	ft_puthex(unsigned int num);
int	ft_putnbr_fd(int n, int fd);
int	ft_putptr(void *p);
int	ft_putstr_fd(char *s, int fd);
int	ft_putunnum(unsigned int n);

#endif
