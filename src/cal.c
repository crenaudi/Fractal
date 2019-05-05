#include "../includes/fractol.h"

void mandelbrot(t_envthread *e, int i, float y)
{
    float tmp;

    e->c_r = e->x / e->zoom + e->x1;
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
		color_px(e, i, y, 0x000000);
}

void julia(t_envthread *e, int i, float y)
{
		float   c_r;
		float   c_i;
    float 	tmp;

    c_r = e->c_r;
    c_i = e->c_i;
    e->z_r = e->x / e->zoom + e->x1;
    e->z_i = y / e->zoom + e->y1;
    while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && i < e->it_max)
    {
      tmp = e->z_r;
      e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
      e->z_i = 2 * e->z_i * tmp + e->c_i;
      i = i + 1;
    }
    color_px(e, i, y, 0xFFFFFF);
}

void burning_ship(t_envthread *e, int i, float y)
{
    float tmp;

    e->c_r = e->x / e->zoom + e->x1;
    e->c_i = y / e->zoom + e->y1;
    e->z_r = 0;
    e->z_i = 0;
    while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && i < e->it_max)
    {
      tmp = e->z_r;
      e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
      e->z_i = 2 * fabs(e->z_i) * fabs(tmp) + e->c_i;
			i = i + 1;
    }
		color_px(e, i, y, 0x000000);
}
