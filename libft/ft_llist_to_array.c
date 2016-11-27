/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_to_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:46:51 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:19:37 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	**ft_llist_to_array(t_llist *list)
{
	void		**array;
	size_t		i;
	t_llnode	*cur;

	array = (void **)malloc(sizeof(void *) * list->size);
	if (array == NULL)
		return (NULL);
	i = 0;
	cur = list->first;
	while (i < list->size)
	{
		array[i] = (void *)malloc(cur->val_size);
		if (array[i] == NULL)
			return (NULL);
		ft_memcpy(array[i], cur->val, cur->val_size);
		i++;
		cur = cur->next;
	}
	return (array);
}
