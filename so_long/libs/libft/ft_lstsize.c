/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/28 18:24:38 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst->content || !lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i + 1);
}
