#include "../includes/fractol.h"

void is_event(t_env *env)
{
  if (env->scale.x == 1)
    env->zoom += 10.0f;
  if (env->scale.x == 1)
    env->zoom -= 10.0f;
}

void interative_fractal(t_env *env, int x, int y, int i)
{
  float tmp;

  while ((env->z_r * env->z_r + env->z_i * env->z_i) < 4 && i < env->iteration_max)
  {
    tmp = env->z_r;
    env->z_r = env->z_r * env->z_r - env->z_i * env->z_i + env->c_r;
    env->z_i = 2 * env->z_i * tmp + env->c_i;
    i = i + 1;
  }
  if (i == env->iteration_max)
  {
    mlx_pixel_put(env->mlx_ptr, env->win_ptr,
      (x - (int)(env->x_img / 2)) + (WIDTH / 2),
      (y - (int)(env->y_img / 2)) + (HEIGHT / 2), 0xFFFFFFF);
  }
  else
  {
    mlx_pixel_put(env->mlx_ptr, env->win_ptr,
      (x - (int)(env->x_img / 2)) + (WIDTH / 2),
      (y - (int)(env->y_img / 2)) + (HEIGHT / 2),
      lerp_non_init_color(0x000000, 0x5588BB, i / env->iteration_max));
  }
}

int mandelbrot(t_env *env)
{
    float x;
    float y;
    float i;

    is_event(env);
    env->x_img = ((env->x2 - env->x1) * env->zoom);
    env->y_img = ((env->y2 - env->y1) * env->zoom);
    x = 0.f;
    while (x < env->x_img)
    {
      y = 0.f;
      while (y < env->y_img)
      {
          env->c_r = x / env->zoom + env->x1;
          env->c_i = y / env->zoom + env->y1;
          env->z_r = 0;
          env->z_i = 0;
          i = 0;
          interative_fractal(env, x, y, i);
          y++;
      }
      x++;
    }
    return (SUCCESS);
}

int julia(t_env *env)
{
    float x;
    float y;
    float i;

    is_event(env);
    env->x_img = ((env->x2 - env->x1) * env->zoom);
    env->y_img = ((env->y2 - env->y1) * env->zoom);
    x = 0.f;
    while (x < env->x_img)
    {
      y = 0.f;
      while (y < env->y_img)
      {
          env->c_r = 0.285;
          env->c_i = 0.1;
          env->z_r = x / env->zoom + env->x1;
          env->z_i = y / env->zoom + env->y1;
          i = 0;
          interative_fractal(env , x, y, i);
          y++;
      }
      x++;
    }
    return (SUCCESS);
}
