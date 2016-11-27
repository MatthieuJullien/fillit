/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:20:09 by majullie          #+#    #+#             */
/*   Updated: 2016/11/25 07:32:28 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	aux_count_word(char const *s, char c)
{
	int		nb_word;

	nb_word = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
			nb_word++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (nb_word);
}

static int	aux_len_sub(char const *s, char c)
{
	int		len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static void	aux_fill_tab(char **tab, char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			if (!(tab[i] = ft_strnew(aux_len_sub(s, c) + 1)))
			{
				tab = NULL;
				return ;
			}
			j = 0;
			while (*s != c && *s != '\0')
			{
				tab[i][j] = *s;
				s++;
				j++;
			}
			i++;
		}
	}
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_word;
	char	**tab;

	if (s == NULL)
		return (NULL);
	nb_word = aux_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (tab == NULL)
		return (NULL);
	tab[nb_word] = NULL;
	aux_fill_tab(tab, s, c);
	return (tab);
}
