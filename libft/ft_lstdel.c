/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:52:09 by majullie          #+#    #+#             */
/*   Updated: 2016/11/23 08:05:58 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*nxt;

	cur = *alst;
	while (cur)
	{
		nxt = cur->next;
		ft_lstdelone(&cur, del);
		free(cur);
		cur = nxt;
	}
	*alst = NULL;
}
