/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:39:51 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:12:50 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llist		*ft_llist_copy(t_llist *list)
{
	t_llist		*copy;
	t_llnode	*cur;

	if (list == NULL)
		return (NULL);
	ft_llist_create(&copy);
	if (copy == NULL)
		return (NULL);
	cur = list->first;
	while (cur != NULL)
	{
		ft_llist_add_last(copy, cur->val, cur->val_size);
		cur = cur->next;
	}
	return (copy);
}
