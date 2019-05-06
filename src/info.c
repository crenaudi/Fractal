#include "../includes/fractol.h"

static void	legend_suite(t_env *env, int fractal)
{
	int color;

	color = (env->color == 1) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 265, color, "RED <-");
	color = (env->color == 2) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 285, color, "GREEN <-");
	color = (env->color == 0) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 305, color, "BLUE <-");
	color = (fractal == 1) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 380, color, "-> Mandelbrot");
	color = (fractal == 2) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 402, color, "-> Julia");
	color = (fractal == 3) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 424, color, "-> Burning ship");
	color = (fractal == 4) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 446, color, "-> Celtic");
	color = (fractal == 5) ? 0x6655FF : 0x555566;
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 468, color, "-> Mandelbar");
}

void	legend(t_env *env, int fractal)
{
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->txt_box->ptr, 10, 10);
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 40, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 40, 70, 0x999999, "(mouse)");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 100, 0xFFFFFFF, "DEPLACEMENT :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 40, 130, 0x999999, "< v >");
	if (env->e_thread[1]->fractal == 2)
	{
		mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 160, 0xFFFFFFF, "CHANGE :");
		mlx_string_put(env->mlx_ptr, env->win_ptr, 40, 190, 0x999999, "<- / ->");
	}
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 245, 0x6655FF,
		"----------------");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 30, 358, 0x6655FF,
		"----------------");
	legend_suite(env, fractal);
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
