/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:09:10 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 12:14:37 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractol(t_fract *fract)
{
	t_img_inf	*pixmap;

	if (!fract)
		return ;
	if (fract->type == MANDELBROT)
		pixmap = draw_mandelbrot(fract);
	if (!pixmap)
		return ;
	if (fract->img != NULL)
		destroy_img(fract);
	fract->img = pixmap;
	mlx_put_image_to_window(fract->win->mlx, fract->win->win, fract->img->img, 0, 0);
}