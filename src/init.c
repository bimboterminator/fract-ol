/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:04:54 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/20 22:13:52 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	init_complex(double Re, double Im)
{
	t_complex	z;

	z.Re = Re;
	z.Im = Im;
	return (z);
}

void	set_default(t_fract *fract)
{
	if (!fract)
		return ;
	fract->img = NULL;
	fract->max = init_complex(2.0, 1.0);
	fract->min = init_complex(-2.0, -2.0);
	fract->max.Im = fract->min.Im + (fract->max.Re - fract->min.Re)
				* fract->win->height / fract->win->width;
	fract->max_iterations = 256;
}

void	init_size(t_mlx_win *win, int width, int height)
{
	if (!win)
		return ;
	if (width == 0)
		width = DEF_WIDTH;
	else if (width < 100)
		width = 276;
	else if (width > 1080)
		width = 1080;
	if (height == 0)
		height = DEF_HEIGHT;
	else if (height < 100)
		height = 276;
	else if (height > 1920)
		height = 1920;
	win->width = width;
	win->height = height;
}

int	init_win_and_img(t_fract *fractol)
{
	if (!fractol)
		return (1);
	fractol->win->win = mlx_new_window(fractol->win->mlx, fractol->win->width,
			fractol->win->height, "Fract'ol");
	if (!fractol->win->win)
		return (1);
	return (0);
}

t_fract	*init(int width, int height)
{
	t_fract	*fractol;

	fractol = (t_fract *)malloc(sizeof(t_fract));
	if (!fractol)
		return (NULL);
	fractol->win = (t_mlx_win *)malloc(sizeof(t_mlx_win));
	if (!fractol->win)
	{
		free(fractol);
		return (NULL);
	}
	fractol->win->mlx = mlx_init();
	if (!fractol->win->mlx)
	{
		correct_free(fractol);
		return (NULL);
	}
	init_size(fractol->win, width, height);
	set_default(fractol);
	if (init_win_and_img(fractol))
	{
		correct_free(fractol);
		return (NULL);
	}
	return (fractol);
}
