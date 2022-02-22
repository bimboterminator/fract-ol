/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:49:27 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/20 21:37:13 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_pressed(int keycode, void *param){
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

int	zoom_in(int button, int x, int y, void *param)
{
	return (0);
}

int zoom_out(int button, int x, int y, void *param)
{
	return (0);
}