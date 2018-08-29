/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 16:54:41 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/13 16:54:48 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				deal_key(int key, t_fract *frl)
{
	if (key == 53)
	{
		mlx_destroy_window(frl->mlx_ptr, frl->win_ptr);
		exit(0);
	}
	else
	{
		ft_bzero(frl->img_data_addr, WIDTH * HEIGHT * 5);
		action(frl, key);
	}
	return (0);
}

static	void	iteration_fern(t_fract *frl, int key)
{
	if (frl->max_iter <= 10000 && frl->max_iter >= 100)
		(key == PLUS_NUM) ? frl->max_iter += 100 : 0;
	else
		(key == PLUS_NUM) ? frl->max_iter += 1000 : 0;
	if (frl->max_iter <= 10000 && frl->max_iter > 100)
		(key == MINUS_NUM) ? frl->max_iter -= 100 : 0;
	else if (frl->max_iter <= 100)
		(key == MINUS_NUM) ? frl->max_iter = 100 : 0;
	else
		(key == MINUS_NUM) ? frl->max_iter -= 1000 : 0;
	(key == SPACE) ? set_value(frl) : 0;
	(key == DOWN) ? frl->move_x_f += 10 : 0;
	(key == UP) ? frl->move_x_f -= 10 : 0;
	(key == RIGHT) ? frl->move_y_f -= 10 : 0;
	(key == LEFT) ? frl->move_y_f += 10 : 0;
}

static	void	action_fern(t_fract *frl, int key)
{
	iteration_fern(frl, key);
	(key == Z) ? frl->menu = 0 : 0;
	(key == X) ? frl->menu = 1 : 0;
	(key == M) ? frl->type_fract = 1 : 0;
	(key == J) ? frl->type_fract = 2 : 0;
	(key == THREE_N) ? frl->type_fract = 7 : 0;
	(key == FOUR_N) ? frl->type_fract = 8 : 0;
	(key == S) ? frl->type_fract = 3 : 0;
	(key == T) ? frl->type_fract = 4 : 0;
	(key == P) ? frl->type_fract = 5 : 0;
	(key == R) ? frl->color_fern = 16711680 : 0;
	(key == G) ? frl->color_fern = 65280 : 0;
	(key == B) ? frl->color_fern = 255 : 0;
	(key == ONE_N) ? frl->color_fern += 10 : 0;
	(key == TWO_N) ? frl->color_fern -= 10 : 0;
	if (key == M || key == J || key == S || key == T || key == P
		|| key == THREE_N || key == FOUR_N)
		set_value(frl);
	if (key == PLUS_NUM || key == MINUS_NUM || key == DOWN
		|| key == UP || key == RIGHT || key == LEFT || key == SPACE
		|| key == M || key == J || key == S || key == T || key == P
		|| key == R || key == G || key == B || key == ONE_N || key == TWO_N
		|| key == THREE_N || key == FOUR_N)
		make_threads(frl);
}

static	void	action_2(t_fract *frl, int key)
{
	(key == M) ? frl->type_fract = 1 : 0;
	(key == J) ? frl->type_fract = 2 : 0;
	(key == S) ? frl->type_fract = 3 : 0;
	(key == T) ? frl->type_fract = 4 : 0;
	(key == P) ? frl->type_fract = 5 : 0;
	(key == F) ? frl->type_fract = 6 : 0;
	(key == THREE_N) ? frl->type_fract = 7 : 0;
	(key == FOUR_N) ? frl->type_fract = 8 : 0;
	if (key == M || key == J || key == S || key == T || key == P || key == F
		|| key == THREE_N || key == FOUR_N)
		set_value(frl);
	(key == SPACE) ? set_value(frl) : 0;
	(key == R) ? frl->color_number = 1048576 : 0;
	(key == G) ? frl->color_number = 4096 : 0;
	(key == B) ? frl->color_number = 10 : 0;
	(frl->color_number < 2) ? frl->color_number = 2 : 0;
	if (key == TWO)
		frl->flag_color = (frl->flag_color == 0) ? 1 : 0;
	if (key == THREE)
		frl->flag_iter = (frl->flag_iter == 0) ? 1 : 0;
}

t_fract			*action(t_fract *frl, int key)
{
	if (frl->type_fract == 6)
		action_fern(frl, key);
	else
	{
		(key == PLUS_NUM) ? frl->max_iter += 10 : 0;
		(key == MINUS_NUM) ? frl->max_iter -= 10 : 0;
		if (key == ONE)
			frl->julia_pause = (frl->julia_pause == 0) ? 1 : 0;
		(key == UP) ? frl->move_x += (0.1 / frl->zoom) : 0;
		(key == DOWN) ? frl->move_x -= (0.1 / frl->zoom) : 0;
		(key == LEFT) ? frl->move_y -= (0.1 / frl->zoom) : 0;
		(key == RIGHT) ? frl->move_y += (0.1 / frl->zoom) : 0;
		(key == Z) ? frl->menu = 0 : 0;
		(key == X) ? frl->menu = 1 : 0;
		(key == ONE_N) ? frl->color_number += 1 : 0;
		(key == TWO_N) ? frl->color_number -= 1 : 0;
		action_2(frl, key);
		make_threads(frl);
	}
	ft_put_string(frl);
	return (frl);
}
