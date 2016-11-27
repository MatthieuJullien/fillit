/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_rm_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:44:03 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:16:52 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_rm_last(t_llist *list)
{
	t_llnode	*cur;
	t_llnode	*node;

	if (list == NULL || list->size == 0)
		return ;
	node = list->last;
	if (list->size == 1)
	{
		list->first = NULL;
		list->last = NULL;
	}
	else
	{
		cur = list->first;
		while (cur->next != list->last)
			cur = cur->next;
		cur->next = NULL;
		list->last = cur;
	}
	ft_llist_destroy_node(&node);
	list->size--;
}
