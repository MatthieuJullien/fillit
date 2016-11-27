/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:31:48 by majullie          #+#    #+#             */
/*   Updated: 2016/11/24 08:37:44 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	aux_iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;

	if (s == NULL)
		return (NULL);
	start = 0;
	end = 0;
	while (s[start] != '\0' && aux_iswhitespace(s[start]))
		start++;
	end = ft_strlen(s);
	while (end > 0 && aux_iswhitespace(s[end - 1]))
		end--;
	if (end - start <= 0)
		return (ft_strnew(0));
	return (ft_strsub(s, start, end - start));
}
