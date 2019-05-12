/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:15:49 by crenaudi          #+#    #+#             */
/*   Updated: 2019/05/12 17:37:34 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_fractal_suite(t_env *env, char *title)
{
	ft_bzero(env, sizeof(t_env));
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT,
		ft_strjoin("PROJET FRACTOL : ", title));
	env->img = init_img(env->mlx_ptr, HEIGHT, WIDTH);
	env->txt_box = do_div(env->mlx_ptr, 530, 200, 0x111122);
}

static void	init(t_envthread *thrd, int fractal)
{
	if (fractal == 1)
		init_thread_mandelbrot(thrd, 180.0f);
	if (fractal == 2)
		init_thread_julia(thrd, 180.0f);
	if (fractal == 3)
		init_thread_burning(thrd, 180.0f);
	if (fractal == 4)
		init_thread_celtic(thrd, 180.0f);
	if (fractal == 5)
		init_thread_mandelbar(thrd, 180.0f);
}

t_env		*init_fractal(t_env *env, int fractal, char *title)
{
	int			i;
	t_envthread	*thrd;

	i = 0;
	init_fractal_suite(env, title);
	if (!(env->e_thread = (t_envthread **)malloc(sizeof(t_envthread *)
					* THREADS)))
		return (NULL);
	while (i < THREADS)
	{
		if (!(thrd = (t_envthread *)malloc(sizeof(t_envthread))))
			return (NULL);
		ft_bzero(thrd, sizeof(t_envthread));
		init(thrd, fractal);
		thrd->data = env->img->data;
		env->e_thread[i] = thrd;
		i++;
	}
	return (env);
}
