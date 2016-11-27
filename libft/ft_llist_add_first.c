/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_add_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:38:21 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:11:39 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_llist_add_first(t_llist *list, const void *val, size_t val_size)
{
	t_llnode	*node;

	node = ft_llist_create_node(val, val_size);
	node->next = list->first;
	if (list->size == 0)
		list->last = node;
	list->first = node;
	list->size++;
}
