#include "../includes/fractol.h"

void	legend(t_env *env)
{
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->txt_box->ptr, 10, 10);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 40, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 40, 70, 0x999999, "(mouse)");
	if (env->julia == 1)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 110, 0xFFFFFFF, "CHANGE :");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 40, 140, 0x999999, "<- / ->");
	}
}

void	is_error(int i)
{
	if (i == 3)
	{
		ft_putstr("NOT A VALID FILE\n");
		exit(0);
	}
	if (i == 1)
		exit(EXIT_FAILURE);
	if (i == 0)
		exit(EXIT_SUCCESS);
}
