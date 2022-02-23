/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:18:53 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 14:51:46 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	correct_free(t_fract *fract)
{
	if (!fract)
		return ;
	if (fract->win)
	{
		if (fract->win->win)
			mlx_destroy_window(fract->win->mlx, fract->win->win);
	}
	if (fract->img)
	{
		if (fract->img->img)
			mlx_destroy_image(fract->win->mlx, fract->img->img);
	}
	free(fract->img);
	free(fract->win);
	free(fract);
}

void	destroy_img(t_fract *fract)
{
	if (!fract)
		return ;
	if (fract->img)
	{
		mlx_destroy_image(fract->win->mlx, fract->img->img);
		free(fract->img);
		fract->img = NULL;
	}
}

void	set_origin(t_fract	*fract)
{
	if (!fract)
		return ;
	fract->img = NULL;
	fract->max = init_complex(2.0, 1.5);
	fract->min = init_complex(-2.0, -2.0);
	fract->max.Im = fract->min.Im + (fract->max.Re - fract->min.Re)
				* fract->win->height / fract->win->width;
	fract->max_iterations = 150;
	fract->shift = 0;
	draw_fractol(fract);
}