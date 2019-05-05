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

int   mouse_event(int code, int x, int y, void *param)
{
  t_env *env;
  int   i;

  env = (t_env *)param;
  i = -1;
  if (code == 4 || code == 1)
  {
    while (++i < THREADS)
      zoom(x, y, env->e_thread[i]);
  }
	else if (code == 5 || code == 2)
  {
    while (++i < THREADS)
      dezoom(x, y, env->e_thread[i]);
  }
  fractal(env);
  return (SUCCESS);
}
