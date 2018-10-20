/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_trace.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 02:46:15 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:20:41 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int	is_in_img(t_point point)
{
	unsigned int pos;

	pos = (((unsigned int)point.y2d * IMG_X) + (unsigned int)point.x2d);
	if (((point.y2d >= 0) && (WIN_Y >= point.y2d))
		&& ((point.x2d >= 0) && (IMG_X >= point.x2d))
		&& (pos <= IMG_X * WIN_Y))
		return (1);
	return (0);
}

int	is_to_print(t_point point, t_window *win)
{
	if (((point.y2d >= -win->fac + 1) && (WIN_Y + win->fac - 1 >= point.y2d))
		&& ((point.x2d >= -win->fac + 1)
		&& (IMG_X + win->fac - 1 >= point.x2d)))
		return (1);
	return (0);
}
