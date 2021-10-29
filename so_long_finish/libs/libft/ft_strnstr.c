/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/28 18:24:19 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

static int	is_same(const char *str, const char *to_find, size_t len)
{
	while (*str && *to_find && len && *str == *to_find)
	{
		str++;
		to_find++;
		len--;
	}
	if (!*to_find)
		return (1);
	if (*to_find && (!*str || !len))
		return (0);
	return (0);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	if (!*to_find)
		return ((char *)str);
	while (*str && len)
	{
		if (*str == *to_find)
		{
			if (is_same(str + 1, to_find + 1, len - 1))
				return ((char *)str);
		}
		str++;
		len--;
	}
	return ((char *)0);
}
