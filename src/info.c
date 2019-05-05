#include "../includes/fractol.h"

void	legend(t_env *env, int fractal)
{
	int color;

	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->txt_box->ptr, 10, 10);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 40, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 40, 70, 0x999999, "(mouse)");
	if (env->e_thread[1]->fractal == 2)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 110, 0xFFFFFFF, "CHANGE :");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 40, 140, 0x999999, "<- / ->");
	}
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 210, 0x6655FF,
		"----------------");
	color = (env->color == 1) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 245, color, "RED <-");
	color = (env->color == 2) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 265, color, "GREEN <-");
	color = (env->color == 0) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 285, color, "BLUE <-");
	color = (fractal == 1) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 325, color, "-> Mandelbrot");
	color = (fractal == 2) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 346, color, "-> Julia");
	color = (fractal == 3) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 367, color, "-> Burning ship");
	color = (fractal == 4) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 388, color, "-> Celtic");
	color = (fractal == 5) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 409, color, "-> Mandelbar");
}

void	is_error(int i)
{
	if (i == 3)
	{
		ft_putendl("[INVALID]");
		ft_putendl("Entrer paramètre parmis ceux qui suivent :\n");
		ft_putendl("-M pour Mandelbrot");
		ft_putendl("-J pour Julia");
		ft_putendl("-BS pour Burning Ship");
		ft_putendl("-C pour Celtic");
		ft_putendl("-MD pour Mandelbar");
		exit(0);
	}
	if (i == 1)
		exit(EXIT_FAILURE);
	if (i == 0)
		exit(EXIT_SUCCESS);
}
