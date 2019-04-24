#include "../includes/fractol.h"

void	legend(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 20, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 40, 0x999999, "<- / ->");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0xFFFFFFF,
			"DISPLACEMENT :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 90, 0x999999,
			"W / A / S / D");
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
