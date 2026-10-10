/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:24:32 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/17 14:25:33 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset( void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		ptr[n] = (unsigned char )c;
	}
	return (s);
}
/*
         size_t i = 0;
         while(i<n)
         {
                         ptr[i]= (unsigned char )c;
         i++;
         }
         
#include <stdio.h>
int main()
{

	char s[] = "anaseli";
	
	ft_memset(s,0,5);
	printf("%s",s);

}
*/
