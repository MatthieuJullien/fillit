/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_add_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:37:46 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 12:27:47 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_llist_add_at(t_llist *list, void *val, size_t val_size,
		unsigned int index)
{
	t_llnode	*new;
	t_llnode	*prv;
	t_llnode	*cur;

	if (list == NULL || index >= list->size)
		return (0);
	if (!(new = ft_llist_create_node(val, val_size)))
		return (0);
	prv = NULL;
	cur = list->first;
	while (index > 0 && cur != NULL)
	{
		prv = cur;
		cur = cur->next;
		index--;
	}
	if (cur == NULL)
		list->last = new;
	if (prv == NULL)
		list->first = new;
	else
		prv->next = new;
	new->next = cur;
	list->size++;
	return (1);
}
