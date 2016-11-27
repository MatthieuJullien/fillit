/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:43:10 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 13:24:17 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_llist_merge(t_llist *list1, t_llist *list2)
{
	t_llist	*copy_list2;

	if (list1 == NULL || list2 == NULL)
		return ;
	copy_list2 = ft_llist_copy(list2);
	if (copy_list2 == NULL)
		return ;
	list1->last->next = copy_list2->first;
	list1->last = copy_list2->last;
	list1->size = list1->size + copy_list2->size;
	free(copy_list2);
}
