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
#define N_COLORS  3*256
# define ESC			53
# define MOVE			5
# define MORE			116
# define LESS 		121

typedef struct s_env      t_env;
typedef struct s_envthread   t_envthread;
typedef struct s_budd  t_budd;

struct s_env
{
  void          *mlx_ptr;
  void          *win_ptr;
  t_vec2        move;
  t_img				  *img;
  t_envthread   **e_thread;
  t_vec2        mouse;
  t_vec2        scale;
  int           julia;
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
  void          *param_sup;
};

struct s_budd
{
  t_vec3      it;
  int         **px_r;
  int         **px_v;
  int         **px_b;
};

int       init_env(t_env *env);
void      win_close(t_env *env);
int       **do_tab_px(int y);
t_budd    *do_tab(void);
t_env     *init_fractal(t_env *env, int fractal);
void      *open_thread(void *param);
int       fractal(t_env *env);
void      julia(t_envthread *e, int i, float y);
void      mandelbrot(t_envthread *e, int i, float y);
void      buddhabrot(t_envthread *e, int i, float y);
int       mouse_event(int code, int x, int y, void *param);
int		    key_press(int key, void *param);
int		    key_release(int key, void *param);
void	    legend(t_env *env);
void	    is_error(int i);

# endif
