/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:38:32 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/09 17:45:38 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	c2;
	size_t			i;

	i = 0;
	c2 = (unsigned char)c;
	s2 = (unsigned char *)s;
	while (i < n)
	{
		if (s2[i] == c2)
			return ((void *)&s2[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
    char src[50] = "This is a test string.";
    printf("%p", ft_memchr(src, 97 , 10));
  printf("%p",&src[8]);
    return (0);
}*/
