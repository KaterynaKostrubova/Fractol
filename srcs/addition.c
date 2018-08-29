/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:26:03 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/13 17:26:05 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			set_p_burningship(t_fract *frl)
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
		if ((frl->old_im) < 0)
			frl->old_im *= -1;
		frl->new_re = frl->old_re * frl->old_re - frl->old_im * frl->old_im
		+ frl->c_re;
		frl->new_im = frl->old_re * frl->old_im * 2 + frl->c_im;
		if ((frl->new_re * frl->new_re + frl->new_im * frl->new_im) > 4)
			break ;
		frl->iter++;
	}
}

void			set_tricorn(t_fract *frl)
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
		frl->new_im = -2 * frl->old_re * frl->old_im + frl->c_im;
		if ((frl->new_re * frl->new_re + frl->new_im * frl->new_im) > 4)
			break ;
		frl->iter++;
	}
}

void			set_perpendical_mandelbrot(t_fract *frl)
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
		if (frl->old_re < 0)
			frl->old_re *= -1;
		frl->new_re = frl->old_re * frl->old_re - frl->old_im * frl->old_im
		+ frl->c_re;
		frl->new_im = -2 * frl->old_re * frl->old_im + frl->c_im;
		if ((frl->new_re * frl->new_re + frl->new_im * frl->new_im) > 4)
			break ;
		frl->iter++;
	}
}

void			set_mandelbrot_third(t_fract *frl)
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
		frl->new_im = (frl->old_re * frl->old_re * 3 - frl->old_im
		* frl->old_im) * frl->old_im + frl->c_im;
		frl->new_re = (frl->old_re * frl->old_re - frl->old_im
		* frl->old_im * 3) * frl->old_re + frl->c_re;
		if ((frl->new_re * frl->new_re + frl->new_im * frl->new_im) > 4)
			break ;
		frl->iter++;
	}
}

void			set_mandelbrot_fourth(t_fract *frl)
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
		frl->new_im = 4 * frl->old_re * frl->old_im * ((frl->old_re *
		frl->old_re) - (frl->old_im * frl->old_im)) + frl->c_im;
		frl->new_re = (frl->old_re * frl->old_re) * (frl->old_re * frl->old_re)
		+ (frl->old_im * frl->old_im) * (frl->old_im * frl->old_im) - 6 *
		(frl->old_re * frl->old_re) * (frl->old_im * frl->old_im) + frl->c_re;
		if ((frl->new_re * frl->new_re + frl->new_im * frl->new_im) > 4)
			break ;
		frl->iter++;
	}
}
