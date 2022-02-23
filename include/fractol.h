/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:57:06 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 15:18:01 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define DEF_WIDTH 800
# define DEF_HEIGHT 600
# define MANDELBROT 0
# define JULIA 1
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"

typedef struct s_img_inf
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img_inf;

typedef struct s_mlx_win
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
}				t_mlx_win;

typedef struct s_complex
{
	double Re;
	double Im;
}				t_complex;

typedef struct s_fract
{
	t_complex 	min;
	t_complex 	max;
	t_mlx_win	*win;
	t_img_inf   *img;
	int			type;
	int			max_iterations;
	int			shift;
}				t_fract;

int			get_trgb(int t, int r, int g, int b);
void		img_put(t_img_inf *image, int x, int y, int color);
char		*get_pixel_pos(t_img_inf*	image, int x, int y);
int			color(int iter, int max_iter, int shift);
t_fract		*init(int width, int height);
t_img_inf	*new_image(t_fract *fractol);
int			key_pressed(int keycode, void *param);
int			close_win(void *param);
int			zoom(int button, int x, int y, void *param);
t_img_inf	*draw_mandelbrot(t_fract *fract);
t_img_inf	*draw_julia(t_fract *fract);
void		draw_fractol(t_fract *fract);
void		correct_free(t_fract *fract);
t_complex	init_complex(double Re, double Im);
void		destroy_img(t_fract *fract);
void		copy_row(t_img_inf *img, int src, int dest);
void		translation(int key, t_fract *param);
void		set_origin(t_fract	*fract);
void		shift(t_fract	*fract);
int			change_pixel(int shift, int r, int g, int b);
#endif