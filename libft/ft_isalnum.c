/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:48:04 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/06 14:06:32 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <stdio.h>
int main()
{
	printf("%d",ft_isalnum('9'));
        printf("%d",ft_isalnum('l'));
        printf("%d",ft_isalnum('A'));
        printf("%d",ft_isalnum(','));
        printf("%d",ft_isalnum(' '));
}*/
