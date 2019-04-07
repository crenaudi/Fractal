#include "../includes/fractol.h"

void win_close(t_env *env)
{
  mlx_destroy_window(env->mlx_ptr, env->win_ptr);
  ft_bzero(env, sizeof(t_env));
  exit(0);
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
  mandelbrot(env);
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
