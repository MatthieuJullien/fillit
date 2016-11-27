/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:40:49 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:13:34 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_llist_destroy(t_llist **list)
{
	t_llnode	*cur;
	t_llnode	*nxt;

	if (list && *list)
	{
		cur = (*list)->first;
		while (cur)
		{
			nxt = cur->next;
			ft_llist_destroy_node(&cur);
			cur = nxt;
		}
		free(*list);
		*list = NULL;
	}
}
