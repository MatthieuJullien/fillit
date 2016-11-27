/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:41:20 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:13:52 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llist_foreach(t_llist *list, void (*f)(void *))
{
	t_llnode	*cur;

	if (list && f)
	{
		cur = list->first;
		while (cur)
		{
			f(cur->val);
			cur = cur->next;
		}
	}
}
