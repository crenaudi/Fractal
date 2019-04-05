#include "../includes/fractol.h"

void win_close(t_env *env)
{
  mlx_destroy_window(env->mlx_ptr, env->win_ptr);
  exit (EXIT_SUCCESS);
}

int		key_press(int key, void *param)
{
  t_env *env;

  env = (t_env *)param;
  if (key == ESC)
    win_close(env);
  if (key == MOVE)
    env->move = 1;
  return (SUCCESS);
}

int		key_release(int key, void *param)
{
  t_env *env;

  env = (t_env *)param;
  if (key == MOVE)
    env->move = 0;
  return (SUCCESS);
}
