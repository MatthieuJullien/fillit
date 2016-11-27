/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:47:45 by majullie          #+#    #+#             */
/*   Updated: 2016/11/26 12:19:36 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *sub)
{
	int		i;
	int		j;

	if (sub[0] == '\0')
		return ((char *)str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == sub[j])
		{
			while (str[i + j] == sub[j] && sub[j] != '\0')
				j++;
			if (sub[j] == '\0')
				return ((char *)str + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
