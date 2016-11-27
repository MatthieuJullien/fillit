/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_get_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:41:36 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:14:04 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_llnode	*ft_llist_get_at(t_llist *list, unsigned int index)
{
	t_llnode	*cur;

	if (index > list->size)
		return (NULL);
	cur = list->first;
	while (index > 0 && cur != NULL)
	{
		cur = cur->next;
		index--;
	}
	return (cur);
}
