/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:31:51 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/13 17:31:54 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void	menu_2(t_fract *frl)
{
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 330, 0x0000ff, " J - julia");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 350, 0x00cc00, " F - barnsley fern");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 370, 0xffff00, " T - tricorn");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 390, 0x00FFFF, " P - perpendical mandelbrot");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 410, 0xFF0000, " S - perpendical burning ship");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 430, 0x008000, "COLOR: ");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 450, 0xFF0000, " R - red");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 470, 0x00FF00, " G - green");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 490, 0x0000FF, " B - blue");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 520, 0x008000, "Shift color:       NUM1, NUM2");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			1000, 750, 0x800000, "Exit: [esc]");
}

static	void	draw_menu(t_fract *frl)
{
	int y;
	int x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 900;
		while (x < WIDTH)
		{
			mlx_pixel_put(frl->mlx_ptr, frl->win_ptr, x, y, 0x00001a);
			x++;
		}
		y++;
	}
}

static	void	menu(t_fract *frl)
{
	draw_menu(frl);
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 10, 0x00FFFF, "Hide hints:           Z");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 50, 0x00FFFF, "Moov UP/DOWN:         ^/v");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 80, 0x00FFFF, "Moov LEFT/RIGHT:      ->/<-");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 110, 0x00FFFF, "More/Less iterations: NUM+/-");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 140, 0x00FFFF, "Interactive color:    2");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 170, 0x00FFFF, "Iteractive iteration: 3");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 200, 0x00FFFF, "Stop/start Julia:     1");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 230, 0x00FFFF, "Zoom:                 MOUSE");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 260, 0x00FFFF, "Reset:                SPACE");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 290, 0x008000, "Button for switch fractals:");
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			905, 310, 0xff00ff, " M - mandelbrot");
	menu_2(frl);
}

static	void	show_menu(t_fract *frl)
{
	mlx_string_put(frl->mlx_ptr, frl->win_ptr,
			1050, 10, 0x00FFFF, "Show hints: X");
}

void			ft_put_string(t_fract *frl)
{
	(frl->menu == 1) ? menu(frl) : show_menu(frl);
}
