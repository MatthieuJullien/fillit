/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_sorted_insert.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:45:46 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:18:46 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_sorted_insert(t_llist *list, void *val, size_t val_size,
			int (*cmp)())
{
	t_llnode	*new;
	t_llnode	*prv;
	t_llnode	*cur;

	if (!list || !cmp || !(new = ft_llist_create_node(val, val_size)))
		return ;
	list->size++;
	prv = NULL;
	cur = list->first;
	while (cur)
	{
		if (cmp(val, cur->val) <= 0)
		{
			if (prv == NULL)
				list->first = new;
			else
				prv->next = new;
			new->next = cur;
			return ;
		}
		prv = cur;
		cur = cur->next;
	}
	prv->next = new;
	list->last = new;
}
