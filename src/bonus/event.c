/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 17:36:07 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 14:47:23 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int		fdf_event(int key, t_fdf *fdf)
{
	if (key == ESC)
	{
		fdf_parciel_clean_fdf(fdf);
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	if (key == O)
	{
		fdf->rot_map.x = deg2rad(-50);
		fdf->rot_map.y = deg2rad(-50);
		fdf->rot_map.z = deg2rad(30);
	}
	if (key == P)
	{
		fdf->rot_map.x = deg2rad(-25);
		fdf->rot_map.y = deg2rad(0);
		fdf->rot_map.z = deg2rad(0);
	}
	return (SUCCESS);
}

int		fdf_key_press_event(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MOVE_U)
		fdf->up = 1;
	if (key == MOVE_D)
		fdf->down = 1;
	if (key == MOVE_R)
		fdf->right = 1;
	if (key == MOVE_L)
		fdf->left = 1;
	if (key == ZOOM)
		fdf->front = 1;
	if (key == DZOOM)
		fdf->back = 1;
	if (key == UP)
		fdf->v_up = 1;
	if (key == DOWN)
		fdf->v_down = 1;
	if (key == RIGHT)
		fdf->v_left = 1;
	if (key == LEFT)
		fdf->v_right = 1;
	fdf_event(key, fdf);
	return (0);
}

int		fdf_key_release_event(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MOVE_U)
		fdf->up = 0;
	if (key == MOVE_D)
		fdf->down = 0;
	if (key == MOVE_R)
		fdf->right = 0;
	if (key == MOVE_L)
		fdf->left = 0;
	if (key == ZOOM)
		fdf->front = 0;
	if (key == DZOOM)
		fdf->back = 0;
	if (key == UP)
		fdf->v_up = 0;
	if (key == DOWN)
		fdf->v_down = 0;
	if (key == RIGHT)
		fdf->v_left = 0;
	if (key == LEFT)
		fdf->v_right = 0;
	return (0);
}

int		fdf_win_event(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->up = 0;
	fdf->down = 0;
	fdf->left = 0;
	fdf->right = 0;
	fdf->front = 0;
	fdf->back = 0;
	return (0);
}
