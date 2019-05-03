#include "../includes/fractol.h"

static void init_thread_mandelbrot(t_envthread *thrd)
{
  thrd->x.y = -4.1f;
  thrd->x.z = 2.6f;
  thrd->y1 = -2.2f;
  thrd->y2 = 2.2f;
  thrd->zoom = 200;
  thrd->it_max = 100;
  thrd->fractal = 1;
  thrd->HSL = 180.0f;
  thrd->x_img = ((thrd->x.z - thrd->x.y) * thrd->zoom);
  thrd->y_img = ((thrd->y2 - thrd->y1) * thrd->zoom);
}

static void init_thread_julia(t_envthread *thrd)
{
  thrd->x.y = -3.0f;
  thrd->x.z = 3.0f;
  thrd->y1 = -2.2f;
  thrd->y2 = 2.2f;
  thrd->zoom = 200;
  thrd->it_max = 300;
  thrd->fractal = 2;
  thrd->c_r = 0.285f;
  thrd->c_i = 0.01f;
  thrd->HSL = 180.0f;
  thrd->x_img = ((thrd->x.z - thrd->x.y) * thrd->zoom);
  thrd->y_img = ((thrd->y2 - thrd->y1) * thrd->zoom);
}

static void init_thread_burning(t_envthread *thrd)
{
  thrd->x.y = -3.5f;
  thrd->x.z = 2.0f;
  thrd->y1 = -2.5f;
  thrd->y2 = 1.5f;
  thrd->zoom = 200;
  thrd->it_max = 400;
  thrd->fractal = 3;
  thrd->HSL = 180.0f;
  thrd->x_img = ((thrd->x.z - thrd->x.y) * thrd->zoom);
  thrd->y_img = ((thrd->y2 - thrd->y1) * thrd->zoom);
}

static void init_thread_buddabrot(t_envthread *thrd)
{
  thrd->x.y = -4.1f;
  thrd->x.z = 2.6f;
  thrd->y1 = -2.2f;
  thrd->y2 = 2.2f;
  thrd->zoom = 200;
  thrd->it_max = 50;
  thrd->fractal = 4;
  thrd->HSL = 180.0f;
  thrd->x_img = ((thrd->x.z - thrd->x.y) * thrd->zoom);
  thrd->y_img = ((thrd->y2 - thrd->y1) * thrd->zoom);
  thrd->param_sup = do_tab();
}

t_env *init_fractal(t_env *env, int fractal)
{
  int     i;
  t_envthread *thrd;

  i = 0;
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  env->img = init_img(env->mlx_ptr, HEIGHT, WIDTH);
	env->txt_box = do_div(env->mlx_ptr, 255, 200, 0x111122);
  if (!(env->e_thread = (t_envthread **)malloc(sizeof(t_envthread *) * THREADS)))
    return (NULL);
  while (i < THREADS)
  {
    if (!(thrd = (t_envthread *)malloc(sizeof(t_envthread))))
      return (NULL);
    ft_bzero(thrd, sizeof(t_envthread));
    if (fractal == 1)
      init_thread_mandelbrot(thrd);
    if (fractal == 2)
    {
      init_thread_julia(thrd);
      env->julia = 1;
    }
    if (fractal == 3)
      init_thread_burning(thrd);
    if (fractal == 4)
      init_thread_buddabrot(thrd);
    thrd->data = env->img->data;
    env->e_thread[i] = thrd;
    i++;
  }
  env->x_img = env->e_thread[1]->x_img;
  env->y_img = env->e_thread[1]->y_img;
  return (env);
}
