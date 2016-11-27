/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_to_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:47:06 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:19:57 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llist		*ft_llist_to_set(t_llist *list, int (*cmp)())
{
	t_llist		*set;
	t_llnode	*cur;

	ft_llist_create(&set);
	if (set == NULL)
		return (NULL);
	cur = list->first;
	while (cur)
	{
		ft_llist_add_nodup(set, cur->val, cur->val_size, cmp);
		cur = cur->next;
	}
	return (set);
}
