/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 16:19:28 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 14:43:20 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static float	lerp_z(t_fdf *fdf, float z)
{
	if (fdf->z_max == 0 && fdf->z_min == 0)
		return (1);
	return ((z - fdf->z_min) / (fdf->z_max - fdf->z_min));
}

static int		trace(t_fdf *fdf, t_point **coord)
{
	int		x;
	int		y;
	t_vec3	z;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
		{
			if (x < (fdf->x_max - 1))
			{
				z.x = lerp_z(fdf, fdf->tab_p[y][x].z);
				z.y = lerp_z(fdf, fdf->tab_p[y][x + 1].z);
				fdf_line(fdf, coord[y][x], coord[y][x + 1], z);
			}
			if (y < (fdf->y_max - 1))
			{
				z.x = lerp_z(fdf, fdf->tab_p[y][x].z);
				z.y = lerp_z(fdf, fdf->tab_p[y + 1][x].z);
				fdf_line(fdf, coord[y][x], coord[y + 1][x], z);
			}
		}
	}
	return (SUCCESS);
}

int				fdf_converte(t_fdf *fdf)
{
	int		x;
	int		y;

	y = -1;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max)
		{
			fdf->tab_m[y][x].x = fdf->tab_p[y][x].x - (fdf->x_max / 2);
			fdf->tab_m[y][x].y = fdf->tab_p[y][x].y - (fdf->y_max / 2);
			fdf->tab_m[y][x].z = fdf->tab_p[y][x].z - (fdf->z_max / 2);
			scale(&fdf->tab_m[y][x], fdf->scl);
			rotate_x(&fdf->tab_m[y][x], fdf->rot_map.x);
			rotate_y(&fdf->tab_m[y][x], fdf->rot_map.y);
			rotate_z(&fdf->tab_m[y][x], fdf->rot_map.z);
		}
	}
	fdf_clean_image(fdf->img);
	trace(fdf, fdf->tab_m);
	return (SUCCESS);
}
