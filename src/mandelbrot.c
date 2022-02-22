/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:10:51 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/20 21:44:39 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../libft/libft.h"

static t_img_inf	*paint(int y_min, int y_max,
						double pixel_scale, t_fract	*fract);
static int			iterate(t_complex c, int max_iterations);
static void			copy_half(t_img_inf *pixmap, int y_min, int y_max,
						t_fract *fract);					

t_img_inf	*draw_mandelbrot(t_fract *fract)
{
	t_img_inf	*pixmap;
	double		pixel_scale;
	int			y_min;
	int			y_max;
	
	pixel_scale = (fract->max.Re - fract->min.Re) / fract->win->width;
	y_min = 0;
	y_max = fract->win->height;
	if (fract->min.Im < 0 && fract->max.Im > 0)
	{
		if (fract->max.Im + fract->min.Im >= 0)
			y_max = ((fract->max.Im * fract->win->height)
					/ (fract->max.Im - fract->min.Im)) + 1;
		else
			y_min = ((fract->max.Im * fract->win->height)
					/ (fract->max.Im - fract->min.Im));
	}
	pixmap = paint(y_min, y_max, pixel_scale, fract);
	if (!pixmap)
		return (NULL);
	if (fract->img != NULL)
		destroy_img(fract);
	fract->img = pixmap;
	mlx_put_image_to_window(fract->win->mlx, fract->win->win, fract->img->img, 0, 0);
}

static t_img_inf	*paint(int y_min, int y_max,
						double pixel_scale, t_fract *fract)
{
	int			y;
	int			x;
	t_complex	c;
	t_img_inf	*pixmap;
	
	pixmap = new_image(fract);
	if (!pixmap)
		return (NULL);
	y = y_min;
	while (y < y_max)
	{
		x = 0;
		while (x < fract->win->width)
		{
			c = init_complex(fract->min.Re + x * pixel_scale,
					fract->max.Im - y * pixel_scale);
			img_put(pixmap, x, y, iterate(c, fract->max_iterations));
			x++;
		}
		y++;
	}
	copy_half(pixmap, y_min, y_max, fract);
	return (pixmap);
}

static void	copy_half(t_img_inf *pixmap, int y_min, int y_max,
					t_fract *fract)
{
	int	y;

	y = 0;
	while (y < y_min)
	{
		copy_row(pixmap, y_min + y_min - y, y);
		y++;
	}
	y = y_max;
	while (y < fract->win->height)
	{
		copy_row(pixmap, y_max + y_max - y, y);
		y++;
	}
}

static int	iterate(t_complex c, int max_iterations)
{
	t_complex	z;
	int			i;
	int			rgb;

	z.Im = 0;
	z.Re = 0;
	i = 0;
	rgb = 0;
	while (i < max_iterations)
	{
		if (z.Re * z.Re + z.Im * z.Im > 4.)
			break ;
		z = init_complex(z.Re * z.Re - z.Im * z.Im + c.Re,
				2 * z.Re * z.Im + c.Im);
		i++;
	}
//	printf("it %f %f %d \n",c.Re, c.Im, i);
	rgb = color(i, max_iterations);
	return (rgb);
}
