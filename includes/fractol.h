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

typedef struct s_env    t_env;
typedef struct s_trace  t_trace;
typedef struct s_lst    t_lst;

struct s_env
{
  void          *mlx_ptr;
  void          *win_ptr;
  int           move;
  int           n;
  t_point       *tab;
  struct s_lst  *p;
  int           scale;
};

struct  s_trace
{
  t_vec2          p1;
  t_vec2          p2;
  t_vec2          dir;
  t_vec2          sens;
  float           t;
  struct s_color  c1;
  struct s_color  c2;
};

struct  s_lst
{
  t_vec3          p;
  struct s_lst    *next;
};

int       init_env(t_env *env);
void      win_close(t_env *env);
t_lst    *new_point(float x, float y);
int       triangle(t_env *env);
void			line(t_env *env, t_point p1, t_point p2);
int		    key_press(int key, void *param);
int		    key_release(int key, void *param);

# endif
