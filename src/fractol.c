#include "../includes/fractol.h"

int init_env(t_env *env)
{
  ft_bzero(env, sizeof(t_env));
  env->mlx_ptr = mlx_init();
  env->win_ptr = mlx_new_window(env->mlx_ptr, WIDTH, HEIGHT, "Fractol");
  return (SUCCESS);
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
  mlx_hook(env.win_ptr, 2, 0, key_press, (void *)&env);
  mlx_hook(env.win_ptr, 3, 0, key_release, (void *)&env);
  mlx_loop(env.mlx_ptr);
  return (0);
}
