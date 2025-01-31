/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:10:44 by crenaudi          #+#    #+#             */
/*   Updated: 2019/05/12 19:37:31 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"
# include "gfx.h"

# define ERROR 		-1
# define SUCCESS	0
# define WIDTH		1074
# define HEIGHT		550
# define THREADS	6
# define ESC		53
# define RED		83
# define GREEN		84
# define BLUE		85
# define TOP		126
# define BOTTOM		125
# define RIGHT		124
# define LEFT		123
# define MORE		116
# define LESS 		121
# define FD 		51

typedef struct s_env		t_env;
typedef struct s_envthread	t_envthread;

struct				s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*img;
	t_img			*txt_box;
	t_envthread		**e_thread;
	t_vec2			move;
	t_vec2			abscisse;
	t_vec2			ordonne;
	int				color;
};

struct				s_envthread
{
	int				*data;
	int				fractal;
	float			x;
	float			x1;
	float			y1;
	float			zoom;
	float			z_r;
	float			z_i;
	float			c_r;
	float			c_i;
	float			it_max;
	float			hsl;
};

int					init_env(t_env *env);
void				win_close(t_env *env);
int					**do_tab_px(int y);
t_env				*init_fractal(t_env *env, int fractal, char *title);
void				init_thread_mandelbrot(t_envthread *thrd, float hsl);
void				init_thread_julia(t_envthread *thrd, float hsl);
void				init_thread_burning(t_envthread *thrd, float hsl);
void				init_thread_celtic(t_envthread *thrd, float hsl);
void				init_thread_mandelbar(t_envthread *thrd, float hsl);
void				init_thread_buddabrot(t_envthread *thrd, float hsl);
void				*open_thread(void *param);
int					fractal(t_env *env);
void				julia(t_envthread *e, int i, float y);
void				mandelbrot(t_envthread *e, int i, float y);
void				burning_ship(t_envthread *e, int i, float y);
void				celtic(t_envthread *e, int i, float y);
void				mandelbar(t_envthread *e, int i, float y);
void				buddhabrot(t_envthread *e, int i, float y);
void				color_px(t_envthread *e, float i, float y, int color);
void				put_px(int *data, int x, int y, int color);
int					mouse_event(int code, int x, int y, void *param);
int					mouse_release(int code, int x, int y, void *param);
int					key_press(int key, void *param);
int					key_release(int key, void *param);
void				change_color(int key, t_env *env);
void				legend(t_env *env, int fractal);
void				is_error(int i);
void				kill_env_threads(t_envthread **thread);
void				zoom(int xx, int yy, t_envthread *e);
void				dezoom(int xx, int yy, t_envthread *e);
void				do_fd(t_env *env);

#endif
