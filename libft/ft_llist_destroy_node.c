/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_destroy_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:41:05 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:10:19 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_llist_destroy_node(t_llnode **node)
{
	if (node && *node)
	{
		free((*node)->val);
		free(*node);
		*node = NULL;
	}
}
