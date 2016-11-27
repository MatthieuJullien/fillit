/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_sorted_merge.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:46:02 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:19:07 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_sorted_merge(t_llist *list1, t_llist *list2, int (*cmp)())
{
	t_llnode	*cur;

	cur = list2->first;
	while (cur)
	{
		ft_llist_sorted_insert(list1, cur->val, cur->val_size, cmp);
		cur = cur->next;
	}
}
