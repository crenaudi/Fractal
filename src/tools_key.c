#include "../includes/fractol.h"

static void julia_move(t_env *env)
{
  int i;

  i = -1;
  if (env->move.x == 1)
  {
    while (++i < THREADS)
    {
      env->e_thread[i]->c_r += 0.0001f;
      env->e_thread[i]->c_i += 0.0001f;
    }
  }
  if (env->move.y == 1)
  {
    while (++i < THREADS)
    {
      env->e_thread[i]->c_r -= 0.0001f;
      env->e_thread[i]->c_i -= 0.0001f;
    }
  }
}

static void change_color(int key, t_env *env)
{
  int i;

  i = -1;
	if (key == RED)
    env->color = 1;
  if (key == GREEN)
    env->color = 2;
  if (key == BLUE)
    env->color = 0;
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

static void is_move(t_env *env)
{
  int i;

  i = -1;
  if (env->abscisse.x == 1)
    while (++i < THREADS)
      env->e_thread[i]->x1 -= 0.02f;

  if (env->abscisse.y == 1)
    while (++i < THREADS)
      env->e_thread[i]->x1 += 0.02f;

	if (env->ordonne.x == 1)
		while (++i < THREADS)
		  env->e_thread[i]->y1 += 0.02f;

	if (env->ordonne.y == 1)
		while (++i < THREADS)
			env->e_thread[i]->y1 -= 0.02f;
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
	if (key == RIGHT)
	  env->abscisse.x = 1;
	if (key == LEFT)
	  env->abscisse.y = 1;
	if (key == TOP)
		env->ordonne.x = 1;
	if (key == BOTTOM)
		env->ordonne.y = 1;
	if (key == FDF)
		make_fdf(env->img);
  change_color(key, env);
	is_move(env);
  if (env->e_thread[1]->fractal == 2)
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
	if (key == RIGHT)
		env->abscisse.x = 0;
	if (key == LEFT)
		env->abscisse.y = 0;
	if (key == TOP)
		env->ordonne.x = 0;
	if (key == BOTTOM)
		env->ordonne.y = 0;
  return (SUCCESS);
}
