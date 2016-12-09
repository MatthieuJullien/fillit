/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majullie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 08:53:54 by majullie          #+#    #+#             */
/*   Updated: 2016/12/06 08:54:20 by majullie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

float		ft_fmin(float x, float y)
{
	if (x < y)
		return (x);
	return (y);
}

double		ft_dmin(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}
