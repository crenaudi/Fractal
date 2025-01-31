/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:16:47 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:17:37 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

void	rotate_x(t_point *p, float a)
{
	t_vec3	tmp;

	tmp.x = (p->x * 1) + (p->y * 0) + (p->z * 0);
	tmp.y = (p->x * 0) + (p->y * cos(a)) + (p->z * sin(a));
	tmp.z = (p->x * 0) + (p->y * -sin(a)) + (p->z * cos(a));
	*p = tmp;
}

void	rotate_y(t_point *p, float a)
{
	t_vec3	tmp;

	tmp.x = (p->x * cos(a)) + (p->y * 0) + (p->z * -sin(a));
	tmp.y = (p->x * 0) + (p->y * 1) + (p->z * 0);
	tmp.z = (p->x * sin(a)) + (p->y * 0) + (p->z * cos(a));
	*p = tmp;
}

void	rotate_z(t_point *p, float a)
{
	t_vec3	tmp;

	tmp.x = (p->x * cos(a)) + (p->y * sin(a)) + (p->z * 0);
	tmp.y = (p->x * -sin(a)) + (p->y * cos(a)) + (p->z * 0);
	tmp.z = (p->x * 0) + (p->y * 0) + (p->z * 1);
	*p = tmp;
}
