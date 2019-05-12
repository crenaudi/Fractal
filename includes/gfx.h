/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:18:21 by crenaudi          #+#    #+#             */
/*   Updated: 2019/05/12 15:59:33 by crenaudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H

# define GFX_H

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include "libft.h"

typedef int		t_vec2 __attribute__((ext_vector_type(2)));
typedef float	t_vec3 __attribute__((ext_vector_type(3)));
typedef t_vec3			t_point;
typedef struct s_img	t_img;
typedef struct s_color	t_color;
typedef struct s_hsl	t_hsl;
typedef union u_rgb		t_rgb;

struct					s_img
{
	void				*ptr;
	int					*data;
	int					bpp;
	int					sl;
	int					endian;
};

struct					s_color
{
	int					r;
	int					g;
	int					b;
	int					color;
};

struct					s_hsl
{
	int					h;
	int					s;
	int					l;
};

float					hsl_float_min(float *n);
float					hsl_float_max(float *n);
t_vec3					rgbtohsl(float r, float g, float b);
int						hsltorgb(float hue, float sat, float lum);
t_img					*init_img(void *mlx_ptr, int x, int y);
t_img					*do_div(void *mlx_ptr, int x, int y, int c);
float					vec2_dist(t_vec2 v2);
t_color					init_c(int color);
int						lerp_c(t_color s, t_color e, float t);
int						lerp_non_init_color(int a, int b, float t);
float					deg2rad(float d);
float					rad2deg(float r);
void					scale(t_point *p, float e);
float					dot_product(t_vec3 a, t_vec3 b);
t_vec3					cross_product(t_vec3 a, t_vec3 b);
void					rotate_x(t_point *p, float a);
void					rotate_y(t_point *p, float a);
void					rotate_z(t_point *p, float a);
t_point					normalize(t_point v);
float					spherical_theta(t_point v);
float					spherical_phi(t_point v);
t_point					to_vec_spherical(t_point v);
void					spherical_perspective(t_point v, t_point *p);

#endif
