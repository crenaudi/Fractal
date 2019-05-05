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
  		mandelbrot(e, 0, y);
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
      env->e_thread[i]->x.x = x;
      if (pthread_create(&thread[i], NULL, open_thread, (void *)env->e_thread[i]))
        return (EXIT_FAILURE);
      if (pthread_join(thread[i], NULL))
        return EXIT_FAILURE;
      if (x == part && part <= WIDTH && i++)
        part += part;
    }
		if (env->e_thread[0]->fractal == 4)
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
  else if (ft_strcmp(argv[1], "-B") == 0)
    fractal(init_fractal(&env, 4, str[3]));
  else
    is_error(3);
  mlx_hook(env.win_ptr, 4, 0, mouse_event, (void*)&env);
  mlx_hook(env.win_ptr, 2, 0, key_press, (void *)&env);
  mlx_hook(env.win_ptr, 3, 0, key_release, (void *)&env);
  mlx_loop(env.mlx_ptr);
  return (0);
}

/*
int generate(void *param)
{
    int   i;
    int   n;
    t_lst *a;
    t_lst *b;
    t_env *env;

    i = 0;
    env = (t_env *)param;
    a = env->p;
    while (i++ < 3)
    {
      b = a->next;
      //draw(a,b,n);
      if (env->n != 0)
        line(env, a->p, b->p);
      a = a->next;

      else (generate)
      déterminer c point au tiers de ab c = (a - b) / 3;
      déterminer d point au deux tiers de ab d = c * 2;
      déterminer e sommet du triangle généré sur le tiers central de ab
      on va passer aux segments ac,ce,ed,db en indiquant le changement de niveau
      dessiner(a,c,n-1) on fait la même chose sur ac (premier tiers)
      dessiner(c,e,n-1) on fait la même chose sur ce (1er cote du triangle généré)
      dessiner(e,d,n-1) on fait la même chose sur ed (2ème cote du triangle généré)
      dessiner(d,b,n-1) on fait la même chose sur ab (dernier tiers)

    }
    return (SUCCESS);
}*/
