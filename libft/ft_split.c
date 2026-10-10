/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:51:01 by aaleassa          #+#    #+#             */
/*   Updated: 2025/12/16 18:11:42 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	num_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*word_cpy(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ffree(char **ret, int j)
{
	while (j > 0)
	{
		j--;
		free(ret[j]);
	}
	free(ret);
	return (NULL);
}

static char	**fill(char **ret, char const *s, char c)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			ret[j] = word_cpy(&s[i], c);
			if (!ret[j])
				return (ffree(ret, j));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	ret[j] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (num_word(s, c) + 1));
	if (!ret)
		return (NULL);
	return (fill(ret, s, c));
}
