/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gfx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:11:34 by crenaudi          #+#    #+#             */
/*   Updated: 2019/03/29 15:12:48 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

float	spherical_theta(t_point v)
{
	return (acos(v.z));
}

float	spherical_phi(t_point v)
{
	float	tmp;

	tmp = atan2(v.y, v.x);
	return (tmp < 0 ? tmp + 2 * M_PI : tmp);
}

t_point	to_vec_spherical(t_point v)
{
	float	theta;
	float	phi;
	t_point	tmp;

	theta = spherical_theta(v);
	phi = spherical_phi(v);
	tmp.x = cos(phi) * cos(theta);
	tmp.y = cos(phi) * sin(theta);
	tmp.z = sin(phi);
	return (tmp);
}

void	spherical_perspective(t_point v, t_point *p)
{
	t_point		tmp;

	tmp.x = (v.x * p->x) + (v.y * p->y) + (v.z * p->z);
	tmp.y = (v.x * p->x) + (v.y * p->y) + (v.z * p->z);
	tmp.z = (v.x * p->x) + (v.y * p->y) + (v.z * p->z);
	*p = tmp;
}
