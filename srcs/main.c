/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 15:49:04 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/13 15:53:48 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void	ft_usage(void)
{
	ft_putendl("usage: ./fractol [type of fractol]\nM - mandelbrot;\n"
				"J  - julia;\nS  - perpendical_burning_ship;\nT  - tricorn;\n"
				"PM - perpendical_mandelbrot\nF - barnsley fern\n"
				"M3 - 3rd Order Mandelbrot\nM4 - 4th Order Mandelbrot");
	exit(0);
}

static	void	ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

void			set_value(t_fract *frl)
{
	frl->c_im = 0.27015;
	frl->c_re = -0.7;
	frl->max_iter = (frl->type_fract == 6) ? 50000 : 50;
	frl->zoom = 1;
	frl->move_x = 0;
	frl->move_y = 0;
	frl->color = 256;
	(frl->type_fract == 1 || frl->type_fract == 7 || frl->type_fract == 8)
	? frl->color_number = 1114129 : 0;
	(frl->type_fract == 2) ? frl->color_number = 10 : 0;
	(frl->type_fract == 3) ? frl->color_number = 1048576 : 0;
	(frl->type_fract == 4) ? frl->color_number = 1118464 : 0;
	(frl->type_fract == 5) ? frl->color_number = 4369 : 0;
	(frl->type_fract == 6) ? frl->color_fern = 65280 : 0;
	frl->flag_iter = 0;
	frl->flag_color = 0;
	frl->menu = (frl->menu == 1) ? 1 : 0;
	(frl->type_fract == 2) ? (frl->julia_pause = 1) : 0;
	frl->move_x_f = WIDTH / 2;
	frl->move_y_f = HEIGHT / 1.1;
	frl->h = 30;
	frl->w = 30;
	frl->zoom_f = 3.6;
	frl->shift_left = 0.44;
	frl->shift_right = 0.44;
}

static	void	check_type(t_fract *frl, char *av)
{
	if (ft_strcmp(av, "M") == 0)
		frl->type_fract = 1;
	else if (ft_strcmp(av, "J") == 0)
		frl->type_fract = 2;
	else if (ft_strcmp(av, "S") == 0)
		frl->type_fract = 3;
	else if (ft_strcmp(av, "T") == 0)
		frl->type_fract = 4;
	else if (ft_strcmp(av, "PM") == 0)
		frl->type_fract = 5;
	else if (ft_strcmp(av, "F") == 0)
		frl->type_fract = 6;
	else if (ft_strcmp(av, "M3") == 0)
		frl->type_fract = 7;
	else if (ft_strcmp(av, "M4") == 0)
		frl->type_fract = 8;
	else
		ft_usage();
}

int				main(int argc, char **argv)
{
	t_fract		*frl;

	if (argc != 2)
		ft_usage();
	if (!(frl = (t_fract *)malloc(sizeof(t_fract))))
		ft_error();
	check_type(frl, argv[1]);
	frl->mlx_ptr = mlx_init();
	frl->win_ptr = mlx_new_window(frl->mlx_ptr, WIDTH, HEIGHT, "fractol");
	frl->img_ptr = mlx_new_image(frl->mlx_ptr, WIDTH, HEIGHT);
	frl->img_data_addr = mlx_get_data_addr(frl->img_ptr,
			&frl->bpp, &frl->sl, &frl->end);
	set_value(frl);
	make_threads(frl);
	ft_put_string(frl);
	mlx_hook(frl->win_ptr, 6, 1L < 6, mouse_julia, frl);
	mlx_hook(frl->win_ptr, 2, (1L << 0), deal_key, frl);
	mlx_mouse_hook(frl->win_ptr, mouse, frl);
	mlx_loop(frl->mlx_ptr);
	return (0);
}
