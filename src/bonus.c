#include "../includes/fractol.h"

static void create_img(t_img *img, int fd)
{
	int x;
	int y;
	const char *n;

  y = -1;
  while (++y < 900)
  {
    x = -1;
    while (++x < 520)
    {
			if (img->data[y + x * WIDTH] != 0)
			{
				n = ft_itoa((img->data[y + x * WIDTH] / 100000));
				write(fd, n, ft_strlen(n));
			}
			else
			 	write(fd, "0", 1);
			if (x < 520)
				write(fd, " ", 1);
    }
		write(fd, "\n", 1);
  }
}

void		do_fd(t_env *env)
{
	int			fd;
	char		*name;

	name = "fractol.fdf";
	if ((fd = open(name, O_WRONLY | O_CREAT, S_IRWXO)) == -1)
		return ;
	create_img(env->img, fd);
	close(fd) == -1 ? is_error(ERROR) : 0;
}
