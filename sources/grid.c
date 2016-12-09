/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 09:10:14 by majullie          #+#    #+#             */
/*   Updated: 2016/12/09 09:29:07 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			grid_alloc(char ***p_grid, int grid_size)
{
	int		i;
	char	**grid;

	if (!(grid = (char **)malloc(sizeof(char *) * grid_size)))
		return (0);
	i = 0;
	while (i < grid_size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * grid_size)))
			return (0);
		ft_memset(grid[i], '.', grid_size);
		i++;
	}
	*p_grid = grid;
	return (1);
}

void		free_grid(t_grid **grid)
{
	int		line_num;

	line_num = 0;
	while (line_num < (*grid)->size)
	{
		free((*grid)->map[line_num]);
		line_num++;
	}
	free((*grid)->map);
	free(*grid);
	*grid = NULL;
}
