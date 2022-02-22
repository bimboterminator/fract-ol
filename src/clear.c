/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:18:53 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/20 21:36:20 by dmesseng         ###   ########.fr       */
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