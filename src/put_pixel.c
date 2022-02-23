/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:52:48 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 12:14:17 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

int	get_trgb(int t, int r, int g, int b)
{
	return ((t << 24) | (r << 16) | (g << 8) | b);
}

void	img_put(t_img_inf* image, int x, int y, int color)
{
	char	*dst;

	if (!image)
		return ;
	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	*(unsigned int *)dst =  color;
	
}

char	*get_pixel_pos(t_img_inf*	image, int x, int y)
{
	char	*dst;

	if (!image)
		return (NULL);
	dst = image->addr + (y * image->line_length + x * (image->bpp / 8));
	return (dst);
}

t_img_inf	*new_image(t_fract *fractol)
{
	t_img_inf	*new_img;

	new_img = (t_img_inf *)malloc(sizeof(t_img_inf));
	if (!new_img)
		return (NULL);
	new_img->img = mlx_new_image(fractol->win->mlx, fractol->win->width,
			fractol->win->height);
	if (!new_img->img)
	{
		free(new_img);
		return(NULL);
	}
	new_img->addr = mlx_get_data_addr(new_img->img, &(new_img->bpp),
			&(new_img->line_length), &(new_img->endian));
	return (new_img);
}

void	copy_row(t_img_inf *img, int src, int dest)
{
	char	*from;
	char	*to;
	if (!img)
		return ;
	from = get_pixel_pos(img, 0, src);
	to = get_pixel_pos(img, 0, dest);
	if (!from || !to)
		return ;
	ft_memcpy(to, from, img->line_length);
}

