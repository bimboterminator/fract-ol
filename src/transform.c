/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:08:57 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/23 15:27:48 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <math.h>

void	translation(int key, t_fract *fract)
{
	t_complex	scale;

	scale = init_complex(fabs(fract->max.Re - fract->min.Re )/fract->win->width,
					fabs(fract->max.Im - fract->min.Im)/fract->win->height);
	if (key == ARROW_LEFT)
	{
		fract->min.Re += scale.Re * 5;
		fract->max.Re += scale.Re * 5;
	}
	else if(key == ARROW_RIGHT)
	{
		fract->min.Re -= scale.Re * 5;
		fract->max.Re -= scale.Re * 5;
	}
	else if(key == ARROW_UP)
	{
		fract->min.Im -= scale.Im * 5;
		fract->max.Im -= scale.Im * 5;
	}
	else if(key == ARROW_DOWN)
	{
		fract->min.Im += scale.Im * 5;
		fract->max.Im += scale.Im * 5;
	}
	draw_fractol(fract);
}

void	shift(t_fract *fract)
{		
	if (!fract)
		return ;
	fract->shift = (fract->shift + 1) % 3;
	draw_fractol(fract);
}

