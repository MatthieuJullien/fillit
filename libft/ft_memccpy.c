/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:51:43 by majullie          #+#    #+#             */
/*   Updated: 2016/11/26 12:14:17 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	uc;

	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	uc = (unsigned char)c;
	while (n > 0)
	{
		*d = *s;
		if (*d == uc)
			return (d + 1);
		d++;
		s++;
		n--;
	}
	return (NULL);
}
