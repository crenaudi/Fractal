/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:41:31 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 16:06:11 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	lgd_fdf(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 20, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 40, 0x999999, "<- / ->");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 70, 0xFFFFFFF,
			"DISPLACEMENT :");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 90, 0x999999,
			"W / A / S / D");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 120, 0xFFFFFF, "ANGLE :");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 140, 0x999999, "(arrows)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 170, 0xFFFFFF,
			"PROJECTION :");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 190, 0x999999, "O / P");
}
