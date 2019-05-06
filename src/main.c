#include "../includes/fractol.h"

void *open_thread(void *param)
{
  float y;
  t_envthread *e;

  e = (t_envthread *)param;
  y = 0.f;
  while (y < HEIGHT)
  {
    if (e->fractal == 1)
      mandelbrot(e, 0, y);
    else if (e->fractal == 2)
      julia(e, 0, y);
		else if (e->fractal == 3)
			burning_ship(e, 0, y);
    else if (e->fractal == 4)
  		celtic(e, 0, y);
    else if (e->fractal == 5)
    	mandelbar(e, 0, y);
    y++;
  }
  pthread_exit(NULL);
}

int fractal(t_env *env)
{
    int       i;
    float     x;
    float     part;
    pthread_t *thread;

		i = 0;
    ft_bzero(env->img->data, WIDTH * HEIGHT * (env->img->bpp / 8));
    if (!(thread = (pthread_t *)malloc(sizeof(pthread_t) * THREADS)))
      return (ERROR);
    part = WIDTH / THREADS;
    x = -1.f;
    while (x++ < WIDTH)
    {
      env->e_thread[i]->x = x;
      if (pthread_create(&thread[i], NULL, open_thread, (void *)env->e_thread[i]))
        return (EXIT_FAILURE);
      if (pthread_join(thread[i], NULL))
        return EXIT_FAILURE;
      if (x == part && part <= WIDTH && i++)
        part += part;
    }
		if (env->e_thread[0]->fractal == 6)
			compil(env, 0);
    mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img->ptr, 0, 0);
		legend(env, env->e_thread[1]->fractal);
    return (SUCCESS);
}

int main(int argc, char **argv)
{
  t_env env;
  char *str[4] = {"Mandebrot","Julia","Burning Ship","Buddhabrot"};

  if (argc > 2)
  {
    ft_putendl("error : too much arguments.");
    return (0);
  }
  if (ft_strcmp(argv[1], "-M") == 0)
    fractal(init_fractal(&env, 1, str[0]));
  else if (ft_strcmp(argv[1], "-J") == 0)
    fractal(init_fractal(&env, 2, str[1]));
  else if (ft_strcmp(argv[1], "-BS") == 0)
    fractal(init_fractal(&env, 3, str[2]));
  else if (ft_strcmp(argv[1], "-C") == 0)
    fractal(init_fractal(&env, 4, str[3]));
  else if (ft_strcmp(argv[1], "-MD") == 0)
    fractal(init_fractal(&env, 5, str[3]));
  else
    is_error(3);
  mlx_hook(env.win_ptr, 4, 0, mouse_event, (void*)&env);
  mlx_hook(env.win_ptr, 5, 0, mouse_release, (void*)&env);
  mlx_hook(env.win_ptr, 2, 0, key_press, (void *)&env);
  mlx_hook(env.win_ptr, 3, 0, key_release, (void *)&env);
  mlx_loop(env.mlx_ptr);
  return (0);
}
