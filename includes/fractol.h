# ifndef FRACTOL_H
# define FRACTOL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include "mlx.h"
# include "libft.h"
# include "gfx.h"

# define ERROR 		-1
# define SUCCESS	0
# define WIDTH    1200
# define HEIGHT   600
# define ESC			53
# define MOVE			5

typedef struct s_env t_env;

struct s_env
{
  void  *mlx_ptr;
  void  *win_ptr;
  int   move;
};

int   init_env(t_env *env);
void  win_close(t_env *env);
int		key_press(int key, void *param);
int		key_release(int key, void *param);

# endif
