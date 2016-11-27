/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_add_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:38:42 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 11:58:43 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_llist_add_last(t_llist *list, const void *val, size_t val_size)
{
	t_llnode	*node;

	if (list == NULL || val == NULL || val_size == 0)
		return ;
	node = ft_llist_create_node(val, val_size);
	if (list->size > 0)
		list->last->next = node;
	else
		list->first = node;
	list->last = node;
	list->size++;
}
