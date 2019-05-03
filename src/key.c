#include "../includes/fractol.h"

static void	zoom(int x, int y, t_envthread *e)
{
	e->x.y = (x / e->zoom + e->x.y) - (x / (e->zoom * 1.3));
  e->x.z = (x / e->zoom + e->x.z) + (x / (e->zoom * 1.3));
	e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom * 1.3));
  e->y2 = (y / e->zoom + e->y2) + (y / (e->zoom * 1.3));
	e->zoom *= 1.3;
	e->it_max++;

}

static void	dezoom(int x, int y, t_envthread *e)
{
	e->x.y = (x / e->zoom + e->x.y) - (x / (e->zoom / 1.3));
  e->x.z = (x / e->zoom + e->x.z) + (x / (e->zoom / 1.3));
	e->y1 = (y / e->zoom + e->y1) - (y / (e->zoom / 1.3));
  e->y2 = (y / e->zoom + e->y2) + (y / (e->zoom / 1.3));
	e->zoom /= 1.3;
	e->it_max--;
}
//produit en croix

static void julia_move(t_env *env)
{
  int i;

  i = 0;
  if (env->move.x == 1)
  {
    while (i < THREADS)
    {
      env->e_thread[i]->c_r += 0.001f;
      env->e_thread[i]->c_i += 0.001f;
      i++;
    }
  }
  if (env->move.y == 1)
  {
    while (i < THREADS)
    {
      env->e_thread[i]->c_r -= 0.001f;
      env->e_thread[i]->c_i -= 0.001f;
      i++;
    }
  }
}

static void change_color(t_env *env)
{
  int i;

  i = -1;
  if (env->color == 1)
    while (++i < THREADS)
      env->e_thread[i]->HSL = 0.0f;
  else if (env->color == 2)
    while (++i < THREADS)
      env->e_thread[i]->HSL = 80.0f;
  else if (env->color == 0)
    while (++i < THREADS)
      env->e_thread[i]->HSL = 180.0f;
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
      zoom(x, y, env->e_thread[i]);
      i++;
    }
  }
	else if (code == 5 || code == 2)
  {
    while (i < THREADS)
    {
      dezoom(x, y, env->e_thread[i]);
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
  if (key == RED)
    env->color = 1;
  if (key == GREEN)
    env->color = 2;
  if (key == BLUE)
    env->color = 0;
  change_color(env);
  if (env->julia == 1)
    julia_move(env);
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
