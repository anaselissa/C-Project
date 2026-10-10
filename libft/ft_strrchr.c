/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:09:34 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/09 13:34:01 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}

/*
#include <stdio.h>

int main()
{
	const char *s = "asdfgh";
	int c = 103;

	printf("Target address: %p \n", &s[4]);
	printf("ft_strrchr result: %p \n", ft_strrchr(s, c));
	return (0);
}
*/
