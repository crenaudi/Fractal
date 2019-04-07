#include "../includes/fractol.h"

int init_env(t_env *env)
{
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  env->x1 = -3.1f;
  env->x2 = 1.6f;
  env->y1 = -1.2f;
  env->y2 = 1.2f;
  env->zoom = 250;
  env->iteration_max = 50;
  //if (triangle(env) == ERROR)
  //  return (0);
  return (SUCCESS);
}

void is_event(t_env *env)
{
  if (env->scale.x == 1)
    env->zoom += 10.0f;
  if (env->scale.x == 1)
    env->zoom -= 10.0f;
}

int mandelbrot(t_env *env)
{
    float x;
    float y;
    float i;
    float tmp;

    is_event(env);
    env->x_img = ((env->x2 - env->x1) * env->zoom);
    env->y_img = ((env->y2 - env->y1) * env->zoom);
    x = 0.f;
    while (x < env->x_img)
    {
      y = 0.f;
      while (y < env->y_img)
      {
          env->c_r = x / env->zoom + env->x1;
          env->c_i = y / env->zoom + env->y1;
          env->z_r = 0;
          env->z_i = 0;
          i = 0;
          while ((env->z_r * env->z_r + env->z_i * env->z_i) < 4 && i < env->iteration_max)
          {
            tmp = env->z_r;
            env->z_r = env->z_r * env->z_r - env->z_i * env->z_i + env->c_r;
            env->z_i = 2 * env->z_i * tmp + env->c_i;
            i = i + 1;
          }
          if (i == env->iteration_max)
          {
            mlx_pixel_put(env->mlx_ptr, env->win_ptr,
              (x - (int)(env->x_img / 2)) + (WIDTH / 2),
              (y - (int)(env->y_img / 2)) + (HEIGHT / 2), 0x000000);
          }
          else
          {
            mlx_pixel_put(env->mlx_ptr, env->win_ptr,
              (x - (int)(env->x_img / 2)) + (WIDTH / 2),
              (y - (int)(env->y_img / 2)) + (HEIGHT / 2),
              lerp_non_init_color(0x100005, 0x336699, i));
          }
          y++;
      }
      x++;
    }
    return (SUCCESS);
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

void	legend(t_env *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 20, 0xFFFFFFF, "ZOOM :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 40, 0x999999, "<- / ->");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 10, 70, 0xFFFFFFF,
			"DISPLACEMENT :");
	mlx_string_put(env->mlx_ptr, env->win_ptr, 20, 90, 0x999999,
			"W / A / S / D");
}

int main(int argc, char **argv)
{
  t_env env;
  int   fd;

  if (argc > 2)
  {
    ft_putendl("error : too much arguments.");
    return (0);
  }
  fd = open(argv[1], O_RDONLY | O_NOFOLLOW);
  if (!fd)
    exit(0);
  if(init_env(&env) == ERROR)
    exit(0);
  legend(&env);
  mandelbrot(&env);
  //mlx_loop_hook(env.win_ptr, mandelbrot, (void *)&env);
  mlx_hook(env.win_ptr, 2, 0, key_press, (void *)&env);
  mlx_hook(env.win_ptr, 3, 0, key_release, (void *)&env);
  mlx_loop(env.mlx_ptr);
  return (0);
}
