/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_indexof.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:41:51 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:14:21 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llist_indexof(t_llist *list, const void *val, int (*cmp)())
{
	t_llnode	*cur;
	int			i;

	if (list == NULL || cmp == NULL)
		return (-1);
	cur = list->first;
	i = 0;
	while (cur != NULL)
	{
		if (cmp(cur->val, val) == 1)
			return (i);
		cur = cur->next;
		i++;
	}
	return (-1);
}
