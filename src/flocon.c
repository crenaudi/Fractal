#include "../includes/fractol.h"

t_lst  *new_point(float x, float y)
{
  t_lst  *new;

  if (!(new = (t_lst *)malloc(sizeof(t_lst))))
    return NULL;
  new->p.x = x;
  new->p.y = y;
  new->next = NULL;
  return(new);
}

int triangle(t_env *env)
{
    t_lst *p;
    int   y;

    y = 0;
    p = new_point(0, 0);
    env->p = p;
    while (y++ < 4)
    {
      p->next = new_point(0, 0);
      p = p->next;
    }
    p->next = env->p;
    p = p->next;
    p->p.x += -1 * env->scale;
    p->p.y += 1 * env->scale;
    p = p->next;
    p->p.x += 0 * env->scale;
    p->p.y += -1 * env->scale;
    p = p->next;
    p->p.x += 1 * env->scale;
    p->p.y += 1 * env->scale;
    return (SUCCESS);
}
