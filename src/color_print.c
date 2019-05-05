#include "../includes/fractol.h"

void	put_px(int *data, int x, int y, int color)
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

void   color_px(t_envthread *e, float i, float y, int color)
{
  t_vec3	n;

  if (i == e->it_max)
    put_px(e->data, (int)(e->x.x), (int)(y), color);
  else
  {
    n.x = log(e->z_r * e->z_r + e->z_i * e->z_i) / 2;
    n.y = log(n.x / log(2)) / log(2);
    n.z = i + 1 - n.y;
    i = n.z;
    put_px(e->data, (int)(e->x.x), (int)(y),
      lerp_non_init_color(HSLtorgb(e->HSL + n.z, 0.572f, 0.375f),
      HSLtorgb(181.0f + n.z, 0.472f, 0.275f), i / e->it_max));
  }
}
