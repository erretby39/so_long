/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soer-ret <soer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:13:41 by soer-ret          #+#    #+#             */
/*   Updated: 2025/04/07 09:30:28 by soer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	sl;
	char	*substr;

	if (!s)
		return (0);
	sl = ft_strlen(s);
	if (start >= sl)
		len = 0;
	else if (start + len > sl)
	{
		len = sl - start;
	}
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

static int	counter(char const *s, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	else if (!(s[0] == c && s[1] != '\0'))
		k++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			k++;
		i++;
	}
	return (k);
}

static int	cow(char const *s, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static char	**split_free(char **str, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	st;
	size_t	k;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = counter(s, c);
	str = (char **)malloc(sizeof(char *) * (k + 1));
	if (!str)
		return (NULL);
	while (*s && i < k)
	{
		while (*s == c)
			s++;
		st = cow(s, c);
		str[i] = ft_substr(s, 0, st);
		if (str[i] == NULL)
			return (split_free(str, i));
		s += st;
		i++;
	}
	str[i] = NULL;
	return (str);
}
