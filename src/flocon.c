#include "../includes/fractol.h"

t_lst  *new_point(float x, float y)
{
  t_lst  *new;

  if (!(new = (t_lst *)malloc(sizeof(t_lst))))
    return NULL;
  new->c.x = x;
  new->c.y = y;
  new->index = 0;
  new->next = NULL;
  return(new);
}

int triangle(t_env *env, int fd)
{
    t_lst *coord;
    t_lst *begin;
    char  *line_bis;
    int   x;

    env->n = 1;
    while (get_next_line(fd, &env->line) == 1)
    {
      line_bis = env->line;
      x = 0;
      while (env->line[x] != '\0')
      {
        if (env->line[x] == '*')
        {
          if (env->n == 1)
          {
            coord = new_point(x, env->y_max);
            begin = coord;
          }
          else
          {
            coord->next = new_point(x, env->y_max);
            coord = coord->next;
            if (x > env->x_max)
              env->x_max = x;
          }
          env->n = 0;
        }
        x++;
      }
      env->y_max++;
      free(line_bis);
    }
    coord->next = begin;
    env->p = begin;
    return (SUCCESS);
}
