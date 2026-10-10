/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleassa <aaleassa@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 17:50:38 by aaleassa          #+#    #+#             */
/*   Updated: 2026/01/01 17:51:36 by aaleassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*rres(char *temp, char *store, int j, int tl)
{
	int	i;

	i = 0;
	while (j != tl)
		temp[i++] = store[j++];
	temp[i] = '\0';
	free(store);
	return (temp);
}

static char	*freade(int fd, char *buf, char *store)
{
	ssize_t	r;

	r = 1;
	while (!ft_strchr(store, '\n') && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[r] = '\0';
		store = ft_gnl_strjoin(store, buf);
	}
	free(buf);
	return (store);
}

static char	*li(char *store)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (store[j] && store[j] != '\n')
		j++;
	if (store[j])
		j++;
	line = malloc(j + 1);
	if (!line)
		return (NULL);
	while (i < j)
	{
		line[i] = store[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*res(char *store)
{
	int		tl;
	int		j;
	char	*temp;

	tl = ft_strlen(store);
	j = 0;
	while (store[j] && store[j] != '\n')
		j++;
	if (store[j])
		j++;
	if (!store[j])
	{
		free(store);
		return (NULL);
	}
	temp = malloc(tl - j + 1);
	if (!temp)
	{
		free(store);
		return (NULL);
	}
	return (rres(temp, store, j, tl));
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*store;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	store = freade(fd, buf, store);
	if (!store)
		return (NULL);
	if (store[0] == '\0')
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	line = NULL;
	line = li(store);
	store = res(store);
	return (line);
}
