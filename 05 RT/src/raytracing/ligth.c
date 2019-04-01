/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ligth.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 20:59:57 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/05 03:54:18 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

t_color		ft_mult_color(t_color color, double coef)
{
	color.r *= coef;
	color.r > 0xFF ? color.r = 0xFF : 0;
	color.g *= coef;
	color.g > 0xFF ? color.g = 0xFF : 0;
	color.b *= coef;
	color.b > 0xFF ? color.b = 0xFF : 0;
	return (color);
}

/*
** t_uint		ft_light_sum(t_uint c_a, t_uint c_d, t_uint c_s)
** {
** 	t_uint	r;
** 	t_uint	g;
** 	t_uint	b;
**
** 	r = ((c_a & 0xFF000000) >> 24) | ((c_d & 0xFF000000) >> 24)
** 		- ((c_s & 0xFF000000) >> 24);
** 	g = ((c_a & 0x00FF0000) >> 16) | ((c_d & 0x00FF0000) >> 16)
** 		* ((c_s & 0x00FF0000) >> 16);
** 	b = ((c_a & 0x0000FF00) >> 8) | ((c_d & 0x0000FF00) >> 8)
** 		+ ((c_s & 0x0000FF00) >> 8);
** 	(r > 255) ? r = 255 : 0;
** 	(g > 255) ? g = 255 : 0;
** 	(b > 255) ? b = 255 : 0;
** 	return ((r << 24) + (g << 16) + (b << 8));
** }
*/

void		ft_color_pond(t_color *col, t_uint nb)
{
	col->r /= nb;
	col->r > 0xFF ? col->r = 0xFF : 0;
	col->g /= nb;
	col->g > 0xFF ? col->g = 0xFF : 0;
	col->b /= nb;
	col->b > 0xFF ? col->b = 0xFF : 0;
	col->a /= nb;
	col->a > 0xFF ? col->a = 0xFF : 0;
}

t_color		ft_color_sum(t_color c_1, t_color c_2)
{
	c_1.r += c_2.r;
	c_1.g += c_2.g;
	c_1.b += c_2.b;
	c_1.a += c_2.a;
	return (c_1);
}

t_color		ft_light_sum(t_color c_a, t_color c_d, t_color c_s)
{
	t_color sum;

	sum.r = (c_a.r + c_d.r + c_s.r);
	sum.r > 0xFF ? sum.r = 0xFF : 0;
	sum.g = (c_a.g + c_d.g + c_s.g);
	sum.g > 0xFF ? sum.g = 0xFF : 0;
	sum.b = (c_a.b + c_d.b + c_s.b);
	sum.b > 0xFF ? sum.b = 0xFF : 0;
	sum.a = (c_a.a + c_d.a + c_s.a);
	sum.a > 0xFF ? sum.a = 0xFF : 0;
	return (sum);
}
