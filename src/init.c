#include "../includes/fractol.h"
/*
void is_event(t_env *env)
{
  if (env->scale.x == 1)
    env->zoom += 10.0f;
  if (env->scale.x == 1)
    env->zoom -= 10.0f;
}
*/
static t_envthread *init_thread_mandelbrot(t_env *env)
{
  t_envthread *content;

  if (!(content = (t_envthread *)malloc(sizeof(t_envthread))))
    return (NULL);
  ft_bzero(content, sizeof(t_envthread));
  content->mlx_ptr_cpy = env->mlx_ptr;
  content->win_ptr_cpy = env->win_ptr;
  content->x1 = -2.1f;
  content->x2 = 0.6f;
  content->y1 = -1.2f;
  content->y2 = 1.2f;
  content->zoom = 200;
  content->iteration_max = 50;
  content->fractal.x = 1;
  content->x_img = ((content->x2 - content->x1) * content->zoom);
  content->y_img = ((content->y2 - content->y1) * content->zoom);
  return (content);
}

static t_envthread *init_thread_julia(t_env *env)
{
  t_envthread *content;

  if (!(content = (t_envthread *)malloc(sizeof(t_envthread))))
    return (NULL);
  ft_bzero(content, sizeof(t_envthread));
  content->mlx_ptr_cpy = env->mlx_ptr;
  content->win_ptr_cpy = env->win_ptr;
  content->x1 = -1.0f;
  content->x2 = 1.0f;
  content->y1 = -1.2f;
  content->y2 = 1.2f;
  content->zoom = 200;
  content->iteration_max = 200;
  content->fractal.y = 1;
  content->x_img = ((content->x2 - content->x1) * content->zoom);
  content->y_img = ((content->y2 - content->y1) * content->zoom);
  return (content);
}

t_env *init_mandelbrot(t_env *env)
{
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  env->e_thread1 = init_thread_mandelbrot(env);
  env->e_thread2 = init_thread_mandelbrot(env);
  env->e_thread3 = init_thread_mandelbrot(env);
  env->e_thread4 = init_thread_mandelbrot(env);
  env->x_img = env->e_thread1->x_img;
  env->y_img = env->e_thread1->y_img;
  return (env);
}

t_env *init_julia(t_env *env)
{
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  env->e_thread1 = init_thread_julia(env);
  env->e_thread2 = init_thread_julia(env);
  env->e_thread3 = init_thread_julia(env);
  env->e_thread4 = init_thread_julia(env);
  env->x_img = env->e_thread1->x_img;
  env->y_img = env->e_thread1->y_img;
  return (env);
}
