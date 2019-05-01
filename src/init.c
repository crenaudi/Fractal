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

int **do_tab_px(int y)
{
  int     x;
  int     **px;
  int     *pixel;

  if (!(px = (int **)malloc(sizeof(int *) * WIDTH)))
      return (0);
  while (y++ < WIDTH)
  {
    if (!(pixel = (int *)malloc(sizeof(int) * HEIGHT)))
        return (0);
    x = -1;
    while (x++ > 0)
      pixel[x] = 0;
    px[y] = pixel;
  }
  return (px);
}

t_budd *do_tab(void)
{
  t_budd  *tab_px;

  if (!(tab_px = (t_budd *)malloc(sizeof(t_budd))))
    return (0);
  tab_px->px_r = do_tab_px(-1);
  tab_px->px_v = do_tab_px(-1);
  tab_px->px_b = do_tab_px(-1);
  tab_px->it.x = 20000;
  tab_px->it.y = 100000;
  tab_px->it.z = 1000000;
  return ((void *)tab_px);
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
    {/*
      env->e_thread[i][0].fractal.x = 0;
      env->e_thread[i][0].fractal.z = 1;
      env->e_thread[i][0].param_sup = do_tab();*/
      env->e_thread[i]->fractal.x = 0;
      env->e_thread[i]->fractal.z = 1;
      env->e_thread[i]->param_sup = do_tab();
      i++;
    }
  }
  env->x_img = env->e_thread[1][0].x_img;
  env->y_img = env->e_thread[1][0].y_img;
  return (env);
}
