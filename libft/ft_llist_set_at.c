/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_set_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:44:31 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:17:28 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_llist_set_at(t_llist *list, void *val, size_t val_size,
			unsigned int index)
{
	t_llnode	*cur;

	if (index >= list->size)
		return ;
	cur = list->first;
	while (index > 0)
	{
		cur = cur->next;
		index--;
	}
	if (cur->val)
		free(cur->val);
	cur->val = (void *)malloc(val_size);
	if (cur->val == NULL)
		return ;
	ft_memcpy(cur->val, val, val_size);
	cur->val_size = val_size;
}
