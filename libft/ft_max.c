/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 08:54:37 by majullie          #+#    #+#             */
/*   Updated: 2016/12/06 08:54:40 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

float		ft_fmax(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

double		ft_dmax(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}
