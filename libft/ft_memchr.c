/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:11:06 by majullie          #+#    #+#             */
/*   Updated: 2016/11/26 12:15:47 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *us;

	us = (unsigned char*)s;
	while (n > 0)
	{
		if (*us == (unsigned char)c)
			return ((void *)us);
		us++;
		n--;
	}
	return (NULL);
}
