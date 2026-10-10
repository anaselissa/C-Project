/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:55:05 by aabtah            #+#    #+#             */
/*   Updated: 2026/02/25 12:22:21 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*free_split(char **res, int k)
{
	while (--k >= 0)
		free(res[k]);
	free(res);
	return (NULL);
}

int	len_word(char *str)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (str[i])
			len++;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
	}
	return (len);
}

static char	*ft_extract_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**revers_word(char **str)
{
	int		i;
	int		end;
	char	*temp;

	i = 0;
	end = 0;
	if (!str)
		return (NULL);
	while (str[end])
		end++;
	end--;
	while (i < end)
	{
		temp = str[i];
		str[i] = str[end];
		str[end] = temp;
		i++;
		end--;
	}
	return (str);
}

char	**ft_reverse_split(char *str, int i, int k, int j)
{
	char	**res;

	if (!str || len_word(str) == 0)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (len_word(str) + 1));
	if (!res)
		return (NULL);
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t')
			i++;
		if (i > j)
		{
			res[k] = ft_extract_word(str, j, i);
			if (!res[k])
				return (free_split(res, k));
			k++;
		}
	}
	res[k] = NULL;
	return (revers_word(res));
}
