/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 11:36:16 by majullie          #+#    #+#             */
/*   Updated: 2016/12/07 17:25:53 by qpradell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		solve(t_llist *tetris, t_grid *grid)
{
	while (!solve_grid(tetris, tetris->first, grid, 0))
	{
		grid->size++;
		if ((grid_alloc(&grid->map, grid->size)) == -1)
			die("error");
	}
	print_grid(tetris, grid->map, grid->size);
}

int			solve_grid(t_llist *tetris, t_llnode *cur, t_grid *grid, int i)
{
	int			j;

	j = 0;
	if (cur != NULL)
	{
		while (i < grid->size)
		{
			if (try_each_block((t_tetri *)cur->val, grid, j, i) == 1)
			{
				((t_tetri *)cur->val)->position = i + j * 100;
				if (solve_grid(tetris, cur->next, grid, 0) == 1)
					return (1);
				clear_tetri((t_tetri *)cur->val, grid->map);
			}
			j++;
			if (j == grid->size)
			{
				j = 0;
				i++;
			}
		}
		return (0);
	}
	return (1);
}

int			try_each_block(t_tetri *tetri, t_grid *grid, int x0, int y0)
{
	int		block;
	int		x;
	int		y;

	block = 0;
	while (block < 4)
	{
		x = tetri->coord[block * 2] - '0';
		y = tetri->coord[block * 2 + 1] - '0';
		if ((x0 + x) >= grid->size
				|| (y0 + y) >= grid->size
				|| grid->map[y0 + y][x0 + x] != '.')
			return (0);
		block++;
	}
	block = 0;
	while (block < 4)
	{
		x = tetri->coord[block * 2] - '0';
		y = tetri->coord[block * 2 + 1] - '0';
		grid->map[y0 + y][x0 + x] = tetri->sign;
		block++;
	}
	return (1);
}
