/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fhsl_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:41:10 by crenaudi          #+#    #+#             */
/*   Updated: 2019/05/12 15:55:35 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/gfx.h"

float		hsl_float_min(float *n)
{
	float	min;
	int		i;

	i = 0;
	min = n[i];
	while (i++ < 2)
	{
		if (min > n[i])
			min = n[i];
	}
	return (min);
}

float		hsl_float_max(float *n)
{
	float	max;
	int		i;

	i = 0;
	max = n[i];
	while (i++ < 2)
	{
		if (max < n[i])
			max = n[i];
	}
	return (max);
}
