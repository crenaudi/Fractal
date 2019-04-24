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
