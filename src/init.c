#include "../includes/fractol.h"

void init_thread_mandelbrot(t_envthread *thrd, float hsl)
{
  thrd->x1 = -3.5f;
  thrd->y1 = -1.3f;
  thrd->zoom = 210;
  thrd->it_max = 90;
  thrd->fractal = 1;
  thrd->HSL = hsl;
}

void init_thread_julia(t_envthread *thrd, float hsl)
{
  thrd->x1 = -3.0f;
  thrd->y1 = -1.4f;
  thrd->zoom = 200;
  thrd->it_max = 210;
  thrd->fractal = 2;
  thrd->c_r = 0.285f;
  thrd->c_i = 0.01f;
  thrd->HSL = hsl;
}

void init_thread_burning(t_envthread *thrd, float hsl)
{
  thrd->x1 = -3.5f;
  thrd->y1 = -2.0f;
  thrd->zoom = 200;
  thrd->it_max = 120;
  thrd->fractal = 3;
  thrd->HSL = hsl;
}

void init_thread_celtic(t_envthread *thrd, float hsl)
{
  thrd->x1 = -5.0f;
  thrd->y1 = -1.9f;
  thrd->zoom = 145;
  thrd->it_max = 120;
  thrd->fractal = 4;
  thrd->HSL = hsl;
}

void init_thread_mandelbar(t_envthread *thrd, float hsl)
{
  thrd->x1 = -4.5f;
  thrd->y1 = -1.9f;
  thrd->zoom = 145;
  thrd->it_max = 100;
  thrd->fractal = 5;
  thrd->HSL = hsl;
}

void init_thread_buddabrot(t_envthread *thrd, float hsl)
{
  thrd->x1 = -3.3f;
  thrd->y1 = -1.3f;
  thrd->zoom = 210;
  thrd->it_max = 90;
  thrd->fractal = 6;
  thrd->HSL = hsl;
}

t_env *init_fractal(t_env *env, int fractal, char *title)
{
  int     i;
  t_envthread *thrd;

  i = 0;
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, ft_strjoin("PROJET FRACTOL : ", title));
  env->img = init_img(env->mlx_ptr, HEIGHT, WIDTH);
	env->txt_box = do_div(env->mlx_ptr, 530, 200, 0x111122);
  if (!(env->e_thread = (t_envthread **)malloc(sizeof(t_envthread *) * THREADS)))
    return (NULL);
  while (i < THREADS)
  {
    if (!(thrd = (t_envthread *)malloc(sizeof(t_envthread))))
      return (NULL);
    ft_bzero(thrd, sizeof(t_envthread));
    if (fractal == 1)
      init_thread_mandelbrot(thrd, 180.0f);
    if (fractal == 2)
      init_thread_julia(thrd, 180.0f);
    if (fractal == 3)
      init_thread_burning(thrd, 180.0f);
    if (fractal == 4)
      init_thread_celtic(thrd, 180.0f);
    if (fractal == 5)
      init_thread_mandelbar(thrd, 180.0f);
    if (fractal == 6)
      init_thread_buddabrot(thrd, 180.0f);
    thrd->data = env->img->data;
    env->e_thread[i] = thrd;
    i++;
  }
  return (env);
}
