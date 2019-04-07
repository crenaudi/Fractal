/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:43:37 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 14:45:11 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		need_px(t_trace *b, t_env *env)
{
	int x;
	int y;

	x = b->p1.x + (WIDTH / 2);
	y = b->p1.y + ((HEIGHT / 2) - (int)env->scale);
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= (HEIGHT)))
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, x, y, 0x336699);
}

static void		init_trace(t_trace *b, t_point p1, t_point p2)
{
	ft_bzero(b, sizeof(t_trace));
	b->p1 = (t_vec2){(int)p1.x, (int)p1.y};
	b->p2 = (t_vec2){(int)p2.x, (int)p2.y};
	b->dir.x = abs(b->p2.x - b->p1.x);
	b->dir.y = abs(b->p2.y - b->p1.y);
	b->sens.x = b->p1.x < b->p2.x ? 1 : -1;
	b->sens.y = b->p1.y < b->p2.y ? 1 : -1;
	b->c1 = init_c(0x112233);
	b->c2 = init_c(0x336699);
	b->t = vec2_dist(b->p2 - b->p1);
}

void			line(t_env *env, t_point p1, t_point p2)
{
	t_trace		b;
	t_vec2		err;

	init_trace(&b, p1, p2);
	err.x = (b.dir.x > b.dir.y ? b.dir.x : -b.dir.y) / 2;
	err.y = 0;
	while ("OUIIIIIIIIIII")
	{
		need_px(&b, env);
		if (b.p1.x == b.p2.x && b.p1.y == b.p2.y)
			return ;
		err.y = err.x;
		if (err.y > -b.dir.x)
		{
			err.x -= b.dir.y;
			b.p1.x += b.sens.x;
		}
		if (err.y < b.dir.y)
		{
			err.x += b.dir.x;
			b.p1.y += b.sens.y;
		}
	}
}
