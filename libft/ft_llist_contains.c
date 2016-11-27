/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_contains.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:39:35 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:12:31 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_llist_contains(t_llist *list, const void *val, int (cmp)())
{
	if (ft_llist_indexof(list, val, cmp) == -1)
		return (0);
	else
		return (1);
}
