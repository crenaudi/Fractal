# ifndef FRACTOL_H
# define FRACTOL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
# include "mlx.h"
# include "libft.h"
# include "gfx.h"

# define ERROR 		-1
# define SUCCESS	0
# define WIDTH    800
# define HEIGHT   600
# define ESC			53
# define MOVE			5
# define ZOOM			116
# define DZOOM		121

typedef struct s_env      t_env;
typedef struct s_envthread   t_envthread;

struct s_env
{
  void          *mlx_ptr;
  void          *win_ptr;
  int           move;
  int           n;
  t_point       *tab;
  struct s_lst  *p;
  t_envthread   *e_thread1;
  t_envthread   *e_thread2;
  t_envthread   *e_thread3;
  t_envthread   *e_thread4;
  float         x1;
  float         x2;
  float         y1;
  float         y2;
  t_vec2        scale;
  float         x_img;
  float         y_img;
};

struct s_envthread
{
  void          *mlx_ptr_cpy;
  void          *win_ptr_cpy;
  t_vec3        fractal;
  float         x;
  float         x1;
  float         x2;
  float         y1;
  float         y2;
  float         zoom;
  float         z_r;
  float         z_i;
  float         c_r;
  float         c_i;
  float         x_img;
  float         y_img;
  float         iteration_max;
};

int       init_env(t_env *env);
void      win_close(t_env *env);
t_env     *init_mandelbrot(t_env *env);
t_env     *init_julia(t_env *env);
void      *open_thread(void *param);
int       fractal(t_env *env);
void      julia(t_envthread *e, int i, float y);
void      mandelbrot(t_envthread *e, int i, float y);
void			line(t_env *env, t_point p1, t_point p2);
int		    key_press(int key, void *param);
int		    key_release(int key, void *param);
void	    legend(t_env *env);

# endif
