/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:54:26 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/13 15:55:09 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void	set_fractal(t_fract *frl)
{
	if (frl->type_fract == 1)
		set_mandelbrot(frl);
	else if (frl->type_fract == 2)
		set_julia(frl);
	else if (frl->type_fract == 3)
		set_p_burningship(frl);
	else if (frl->type_fract == 4)
		set_tricorn(frl);
	else if (frl->type_fract == 5)
		set_perpendical_mandelbrot(frl);
	else if (frl->type_fract == 7)
		set_mandelbrot_third(frl);
	else if (frl->type_fract == 8)
		set_mandelbrot_fourth(frl);
}

static	void	calc_fractol(t_fract *frl)
{
	if (frl->type_fract == 6)
		set_barnsley_fern(frl);
	else
	{
		frl->y = frl->st;
		while (frl->y < frl->en)
		{
			frl->x = -1;
			while (++frl->x < WIDTH)
			{
				set_fractal(frl);
				if (frl->iter == frl->max_iter)
					frl->color = 0x000000;
				else if (frl->iter > 0)
					frl->color = frl->color_number * frl->iter;
				else
					frl->color = frl->color_number * 1;
				make_img(frl, frl->x, frl->y, frl->color);
			}
			frl->y++;
		}
	}
}

void			make_threads(t_fract *frl)
{
	pthread_t	threads[THREAD];
	t_fract		frls[THREAD];
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < THREAD)
	{
		frls[i] = *frl;
		frls[i].st = j;
		j += HEIGHT / THREAD;
		frls[i].en = j;
		pthread_create(&threads[i], NULL,
		(void *(*)(void *))calc_fractol, (void *)&frls[i]);
	}
	while (i-- > 0)
		frl->status = pthread_join(threads[i], (void **)&frl->img_status_addr);
	mlx_put_image_to_window(frl->mlx_ptr, frl->win_ptr, frl->img_ptr, 0, 0);
}

void			make_img(t_fract *frl, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int*)(frl->img_data_addr + ((x + y * WIDTH) * 4)) = color;
}
