#include "../includes/fractol.h"

static void	zoom(int xx, int yy, t_envthread *e)
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

static void	dezoom(int xx, int yy, t_envthread *e)
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

static void modif_fractal(t_env *env, int nb_fractal)
{
  int i;
	int hsl;

  i = -1;
	if (env->color == 0)
		hsl = 180.0f;
	if (env->color == 1)
		hsl = 0.0f;
	if (env->color == 2)
		hsl = 80.0f;
  while (++i < THREADS)
	{
    env->e_thread[i]->fractal = nb_fractal;
		if (nb_fractal == 1)
      init_thread_mandelbrot(env->e_thread[i], hsl);
    if (nb_fractal == 2)
      init_thread_julia(env->e_thread[i], hsl);
    if (nb_fractal == 3)
      init_thread_burning(env->e_thread[i], hsl);
    if (nb_fractal == 4)
      init_thread_celtic(env->e_thread[i], hsl);
    if (nb_fractal == 5)
      init_thread_mandelbar(env->e_thread[i], hsl);
    if (nb_fractal == 6)
      init_thread_buddabrot(env->e_thread[i], hsl);
		}
}

int   mouse_event(int code, int x, int y, void *param)
{
  t_env *env;
  int   i;

	env = (t_env *)param;
  i = -1;
  if (x > 200 && (code == 4 || code == 1))
  {
    while (++i < THREADS)
      zoom(x, y, env->e_thread[i]);
  }
	else if (code == 5 || code == 2)
  {
    while (++i < THREADS)
      dezoom(x, y, env->e_thread[i]);
  }
	if (x > 40 && x < 100)
	{
		if (y > 305 && y < 325)
		{
			env->color = 0;
			change_color(85, env);
		}
		if (y > 265 && y < 285)
		{
			env->color = 1;
			change_color(83, env);
		}
		if (y > 285 && y < 305)
		{
			env->color = 2;
			change_color(84, env);
		}
		if (y > 380 && y < 400)
			modif_fractal(env, 1);
		if (y > 402 && y < 420)
			modif_fractal(env, 2);
		if (y > 424 && y < 445)
			modif_fractal(env, 3);
		if (y > 446 && y < 465)
			modif_fractal(env, 4);
		if (y > 468 && y < 490)
			modif_fractal(env, 5);
  }
  fractal(env);
  return (SUCCESS);
}

int   mouse_release(int code, int x, int y, void *param)
{
  t_env *env;

  env = (t_env *)param;
	(void)code;
	(void)x;
	(void)y;
  return (SUCCESS);
}
