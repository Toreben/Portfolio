/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/06 21:07:35 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 08:20:52 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef JULIA_H
# define JULIA_H

# include "fractol.h"
# define JULIA_XMIN -3.5
# define JULIA_WIDTH 4.1
# define JULIA_YMIN -2
# define JULIA_HEIGHT 4

typedef struct s_window	t_window;
typedef struct s_comp	t_comp;

typedef enum			e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;

typedef struct			s_julia
{
	double				x_min;
	double				y_min;
	double				width;
	double				height;
	t_comp				center;
	t_bool				is_moving;
}						t_julia;

/*
**JULIA.C
*/
void					init_julia(t_window *win);
void					create_julia(t_window *win);
void					modif_julia_center(int x, int y, void *param);

#endif
