#include "../includes/fractol.h"

void win_close(t_env *env)
{
  mlx_destroy_window(env->mlx_ptr, env->win_ptr);
  ft_bzero(env, sizeof(t_env));
  exit(0);
}

static void	zoom(int x, int y, t_envthread *e)
{
	e->x.y = (x / e->zoom + e->x.y) - (x / (e->zoom * 1.3));
	e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom * 1.3));
	e->zoom *= 1.3;
	e->it_max++;
}

static void	dezoom(int x, int y, t_envthread *e)
{
	e->x.y = (x / e->zoom + e->x.y)  - (x / (e->zoom / 1.3));
	e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom / 1.3));
	e->zoom /= 1.3;
	e->it_max--;
}

//produit en croix

static void is_event(t_env *env)
{
  int i;

  i = 0;
  if (env->move.x == 1 && env->julia == 1)
  {
    while (i < THREADS)
    {
      env->e_thread[i][0].c_r += 0.001f;
      env->e_thread[i][0].c_i += 0.001f;
      i++;
    }
  }
  if (env->move.y == 1 && env->julia == 1)
  {
    while (i < THREADS)
    {
      env->e_thread[i][0].c_r -= 0.001f;
      env->e_thread[i][0].c_i -= 0.001f;
      i++;
    }
  }
}

int   mouse_event(int code, int x, int y, void *param)
{
  t_env *env;
  int   i;

  env = (t_env *)param;
  i = 0;
  if (code == 4 || code == 1)
  {
    while (i < THREADS)
    {
      zoom(x, y, &env->e_thread[i][0]);
      i++;
    }
  }
	else if (code == 5 || code == 2)
  {
    while (i < THREADS)
    {
      dezoom(x, y, &env->e_thread[i][0]);
      i++;
    }
  }
  fractal(env);
  return (SUCCESS);
}

int		key_press(int key, void *param)
{
  t_env *env;

  env = (t_env *)param;
  if (key == ESC)
    win_close(env);
  if (key == MORE)
    env->move.x = 1;
  if (key == LESS)
    env->move.y = 1;
  is_event(env);
  fractal(env);
  return (SUCCESS);
}

int		key_release(int key, void *param)
{
  t_env *env;

  env = (t_env *)param;
  if (key == MORE)
    env->move.x = 0;
  if (key == LESS)
    env->move.y = 0;
  return (SUCCESS);
}
