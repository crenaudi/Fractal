#include "../includes/fractol.h"
/*
static void		clean_t(t_point **tab)
{
  int x;
  int	y;

	y = -1;
	while (++y < 100)
	{
    x = -1;
    while (++x < 100)
		  free(&tab[y][x]);
	}
	free(tab);
}
*/
void make_fdf(t_img *img)
{
  t_point **tab;
  t_point *nb;
  int x;
  int y;

  x = HEIGHT / 4;
  if (!(tab = (t_point **)malloc(sizeof(t_point *) * (HEIGHT / 2))))
    return ;
  while (++x < HEIGHT / 2)
  {
    y = WIDTH / 4;
    if (!(nb = (t_point *)malloc(sizeof(t_point) * (WIDTH / 2))))
      return ;
    while (++y < WIDTH / 2)
    {
      nb[y].x = (float)(x);
      nb[y].y = (float)(y);
      nb[y].z = (img->data[y + x * WIDTH] == 0) ? 5 : 0;
      img->data++;
    }
    tab[x] = nb;
  }
  ft_putendl("avt");
  fdf(tab, 275, 537);
  free(tab);
}
