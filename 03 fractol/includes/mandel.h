/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mandel.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/28 16:29:22 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 16:42:23 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef MANDEL_H
# define MANDEL_H
# include "fractol.h"

# define MANDEL_XMIN -2.1
# define MANDEL_WIDTH 2.7
# define MANDEL_YMIN -1.2
# define MANDEL_HEIGHT 2.4

typedef struct s_window	t_window;

typedef struct			s_mandel
{
	double				x_min;
	double				y_min;
	double				width;
	double				height;
}						t_mandel;

/*
**MANDEL.C
*/
void					create_mandel(t_window *win);
void					init_mandel(t_window *win);

#endif
