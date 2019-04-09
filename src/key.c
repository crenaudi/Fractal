#include "../includes/fractol.h"

void win_close(t_env *env)
{
  mlx_destroy_window(env->mlx_ptr, env->win_ptr);
  ft_bzero(env, sizeof(t_env));
  exit(0);
}

void	legend(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 20, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 40, 0x999999, "<- / ->");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0xFFFFFFF,
			"DISPLACEMENT :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 90, 0x999999,
			"W / A / S / D");
}

int		key_press(int key, void *param)
{
  t_env *env;

  env = (t_env *)param;
  if (key == ESC)
    win_close(env);
  if (key == MOVE)
    env->move = 1;
  if (key == 116)
    env->scale = 1;
  if (key == 121)
    env->scale = 1;
  return (SUCCESS);
}

int		key_release(int key, void *param)
{
  t_env *env;

  env = (t_env *)param;
  if (key == MOVE)
    env->move = 0;
  if (key == 116)
    env->scale.x = 0;
  if (key == 121)
    env->scale.y = 0;
  return (SUCCESS);
}
