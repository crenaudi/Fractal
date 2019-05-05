/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 16:03:47 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	init_fdf(t_fdf *fdf, float scale)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (ERROR);
	ft_bzero(img, sizeof(t_img));
	ft_bzero(fdf, sizeof(t_fdf));
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W, WIN_H, "mlx_42");
	img->ptr = mlx_new_image(fdf->mlx_ptr, WIN_W, WIN_H);
	img->data = (int *)(mlx_get_data_addr(img->ptr, &img->bpp, &img->sl,
				&img->endian));
	fdf->img = img;
	fdf->rot_map.x = deg2rad(-50);
	fdf->rot_map.y = deg2rad(-50);
	fdf->rot_map.z = deg2rad(30);
	fdf->scl = scale;
	return (SUCCESS);
}

static void	is_move(t_fdf *fdf)
{
	t_vec2	dir;
	t_vec3	view;

	dir = 0;
	view = 0;
	if (fdf->up != 0)
		dir.x -= 1;
	if (fdf->down != 0)
		dir.x += 1;
	if (fdf->left != 0)
		dir.y -= 1;
	if (fdf->right != 0)
		dir.y += 1;
	if (fdf->v_up != 0)
		view.x += deg2rad(-1);
	if (fdf->v_down != 0)
		view.x += deg2rad(1);
	if (fdf->v_right != 0)
		view.y += deg2rad(-1);
	if (fdf->v_left != 0)
		view.y += deg2rad(1);
	fdf->tr += dir;
	fdf->rot_map.x += view.x;
	fdf->rot_map.y += view.y;
}

int			fdf_generate(void *param)
{
	t_fdf	*fdf;
	float	zoom;

	fdf = (t_fdf *)param;
	zoom = 0;
	if (fdf->front != 0)
		zoom += 0.5f;
	if (fdf->back != 0)
		zoom -= 0.5f;
	fdf->scl += zoom;
	is_move(fdf);
	fdf_converte(fdf);
	fdf->bert += 0.05;
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img->ptr, 0, 0);
	lgd_fdf(fdf);
	return (SUCCESS);
}

int			fdf(t_point **tab, int x, int y)
{
	ft_putendl("j'entre");
	t_fdf	fdf;
	float	scale;

	ft_putendl("j'entre");
	scale = 10.0f;
	if (init_fdf(&fdf, scale) == ERROR)
		exit(0);
	ft_putendl("fdf initier");
	fdf.x_max = x;
	fdf.y_max = y;
	fdf.tab_p = tab;
	fdf.tab_m = tab;
	mlx_loop_hook(fdf.mlx_ptr, fdf_generate, (void *)&fdf);
	mlx_hook(fdf.win_ptr, 2, 0, fdf_key_press_event, (void *)&fdf);
	mlx_hook(fdf.win_ptr, 3, 0, fdf_key_release_event, (void *)&fdf);
	mlx_hook(fdf.win_ptr, 12, 0, fdf_win_event, (void *)&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (SUCCESS);
}
