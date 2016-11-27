/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:52:17 by majullie          #+#    #+#             */
/*   Updated: 2016/11/23 09:36:37 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cell;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	cell = *alst;
	del(cell->content, cell->content_size);
	free(cell);
	*alst = NULL;
}
