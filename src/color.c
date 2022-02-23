/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:18:47 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 17:26:22 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color(int iter, int max_iter, int shift)
{
	double	t;
	double	r;
	double 	g;
	double	b;
	
	t = (double)iter / max_iter;
	r = 9 * (1 - t) * t * t * t * 255;
	g = 15 * (1 - t) * (1 - t) * t * t * 255;
	b = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (change_pixel(shift, (int)r, (int)g, (int)b));
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int	change_pixel(int shift, int r, int g, int b)
{
	int col;

	col = get_trgb(0, r, g, b);
	if (shift == 0)
		col = get_trgb(0, r, g, b);
	else if (shift == 1)
		col = get_trgb(0, g, b, r);
	else if (shift == 2)
		col = get_trgb(0, b, r, g);
	return (col);
}
