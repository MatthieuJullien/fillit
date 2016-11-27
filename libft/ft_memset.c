/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:16:15 by majullie          #+#    #+#             */
/*   Updated: 2016/11/26 12:13:31 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*us;

	uc = c;
	us = s;
	while (n > 0)
	{
		*us = uc;
		us++;
		n--;
	}
	return (s);
}
