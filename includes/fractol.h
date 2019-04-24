# ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "mlx.h"
# include "libft.h"
# include "gfx.h"

# define ERROR 		-1
# define SUCCESS	0
# define WIDTH    1000
# define HEIGHT   700
# define M_WTH    500
# define M_HHT    350
# define THREADS  8
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
  t_img				  *img;
  t_envthread   **e_thread;
  t_vec2        mouse;
  t_vec2        scale;
  float         x_img;
  float         y_img;
};

struct s_envthread
{
  void          *mlx_ptr_cpy;
  void          *win_ptr_cpy;
  int           *data;
  t_vec3        fractal;
  t_vec3        x;
  float         y1;
  float         y2;
  float         zoom;
  float         z_r;
  float         z_i;
  float         c_r;
  float         c_i;
  float         x_img;
  float         y_img;
  float         it_max;
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
int       mouse_event(int code, int x, int y, void *param);
int		    key_press(int key, void *param);
int		    key_release(int key, void *param);
void      is_event(t_env *env);
void	    legend(t_env *env);
void	    is_error(int i);

# endif
