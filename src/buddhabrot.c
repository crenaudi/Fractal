#include "../includes/fractol.h"

int **do_tab_px(int y)
{
  int     x;
  int     **px;
  int     *pixel;

  if (!(px = (int **)malloc(sizeof(int *) * WIDTH)))
      return (0);
  while (++y < WIDTH)
  {
    if (!(pixel = (int *)malloc(sizeof(int) * HEIGHT)))
        return (0);
    x = -1;
    while (++x < HEIGHT)
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

void compil(t_env *env, int n)
{
	int *pixel;
  int x;
  int y;
	int i;

  ft_putendl("dbt compil");
	y = -1;
	if (!(pixel = (int *)malloc(sizeof(int) * (WIDTH * HEIGHT))))
		return ;
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			i = -1;
			while (++i < THREADS)
      {
        pixel[n] = ((t_budd *)(env->e_thread[i]->param_sup))->px_r[y][x];
        ft_putnbr(n);
      }
      ft_putendl("j'imprime");
			put_px(env->img->data, (x - (int)(env->x_img / 2)) + M_WTH,
				(y - (int)(env->y_img / 2)) + M_HHT,
					lerp_non_init_color(0x000000, 0xFFFFFFF,
						(float)((pixel[n] > 255) ? 255 : pixel[n]) / 255));
      n++;
		}
	}
	free(pixel);
  ft_putendl("fin compil");
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
