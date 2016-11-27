/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_rm_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:43:51 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:16:39 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_rm_first(t_llist *list)
{
	t_llnode	*node;

	if (list == NULL || list->size == 0)
		return ;
	node = list->first;
	list->first = list->first->next;
	list->size--;
	if (list->size <= 1)
		list->last = list->first;
	ft_llist_destroy_node(&node);
}
