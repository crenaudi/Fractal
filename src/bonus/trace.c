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

#include "../../includes/fdf.h"

static void		px(t_img *img, int x, int y, int color)
{
	int		index;

	index = x + y * WIN_W;
	if (index < 0 || index >= WIN_H * WIN_W)
		return ;
	img->data[index] = color;
}

static void		need_px(t_trace *b, t_fdf *fdf)
{
	int x;
	int y;

	x = b->p1.x + ((WIN_W / 2) + fdf->tr.y);
	y = b->p1.y + (((WIN_H / 2) - (int)fdf->scl) + fdf->tr.x);
	if ((x >= 0 && x <= WIN_W) && (y >= 0 && y <= (WIN_H)))
		px(fdf->img, x, y, lerp_c(b->c2, b->c1,
			fmod(((vec2_dist(b->p2 - b->p1)) / b->t) + fdf->bert, 1.0)));
}

static void		init_trace(t_trace *b, t_point p1, t_point p2, t_vec3 z)
{
	ft_bzero(b, sizeof(t_trace));
	b->p1 = (t_vec2){(int)p1.x, (int)p1.y};
	b->p2 = (t_vec2){(int)p2.x, (int)p2.y};
	b->dir.x = abs(b->p2.x - b->p1.x);
	b->dir.y = abs(b->p2.y - b->p1.y);
	b->sens.x = b->p1.x < b->p2.x ? 1 : -1;
	b->sens.y = b->p1.y < b->p2.y ? 1 : -1;
	b->c1 = z.x != 0.0 ? init_c(lerp_non_init_color(0x112233, 0x336699,
		z.x)) : init_c(0x112233);
	b->c2 = z.y != 0.0 ? init_c(lerp_non_init_color(0x112233, 0x336699,
		z.y)) : init_c(0x112233);
	b->t = vec2_dist(b->p2 - b->p1);
}

void			fdf_line(t_fdf *fdf, t_point p1, t_point p2, t_vec3 z)
{
	t_trace		b;
	t_vec2		err;

	init_trace(&b, p1, p2, z);
	err.x = (b.dir.x > b.dir.y ? b.dir.x : -b.dir.y) / 2;
	err.y = 0;
	while ("OUIIIIIIIIIII")
	{
		need_px(&b, fdf);
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
