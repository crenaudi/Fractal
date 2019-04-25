#include "../includes/fractol.h"

static void init_thread_mandelbrot(t_env *env)
{
  int i;
  t_envthread **env_thread;
  t_envthread *content;

  i = 0;
  if (!(env_thread = (t_envthread **)malloc(sizeof(t_envthread *) * THREADS)))
    return ;
  while (i < THREADS)
  {
    if (!(content = (t_envthread *)malloc(sizeof(t_envthread))))
      return ;
    content->x.y = -4.1f;
    content->x.z = 2.6f;
    content->y1 = -2.2f;
    content->y2 = 2.2f;
    content->zoom = 200;
    content->it_max = 50;
    content->fractal.x = 1;
    content->x_img = ((content->x.z - content->x.y) * content->zoom);
    content->y_img = ((content->y2 - content->y1) * content->zoom);
    content->data = env->img->data;
    env_thread[i] = content;
    i++;
  }
  env->e_thread = env_thread;
}

static void init_thread_julia(t_env *env)
{
  int i;
  t_envthread **env_thread;
  t_envthread *content;

  i = 0;
  if (!(env_thread = (t_envthread **)malloc(sizeof(t_envthread *) * THREADS)))
    return ;
  while (i < THREADS)
  {
    if (!(content = (t_envthread *)malloc(sizeof(t_envthread))))
      return ;
    content->x.y = -3.0f;
    content->x.z = 3.0f;
    content->y1 = -2.2f;
    content->y2 = 2.2f;
    content->c_r = 0.285f;
    content->c_i = 0.01f;
    content->zoom = 200;
    content->it_max = 300;
    content->fractal.y = 1;
    content->x_img = ((content->x.z - content->x.y) * content->zoom);
    content->y_img = ((content->y2 - content->y1) * content->zoom);
    content->data = env->img->data;
    env_thread[i] = content;
    i++;
  }
  env->julia = 1;
  env->e_thread = env_thread;
}

t_env *init_fractal(t_env *env, int fractal)
{
  int i;

  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  env->img = init_img(env->mlx_ptr, HEIGHT, WIDTH);
  if (fractal == 1)
    init_thread_mandelbrot(env);
  if (fractal == 2)
    init_thread_julia(env);
  if (fractal == 3)
  {
    init_thread_mandelbrot(env);
    i = 0;
    while (i < THREADS)
    {
      env->e_thread[i][0].fractal.x = 0;
      env->e_thread[i][0].fractal.z = 1;
      i++;
    }
  }
  env->x_img = env->e_thread[1][0].x_img;
  env->y_img = env->e_thread[1][0].y_img;
  return (env);
}
