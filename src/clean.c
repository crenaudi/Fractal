#include "../includes/fractol.h"

void		kill_ptr_img(t_env *env, t_img *div, int x, int y)
{
  ft_bzero(div->data, x * y * (div->bpp / 8));
	mlx_destroy_image(env->mlx_ptr, div->ptr);
	free(div);
}

void		kill_env_threads(t_envthread **thread)
{
  int i;

  i = -1;
  while (++i < THREADS)
  {
    ft_bzero(thread[i], sizeof(t_envthread));
    free(thread[i]);
  }
	free(thread);
}

void		  kill_env(t_env *env)
{
  kill_ptr_img(env, env->img, HEIGHT, WIDTH);
  kill_ptr_img(env, env->txt_box, 250, 200);
  kill_env_threads(env->e_thread);
}

void win_close(t_env *env)
{
  kill_env(env);
  mlx_destroy_window(env->mlx_ptr, env->win_ptr);
  ft_bzero(env, sizeof(t_env));
  exit(0);
}
