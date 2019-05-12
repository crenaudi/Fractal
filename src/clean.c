/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:10:21 by crenaudi          #+#    #+#             */
/*   Updated: 2019/05/12 19:40:50 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			kill_env_threads(t_envthread **thread)
{
	int		i;

	i = -1;
	while (++i < THREADS)
	{
		ft_bzero(thread[i], sizeof(t_envthread));
		free(thread[i]);
	}
	free(thread);
}

void			kill_env(t_env *env)
{
	ft_bzero(env->img->data, WIDTH * HEIGHT * (env->img->bpp / 8));
	mlx_destroy_image(env->mlx_ptr, env->img->ptr);
	free(env->img);
	kill_env_threads(env->e_thread);
}

void			win_close(t_env *env)
{
	kill_env(env);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	ft_bzero(env, sizeof(t_env));
	exit(0);
}
