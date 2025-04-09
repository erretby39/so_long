/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:50:19 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/09 16:06:42 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *line, int fd)
{
	char	*buff;
	ssize_t	er;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	er = 1;
	while (er > 0)
	{
		er = read(fd, buff, BUFFER_SIZE);
		if (er == -1)
			return (free(buff), free(line), NULL);
		buff[er] = '\0';
		line = ft_strjoin(line, buff);
		if (ft_strchr(line, '\n'))
			break ;
	}
	if (er == 0 && (!line || !*line))
	{
		free(buff);
		return (free(line), line = NULL);
	}
	free(buff);
	return (line);
}

char	*lineuntilnl(char *str)
{
	size_t	i;
	size_t	j;
	char	*ls;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ls = malloc(sizeof(char) * (i + 1));
	if (!ls)
		return (NULL);
	while (j < i)
	{
		ls[j] = str[j];
		j++;
	}
	ls[j] = '\0';
	return (ls);
}

char	*chyata(char *str)
{
	char	*p;
	char	*line;

	if (!str)
		return (NULL);
	p = ft_strchr(str, '\n');
	if (!p)
		return (free(str), (NULL));
	line = ft_strdup(p + 1);
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char		*res;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(line), NULL);
	if (!line)
		line = ft_strdup("");
	if (!ft_strchr(line, '\n'))
		line = read_line(line, fd);
	if (!line)
		return (free(line), NULL);
	res = lineuntilnl(line);
	line = chyata(line);
	return (free(line), res);
}
