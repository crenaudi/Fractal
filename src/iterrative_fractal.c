#include "../includes/fractol.h"

static void		px(int *data, int x, int y, int color)
{
	int		index;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		index = x + y * WIDTH;
		if (index < 0 || index >= HEIGHT * WIDTH)
			return ;
		data[index] = color;
	}
}

void mandelbrot(t_envthread *e, int i, float y)
{
    float tmp;

    e->c_r = e->x.x / e->zoom + e->x.y;
    e->c_i = y / e->zoom + e->y1;
    e->z_r = 0;
    e->z_i = 0;
    while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && i < e->it_max)
    {
      tmp = e->z_r;
      e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
      e->z_i = 2 * e->z_i * tmp + e->c_i;
      i = i + 1;
    }
    if (i == e->it_max)
        px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
          (y - (int)(e->y_img / 2)) + M_HHT, 0x000000);
    else
        px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
          (y - (int)(e->y_img / 2)) + M_HHT,
          lerp_non_init_color(0x110022, 0xDDBB77, i / e->it_max));
}

void julia(t_envthread *e, int i, float y)
{
		float   c_r;
		float   c_i;
    float 	tmp;

    c_r = e->c_r;
    c_i = e->c_i;
    e->z_r = e->x.x / e->zoom + e->x.y;
    e->z_i = y / e->zoom + e->y1;
    while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && i < e->it_max)
    {
      tmp = e->z_r;
      e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
      e->z_i = 2 * e->z_i * tmp + e->c_i;
      i = i + 1;
    }
    if (i == e->it_max)
			px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
          (y - (int)(e->y_img / 2)) + M_HHT, 0x000000);
    else
        px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
          (y - (int)(e->y_img / 2)) + M_HHT,
          lerp_non_init_color(0x001122, 0x77AADD, i / e->it_max));
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
    int       i;
    float     x;
    float     part;
    pthread_t *thread;

    ft_bzero(env->img->data, WIDTH * HEIGHT * (env->img->bpp / 8));
    if (!(thread = (pthread_t *)malloc(sizeof(pthread_t) * THREADS)))
      return (ERROR);
    part = env->y_img / THREADS;
    x = -1.f;
    i = 0;
    while (x++ < env->x_img)
    {
      env->e_thread[i]->x.x = x;
      if (pthread_create(&thread[i], NULL, open_thread, (void *)env->e_thread[i]))
        return (EXIT_FAILURE);
      if (pthread_join(thread[i], NULL))
        return EXIT_FAILURE;
      if (x == part && part <= WIDTH && i++)
        part += part;
    }
    mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->ptr, 0, 0);
		legend(env);
    return (SUCCESS);
}
