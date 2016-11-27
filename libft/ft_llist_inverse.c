/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_inverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:42:13 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:14:34 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_inverse(t_llist *list)
{
	t_llnode	*prv;
	t_llnode	*cur;
	t_llnode	*nxt;

	if (list == NULL)
		return ;
	prv = list->first;
	cur = prv->next;
	list->first = list->last;
	list->last = prv;
	prv->next = NULL;
	while (cur)
	{
		nxt = cur->next;
		cur->next = prv;
		prv = cur;
		cur = nxt;
	}
}
