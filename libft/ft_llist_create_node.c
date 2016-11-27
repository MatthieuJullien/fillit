/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llist_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 08:40:33 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 09:36:19 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_llnode	*ft_llist_create_node(const void *val, size_t val_size)
{
	t_llnode	*new;

	if (val_size == 0 || val == NULL)
		return (NULL);
	new = (t_llnode *)malloc(sizeof(t_llnode));
	if (new == NULL)
		return (NULL);
	new->val = (void *)malloc(val_size);
	if (new->val == NULL)
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->val, val, val_size);
	new->val_size = val_size;
	new->next = NULL;
	return (new);
}
