/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:21:56 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/13 17:21:58 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void	fern_condition(t_fract *frl)
{
	if (frl->rand == 0)
	{
		frl->new_re = 0.0;
		frl->new_im = 0.16 * frl->old_im;
	}
	else if (frl->rand >= 1 && frl->rand <= 7)
	{
		frl->new_re = -0.15 * frl->old_re + 0.28 * frl->old_im;
		frl->new_im = 0.26 * frl->old_re + 0.24 * frl->old_im
		+ frl->shift_right;
	}
	else if (frl->rand >= 8 && frl->rand <= 15)
	{
		frl->new_re = 0.20 * frl->old_re - 0.26 * frl->old_im;
		frl->new_im = 0.26 * frl->old_re + 0.212 * frl->old_im
		+ frl->shift_left;
	}
	else
	{
		frl->new_re = 0.85 * frl->old_re + 0.04 * frl->old_im;
		frl->new_im = -0.04 * frl->old_re + 0.85 * frl->old_im + frl->zoom_f;
	}
}

void			set_barnsley_fern(t_fract *frl)
{
	frl->old_re = 0;
	frl->old_im = 0;
	frl->iter = -1;
	while (++frl->iter < frl->max_iter)
	{
		make_img(frl, frl->h * frl->old_re + frl->move_x_f,
		frl->move_y_f - frl->w * frl->old_im, frl->color_fern);
		frl->rand = rand() % 100;
		fern_condition(frl);
		frl->old_re = frl->new_re;
		frl->old_im = frl->new_im;
	}
}

void			set_mandelbrot(t_fract *frl)
{
	frl->c_re = 1.5 * (frl->x - WIDTH / 2) / (0.5 * frl->zoom * WIDTH)
	+ frl->move_x;
	frl->c_im = (frl->y - HEIGHT / 2) / (0.5 * frl->zoom * HEIGHT)
	+ frl->move_y;
	frl->new_re = 0;
	frl->new_im = 0;
	frl->old_re = 0;
	frl->old_im = 0;
	frl->iter = 0;
	while (frl->iter < frl->max_iter)
	{
		frl->old_re = frl->new_re;
		frl->old_im = frl->new_im;
		frl->new_re = frl->old_re * frl->old_re - frl->old_im * frl->old_im
		+ frl->c_re;
		frl->new_im = 2 * frl->old_re * frl->old_im + frl->c_im;
		if ((frl->new_re * frl->new_re + frl->new_im * frl->new_im) > 4)
			break ;
		frl->iter++;
	}
}

void			set_julia(t_fract *frl)
{
	frl->new_re = 1.5 * (frl->x - WIDTH / 2) / (0.5 * frl->zoom * WIDTH)
	+ frl->move_x;
	frl->new_im = (frl->y - HEIGHT / 2) / (0.5 * frl->zoom * HEIGHT)
	+ frl->move_y;
	frl->iter = 0;
	while (frl->iter < frl->max_iter)
	{
		frl->old_re = frl->new_re;
		frl->old_im = frl->new_im;
		frl->new_re = frl->old_re * frl->old_re - frl->old_im * frl->old_im
		+ frl->c_re;
		frl->new_im = 2 * frl->old_re * frl->old_im + frl->c_im;
		if ((frl->new_re * frl->new_re + frl->new_im * frl->new_im) > 4)
			break ;
		frl->iter++;
	}
}
