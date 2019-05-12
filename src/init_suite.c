/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:15:49 by crenaudi          #+#    #+#             */
/*   Updated: 2019/05/12 17:31:46 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_thread_mandelbrot(t_envthread *thrd, float hsl)
{
	thrd->x1 = -3.5f;
	thrd->y1 = -1.3f;
	thrd->zoom = 210;
	thrd->it_max = 90;
	thrd->fractal = 1;
	thrd->hsl = hsl;
}

void	init_thread_julia(t_envthread *thrd, float hsl)
{
	thrd->x1 = -3.0f;
	thrd->y1 = -1.4f;
	thrd->zoom = 200;
	thrd->it_max = 210;
	thrd->fractal = 2;
	thrd->c_r = 0.285f;
	thrd->c_i = 0.01f;
	thrd->hsl = hsl;
}

void	init_thread_burning(t_envthread *thrd, float hsl)
{
	thrd->x1 = -3.5f;
	thrd->y1 = -2.0f;
	thrd->zoom = 200;
	thrd->it_max = 120;
	thrd->fractal = 3;
	thrd->hsl = hsl;
}

void	init_thread_celtic(t_envthread *thrd, float hsl)
{
	thrd->x1 = -5.0f;
	thrd->y1 = -1.9f;
	thrd->zoom = 145;
	thrd->it_max = 120;
	thrd->fractal = 4;
	thrd->hsl = hsl;
}

void	init_thread_mandelbar(t_envthread *thrd, float hsl)
{
	thrd->x1 = -4.5f;
	thrd->y1 = -1.9f;
	thrd->zoom = 145;
	thrd->it_max = 100;
	thrd->fractal = 5;
	thrd->hsl = hsl;
}
