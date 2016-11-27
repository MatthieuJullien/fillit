/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_to_llist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:37:18 by majullie          #+#    #+#             */
/*   Updated: 2016/11/26 08:35:15 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_llist	*ft_array_to_llist(void *array, size_t size, size_t val_size)
{
	t_llist		*list;
	size_t		i;

	if (!array || val_size == 0)
		return (NULL);
	ft_llist_create(&list);
	if (list == NULL)
		return (NULL);
	i = 0;
	while (size > 0)
	{
		ft_llist_add_last(list, (char*)array + i, val_size);
		i += val_size;
		size--;
	}
	return (list);
}
