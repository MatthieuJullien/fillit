/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:02:41 by majullie          #+#    #+#             */
/*   Updated: 2016/11/26 12:09:59 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_stradd(char **s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return ;
	if (*s1 == NULL)
		*s1 = ft_strnew(0);
	str = ft_strjoin(*s1, s2);
	free(*s1);
	*s1 = str;
}
