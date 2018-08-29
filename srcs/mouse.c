/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:52:23 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/15 16:52:26 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void	zoom(int key, int x, int y, t_fract *frl)
{
	if (key == MOUSE_UP || key == LEFT_MOUSE)
	{
		frl->zoom *= 1.3;
		frl->move_x += (x - CENTER_W) / (frl->zoom * WIDTH);
		frl->move_y += (y - CENTER_H) / (frl->zoom * HEIGHT);
		(frl->flag_iter == 1) ? frl->max_iter++ : 0;
		(frl->flag_color == 1) ? frl->color_number += 10000 : 0;
	}
	else if (key == MOUSE_DOWN || key == RIGHT_MOUSE)
	{
		if (frl->zoom > 0.1)
		{
			frl->zoom /= 1.3;
			frl->move_x -= (x - CENTER_W) / (frl->zoom * WIDTH);
			frl->move_y -= (y - CENTER_H) / (frl->zoom * HEIGHT);
			(frl->flag_iter == 1) ? frl->max_iter-- : 0;
			if (frl->flag_color == 1)
				(frl->color_number > 10000) ? frl->color_number -= 10000 : 0;
		}
	}
}

int				mouse(int key, int x, int y, t_fract *frl)
{
	ft_bzero(frl->img_data_addr, WIDTH * HEIGHT * 5);
	if (frl->type_fract == 6)
	{
		if (key == MOUSE_UP || key == LEFT_MOUSE)
			frl->zoom_f *= 1.3;
		else if (key == MOUSE_DOWN || key == RIGHT_MOUSE)
			if (frl->zoom_f > 0.6)
				frl->zoom_f /= 1.3;
	}
	else
		zoom(key, x, y, frl);
	make_threads(frl);
	ft_put_string(frl);
	return (0);
}

int				mouse_julia(int x, int y, t_fract *frl)
{
	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT
	&& frl->julia_pause == 1 && frl->type_fract == 2)
	{
		frl->c_re = (double)x / (double)WIDTH * 4 - 2;
		frl->c_im = (double)y / (double)HEIGHT * 4 - 2;
		(frl->flag_color == 1) ? frl->color_number += 10 : 0;
		make_threads(frl);
		ft_put_string(frl);
	}
	return (0);
}
