/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:23:03 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 14:57:12 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void		fdf_clean_tab(t_point **coord, int coord_y)
{
	int	i;

	i = 0;
	while (i < coord_y)
	{
		free(coord[i]);
		i++;
	}
	free(coord);
}

void		fdf_clean_image(t_img *img)
{
	ft_bzero(img->data, WIN_W * WIN_H * (img->bpp / 8));
}

void		fdf_kill_image(t_fdf *fdf, t_img *img)
{
	mlx_destroy_image(fdf->mlx_ptr, img->ptr);
	free(img);
}

void		fdf_parciel_clean_fdf(t_fdf *fdf)
{
	fdf_clean_tab(fdf->tab_p, fdf->y_max);
	fdf_clean_tab(fdf->tab_m, fdf->y_max);
	fdf_kill_image(fdf, fdf->img);
}
