/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:26:01 by crenaudi          #+#    #+#             */
/*   Updated: 2019/05/12 17:09:37 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(int xx, int yy, t_envthread *e)
{
	float x;
	float y;

	x = (float)xx;
	y = (float)yy;
	e->x1 = (x / e->zoom + e->x1) - (x / (e->zoom * 1.2));
	e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom * 1.2));
	e->zoom *= 1.2;
	e->it_max++;
}

void	dezoom(int xx, int yy, t_envthread *e)
{
	float x;
	float y;

	x = (float)xx;
	y = (float)yy;
	e->x1 = (x / e->zoom + e->x1) - (x / (e->zoom / 1.2));
	e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom / 1.2));
	e->zoom /= 1.2;
	e->it_max--;
}
