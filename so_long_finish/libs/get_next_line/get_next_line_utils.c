/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/28 21:25:38 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (!dest || !src)
		return (0);
	while (src[i] && i + 1 < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size)
		dest[i] = '\0';
	while (src[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	const char	ch = c;

	while (*s != ch)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*r;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	r = (char *)malloc(s1_len + s2_len + 1);
	if (!r)
		return ((char *)0);
	ft_strlcpy(r, s1, s1_len + 1);
	ft_strlcpy(r + s1_len, s2, s2_len + 1);
	*(r + s1_len + s2_len) = '\0';
	free((void *)s1);
	return (r);
}

char	*ft_strdup(char *src)
{
	char			*dup;
	char			*dup_start;
	unsigned int	len;

	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	dup_start = dup;
	while (*src)
	{
		*dup = *src;
		src++;
		dup++;
	}
	*dup = '\0';
	return (dup_start);
}
