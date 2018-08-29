/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 17:34:18 by kkostrub          #+#    #+#             */
/*   Updated: 2018/08/13 17:34:22 by kkostrub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "math.h"
# include "../libft/libft.h"
# include <pthread.h>

# define WIDTH 1200
# define HEIGHT 800
# define THREAD 16
# define CENTER_W WIDTH / 2
# define CENTER_H HEIGHT / 2
# define LEFT 125
# define RIGHT 126
# define DOWN 124
# define UP 123
# define PLUS_NUM 69
# define MINUS_NUM 78
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define ONE_N 83
# define TWO_N 84
# define THREE_N 85
# define FOUR_N 86
# define LEFT_MOUSE 1
# define RIGHT_MOUSE 2
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define SPACE 49
# define M 46
# define J 38
# define S 1
# define T 17
# define P 35
# define Z 6
# define X 7
# define F 3
# define R 15
# define G 5
# define B 11

typedef struct		s_fract
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data_addr;
	int				bpp;
	int				sl;
	int				end;
	int				st;
	int				en;
	int				status;
	int				*img_status_addr;
	int				type_fract;
	double			c_re;
	double			c_im;
	double			new_re;
	double			new_im;
	double			old_re;
	double			old_im;
	int				rand;
	double			zoom;
	double			move_x;
	double			move_y;
	double			zoom_f;
	double			move_x_f;
	double			move_y_f;
	int				max_iter;
	int				x;
	int				y;
	int				iter;
	int				color;
	int				julia_pause;
	float			color_number;
	int				flag_iter;
	int				flag_color;
	int				menu;
	double			shift_left;
	double			shift_right;
	double			h;
	double			w;
	int				color_fern;
}					t_fract;

void				set_value(t_fract *frl);
void				make_threads(t_fract *frl);
void				make_img(t_fract *frl, int x, int y, int color);
void				set_barnsley_fern(t_fract *frl);
void				set_mandelbrot(t_fract *frl);
void				set_julia(t_fract *frl);
void				set_p_burningship(t_fract *frl);
void				set_perpendical_mandelbrot(t_fract *frl);
void				set_tricorn(t_fract *frl);
int					deal_key(int key, t_fract *frl);
t_fract				*action(t_fract *frl, int key);
int					mouse(int key, int x, int y, t_fract *frl);
int					mouse_julia(int x, int y, t_fract *frl);
void				ft_put_string(t_fract *frl);
void				set_mandelbrot_third(t_fract *frl);
void				set_mandelbrot_fourth(t_fract *frl);

#endif
