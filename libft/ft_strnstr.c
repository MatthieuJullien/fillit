/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:47:54 by majullie          #+#    #+#             */
/*   Updated: 2016/11/26 12:20:31 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	if (sub[0] == '\0')
		return ((char *)str);
	i = 0;
	j = 0;
	while (i < len && str[i] != '\0')
	{
		if (str[i] == sub[j])
		{
			while (str[i + j] == sub[j] && sub[j] != '\0' && (i + j) < len)
				j++;
			if (sub[j] == '\0')
				return ((char *)str + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
