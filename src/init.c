#include "../includes/fractol.h"

t_env *init_mandelbrot(t_env *env)
{
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  env->x1 = -2.1f;
  env->x2 = 0.6f;
  env->y1 = -1.2f;
  env->y2 = 1.2f;
  env->zoom = 200;
  env->iteration_max = 50;
  return (env);
}

t_env *init_julia(t_env *env)
{
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  env->x1 = -1.0f;
  env->x2 = 1.0f;
  env->y1 = -1.2f;
  env->y2 = 1.2f;
  env->zoom = 200;
  env->iteration_max = 200;
  return (env);
}
