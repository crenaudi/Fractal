#include "../includes/fractol.h"



void mandelbrot(t_envthread *e, int i, float y)
{
    float tmp;

    e->c_r = e->x / e->zoom + e->x1;
    e->c_i = y / e->zoom + e->y1;
    e->z_r = 0;
    e->z_i = 0;
    while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && i < e->iteration_max)
    {
      tmp = e->z_r;
      e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
      e->z_i = 2 * e->z_i * tmp + e->c_i;
      i = i + 1;
    }
    if (i == e->iteration_max)
    {
      mlx_pixel_put(e->mlx_ptr_cpy, e->win_ptr_cpy,
        (e->x - (int)(e->x_img / 2)) + (WIDTH / 2),
        (y - (int)(e->y_img / 2)) + (HEIGHT / 2), 0xFFFFFFF);
    }
    else
    {
      mlx_pixel_put(e->mlx_ptr_cpy, e->win_ptr_cpy,
        (e->x - (int)(e->x_img / 2)) + (WIDTH / 2),
        (y - (int)(e->y_img / 2)) + (HEIGHT / 2),
        lerp_non_init_color(0x000000, 0x5588BB, i / e->iteration_max));
    }
}

void julia(t_envthread *e, int i, float y)
{
    float tmp;

    e->c_r = 0.285;
    e->c_i = 0.1;
    e->z_r = e->x / e->zoom + e->x1;
    e->z_i = y / e->zoom + e->y1;
    while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && i < e->iteration_max)
    {
      tmp = e->z_r;
      e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
      e->z_i = 2 * e->z_i * tmp + e->c_i;
      i = i + 1;
    }
    if (i == e->iteration_max)
    {
      mlx_pixel_put(e->mlx_ptr_cpy, e->win_ptr_cpy,
        (e->x - (int)(e->x_img / 2)) + (WIDTH / 2),
        (y - (int)(e->y_img / 2)) + (HEIGHT / 2), 0xFFFFFFF);
    }
    else
    {
      mlx_pixel_put(e->mlx_ptr_cpy, e->win_ptr_cpy,
        (e->x - (int)(e->x_img / 2)) + (WIDTH / 2),
        (y - (int)(e->y_img / 2)) + (HEIGHT / 2),
        lerp_non_init_color(0x000000, 0x5588BB, i / e->iteration_max));
    }
}

void *open_thread(void *param)
{
  float y;
  t_envthread *e;

  e = (t_envthread *)param;
  y = 0.f;
  while (y < e->y_img)
  {
      if (e->fractal.y == 1)
        julia(e, 0, y);
      if (e->fractal.x == 1)
        mandelbrot(e, 0, y);
      y++;
  }
  pthread_exit(NULL);
}

int fractal(t_env *env)
{
    float x;
    t_vec3 part;
    pthread_t *thread;

    //is_event(env);
    if (!(thread = (pthread_t *)malloc(sizeof(pthread_t) * 4)))
      return (ERROR);
    part.x = env->y_img / 4;
    part.y = part.x * 2;
    part.z = part.x * 3;
    x = 0.f;
    while (x < env->x_img)
    {
      if (x < part.x)
      {
        env->e_thread1->x = x;
        if (pthread_create(&thread[0], NULL, open_thread, (void *)env->e_thread1))
          return (EXIT_FAILURE);
        if (pthread_join(thread[0], NULL))
          return EXIT_FAILURE;
      }
      if (x > part.x && x < part.y)
      {
        env->e_thread2->x = x;
        if (pthread_create(&thread[1], NULL, open_thread, (void *)env->e_thread2))
          return (EXIT_FAILURE);
        if (pthread_join(thread[1], NULL))
          return EXIT_FAILURE;
      }
      if (x > part.y && x < part.z)
      {
        env->e_thread3->x = x;
        if (pthread_create(&thread[2], NULL, open_thread, (void *)env->e_thread3))
          return (EXIT_FAILURE);
        if (pthread_join(thread[2], NULL))
          return EXIT_FAILURE;
      }
      if (x > part.z && x < env->x_img)
      {
        env->e_thread4->x = x;
        if (pthread_create(&thread[3], NULL, open_thread, (void *)env->e_thread4))
          return (EXIT_FAILURE);
        if (pthread_join(thread[3], NULL))
          return EXIT_FAILURE;
      }
      x++;
    }
    return (SUCCESS);
}
