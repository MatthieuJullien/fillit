/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_add_nodup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:39:21 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:12:14 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llist_add_nodup(t_llist *list, void *val, size_t val_size, int (*cmp)())
{
	if (!ft_llist_contains(list, val, cmp))
	{
		ft_llist_add_last(list, val, val_size);
		return (1);
	}
	return (0);
}
