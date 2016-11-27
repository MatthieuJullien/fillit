/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:57:31 by majullie          #+#    #+#             */
/*   Updated: 2016/11/23 11:26:48 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t old, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		size = 1;
	new_ptr = ft_memalloc(size);
	if (new_ptr == NULL)
		return (NULL);
	if (size < old)
		ft_memmove(new_ptr, ptr, size);
	else
		ft_memmove(new_ptr, ptr, old);
	free(ptr);
	return (new_ptr);
}
