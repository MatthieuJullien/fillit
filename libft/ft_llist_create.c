/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:40:12 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 10:50:19 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_llist_create(t_llist **list)
{
	if (list == NULL)
		return ;
	*list = (t_llist *)malloc(sizeof(t_llist));
	if (*list == NULL)
		return ;
	(*list)->size = 0;
	(*list)->first = NULL;
	(*list)->last = NULL;
}
