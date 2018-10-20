/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   burning.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/03 17:21:51 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 23:02:13 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef BURNING_H
# define BURNING_H
# include "fractol.h"
# define BURNING_XMIN -2.5
# define BURNING_WIDTH 3.5
# define BURNING_YMIN -2
# define BURNING_HEIGHT 3

typedef struct s_window	t_window;

typedef struct			s_burning
{
	double				x_min;
	double				y_min;
	double				width;
	double				height;
}						t_burning;

/*
**BURNING_SHIP.C
*/
void					init_burning(t_window *win);
void					create_burning(t_window *win);

#endif
