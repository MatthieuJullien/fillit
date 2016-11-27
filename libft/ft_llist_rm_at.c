/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_rm_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:43:33 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:16:21 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_rm_at(t_llist *list, unsigned int index)
{
	t_llnode	*prv;
	t_llnode	*cur;

	if (index >= list->size)
		return ;
	if (index == 0)
	{
		cur = list->first;
		list->first = list->first->next;
		ft_llist_destroy_node(&cur);
		list->size--;
		return ;
	}
	cur = list->first;
	while (index > 0)
	{
		prv = cur;
		cur = cur->next;
		index--;
	}
	prv->next = cur->next;
	if (cur->next == NULL)
		list->last = prv;
	ft_llist_destroy_node(&cur);
	list->size--;
}
