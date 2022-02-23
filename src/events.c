/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:49:27 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 17:23:15 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"

int	key_pressed(int keycode, void *param){
	if (keycode == ESC)
		close_win(param);
	else if (param && (keycode == ARROW_UP || keycode == ARROW_DOWN
		|| keycode == ARROW_LEFT || keycode == ARROW_RIGHT))
		translation(keycode, (t_fract *)param);
	else if (param && (keycode == R))
		set_origin((t_fract *)param);
	else if (param && (keycode == C))
		shift((t_fract *)param);
	return (0);
}

int	close_win(void *param)
{
	t_fract	*fract;
	if (!param)
		return (0);
	fract = (t_fract *)param;
	correct_free(fract);
	exit(0);
	return (0);
}

int	zoom(int button, int x, int y, void *param)
{
	t_complex	ratio;
	t_fract		*fract;
	t_complex	delta;
	t_complex	delta_delta;
	double		scale;

	fract = (t_fract *)param;
	if (!fract)
		return (1);
	delta = init_complex(fract->max.Re - fract->min.Re,
						fract->max.Im - fract->min.Im);
	ratio = init_complex(1. * x * delta.Re/fract->win->width + fract->min.Re,
					-1. * y * delta.Im/fract->win->height + fract->max.Im);
	if (button == SCROLL_UP)
		scale = 1.2;
	else if (button == SCROLL_DOWN)
		scale = 0.7;
	fract->min.Re = ratio.Re + ((fract->min.Re - ratio.Re) * 1 / scale);
	fract->max.Re = ratio.Re + ((fract->max.Re - ratio.Re) * 1 / scale);
	fract->min.Im = ratio.Im + ((fract->min.Im - ratio.Im) * 1 / scale);
	fract->max.Im = ratio.Im + ((fract->max.Im - ratio.Im) * 1 / scale);
	draw_fractol(fract);
	return (0);
}
