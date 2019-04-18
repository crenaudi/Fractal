#include "../includes/fractol.h"

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
      déterminer c point au tiers de ab
      déterminer d point au deux tiers de ab
      déterminer e sommet du triangle généré sur le tiers central de ab
      on va passer aux segments ac,ce,ed,db en indiquant le changement de niveau
      dessiner(a,c,n-1) on fait la même chose sur ac (premier tiers)
      dessiner(c,e,n-1) on fait la même chose sur ce (1er cote du triangle généré)
      dessiner(e,d,n-1) on fait la même chose sur ed (2ème cote du triangle généré)
      dessiner(d,b,n-1) on fait la même chose sur ab (dernier tiers)

    }
    return (SUCCESS);
}*/

int main(int argc, char **argv)
{
  t_env env;

  if (argc > 2)
  {
    ft_putendl("error : too much arguments.");
    return (0);
  }
  //legend(&env);
  if (ft_strcmp(argv[1], "mandelbrot") == 0)
  {
    fractal(init_mandelbrot(&env));
  }
  else if (ft_strcmp(argv[1], "julia") == 0)
  {
    fractal(init_julia(&env));
  }
  else
  {
    ft_putendl("error : incorrect name argument.");
    exit(0);
  }
  //mlx_loop_hook(env.win_ptr, mandelbrot, (void *)&env);
  mlx_hook(env.win_ptr, 2, 0, key_press, (void *)&env);
  mlx_hook(env.win_ptr, 3, 0, key_release, (void *)&env);
  mlx_loop(env.mlx_ptr);
  return (0);
}
