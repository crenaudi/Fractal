#include "../includes/fractol.h"

void	legend(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 30, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 60, 0x999999, "(mouse)");
	if (env->julia == 1)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 100, 0xFFFFFFF, "CHANGE :");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 130, 0x999999, "<- / ->");
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
