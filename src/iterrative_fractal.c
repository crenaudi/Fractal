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
		t_vec3 n;

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
		{
			n.x = log(e->z_r * e->z_r + e->z_i * e->z_i) / 2;
    	n.y = log(n.x / log(2)) / log(2);
    	n.z = i + 1 - n.y;
			i = n.z;
			px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
				(y - (int)(e->y_img / 2)) + M_HHT,
				lerp_non_init_color(HSLtorgb(190.0f + n.z, 0.472f, 0.275f),
				HSLtorgb(191.0f + n.z, 0.472f, 0.275f), i % 1));
			/*i = i - log(log(ft_sqrt(e->z_r * e->z_r + e->z_i * e->z_i))) / log(2);
			px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
				(y - (int)(e->y_img / 2)) + M_HHT, ((N_COLORS - 1) * i) / e->it_max);*/
		}
}

void julia(t_envthread *e, int i, float y)
{
		float   c_r;
		float   c_i;
    float 	tmp;
		t_vec3	n;

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
          (y - (int)(e->y_img / 2)) + M_HHT, 0xFFFFFF);
    else
		{
			n.x = log(e->z_r * e->z_r + e->z_i * e->z_i) / 2;
    	n.y = log(n.x / log(2)) / log(2);
    	n.z = i + 1 - n.y;
			i = n.z;
			px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
				(y - (int)(e->y_img / 2)) + M_HHT,
				lerp_non_init_color(HSLtorgb(180.0f + n.z, 0.472f, 0.275f),
				HSLtorgb(181.0f + n.z, 0.472f, 0.275f), i % 1));
			}
		/*
			px(e->data, (e->x.x - (int)(e->x_img / 2)) + M_WTH,
				(y - (int)(e->y_img / 2)) + M_HHT,
				lerp_non_init_color(0x110022, 0xDDBB77, i / e->it_max));*/
}

void buddhabrot(t_envthread *e, int i, float y)
{
    float 	tmp;
		t_budd 	*budd;
		t_vec2 	*tmp_pixels;
		int j;

		budd = (t_budd *)e->param_sup;
		if (!(tmp_pixels = (t_vec2 *)malloc(sizeof(t_vec2) * (WIDTH * HEIGHT))))
			return;
    e->c_r = e->x.x / e->zoom + e->x.y;
    e->c_i = y / e->zoom + e->y1;
    e->z_r = 0;
    e->z_i = 0;
    while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && i < e->it_max)
    {
      tmp = e->z_r;
      e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
      e->z_i = 2 * e->z_i * tmp + e->c_i;
			tmp_pixels[i].y = (int)((e->z_i - e->y1) * e->zoom);
			tmp_pixels[i].x = (int)((e->z_r - e->x.y) * e->zoom);
      i = i + 1;
    }
		if (i != e->it_max)
		{
			j = 0;
			if (j < i)
			{
				if (tmp_pixels[j].x >= 0 && tmp_pixels[j].x < WIDTH
					&& tmp_pixels[j].y >= 0 && tmp_pixels[j].y < HEIGHT)
							budd->px_r[tmp_pixels[j].x][tmp_pixels[j].y]++;
			}
    }
		free(tmp_pixels);
}

void compil(t_env *env, int n, int y)
{
  int x;
	int i;
	int *pixel;

	y = -1;
	n = 0;
	ft_putendl("hello");
	if (!(pixel = (int *)malloc(sizeof(int) * (WIDTH * HEIGHT))))
		return ;
	while (y++ < WIDTH)
	{
		x = -1;
		while (x++ < HEIGHT)
		{
			i = -1;
			while (i++ < THREADS)
				pixel[n++] = ((t_budd *)(env->e_thread[i]->param_sup))->px_r[y][x];
			px(env->img->data, (x - (int)(env->x_img / 2)) + M_WTH,
				(y - (int)(env->y_img / 2)) + M_HHT,
					lerp_non_init_color(0x000000, 0xFFFFFFF,
						(float)((pixel[n] > 255) ? 255 : pixel[n]) / 255));
		}
	}
	free(pixel);
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
    else if (e->fractal.x == 1)
      mandelbrot(e, 0, y);
		else if (e->fractal.z == 1)
			buddhabrot(e, 0, y);
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
		if (env->e_thread[0]->fractal.z == 1)
			compil(env, 0, -1);
    mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->ptr, 0, 0);
		legend(env);
    return (SUCCESS);
}
