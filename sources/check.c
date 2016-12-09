/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:35:28 by majullie          #+#    #+#             */
/*   Updated: 2016/12/07 11:35:46 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		check_bf(char *bf, size_t len, t_ress *p_ress)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if ((bf[i] != '.' && bf[i] != '#')
				|| (bf[i + 1] != '.' && bf[i + 1] != '#')
				|| (bf[i + 2] != '.' && bf[i + 2] != '#')
				|| (bf[i + 3] != '.' && bf[i + 3] != '#')
				|| (bf[i + 4] != '\n'))
			free_and_die(p_ress, "error");
		i += 5;
	}
	if (len == 21 && bf[20] != '\n')
		free_and_die(p_ress, "error");
	check_count(bf, p_ress);
}

void		check_count(char *bf, t_ress *p_ress)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 20)
	{
		if (bf[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		free_and_die(p_ress, "error");
}

void		check_tetri(t_tetri *tetri, t_ress *p_ress)
{
	if ((ft_strcmp(tetri->coord, "00102030") != 0)
			&& (ft_strcmp(tetri->coord, "00010203") != 0)
			&& (ft_strcmp(tetri->coord, "00100111") != 0)
			&& (ft_strcmp(tetri->coord, "00102001") != 0)
			&& (ft_strcmp(tetri->coord, "00101112") != 0)
			&& (ft_strcmp(tetri->coord, "20011121") != 0)
			&& (ft_strcmp(tetri->coord, "00102021") != 0)
			&& (ft_strcmp(tetri->coord, "10110212") != 0)
			&& (ft_strcmp(tetri->coord, "00011121") != 0)
			&& (ft_strcmp(tetri->coord, "00100102") != 0)
			&& (ft_strcmp(tetri->coord, "10200111") != 0)
			&& (ft_strcmp(tetri->coord, "00011112") != 0)
			&& (ft_strcmp(tetri->coord, "00101121") != 0)
			&& (ft_strcmp(tetri->coord, "10011102") != 0)
			&& (ft_strcmp(tetri->coord, "10011121") != 0)
			&& (ft_strcmp(tetri->coord, "00011102") != 0)
			&& (ft_strcmp(tetri->coord, "00102011") != 0)
			&& (ft_strcmp(tetri->coord, "10011112") != 0)
			&& (ft_strcmp(tetri->coord, "00010212") != 0))
		free_and_die(p_ress, "error");
}
