/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_fracts.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 22:04:52 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 23:01:50 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mouse_mandel(int button, double x, double y, t_fractol *fract)
{
	double inv_zoom;

	y = (y / fract->zoom) + fract->mandel.y_min;
	x = (x / fract->zoom) + fract->mandel.x_min;
	inv_zoom = 1 - (1 / ZOOM);
	if (button == M_WHEELUP || button == M_LCLICK)
	{
		fract->mandel.x_min = (fract->mandel.x_min / ZOOM) + x * inv_zoom;
		fract->mandel.width /= ZOOM;
		fract->mandel.y_min = (fract->mandel.y_min / ZOOM) + y * inv_zoom;
		fract->mandel.height /= ZOOM;
		fract->zoom *= ZOOM;
	}
	else if (button == M_WHEELDOWN || button == M_RCLICK)
	{
		if (fract->zoom > 330)
		{
			fract->mandel.x_min = (fract->mandel.x_min - x * inv_zoom) * ZOOM;
			fract->mandel.width *= ZOOM;
			fract->mandel.y_min = (fract->mandel.y_min - y * inv_zoom) * ZOOM;
			fract->mandel.height *= ZOOM;
			fract->zoom /= ZOOM;
		}
	}
}

void	mouse_burning(int button, double x, double y, t_fractol *fract)
{
	double inv_zoom;

	y = (y / fract->zoom) + fract->burning.y_min;
	x = (x / fract->zoom) + fract->burning.x_min;
	inv_zoom = 1 - (1 / ZOOM);
	if (button == M_WHEELUP || button == M_LCLICK)
	{
		fract->burning.x_min = (fract->burning.x_min / ZOOM) + x * inv_zoom;
		fract->burning.width /= ZOOM;
		fract->burning.y_min = (fract->burning.y_min / ZOOM) + y * inv_zoom;
		fract->burning.height /= ZOOM;
		fract->zoom *= ZOOM;
	}
	else if (button == M_WHEELDOWN || button == M_RCLICK)
	{
		if (fract->zoom > 330)
		{
			fract->burning.x_min = (fract->burning.x_min - x * inv_zoom) * ZOOM;
			fract->burning.width *= ZOOM;
			fract->burning.y_min = (fract->burning.y_min - y * inv_zoom) * ZOOM;
			fract->burning.height *= ZOOM;
			fract->zoom /= ZOOM;
		}
	}
}

void	mouse_julia(int button, double x, double y, t_fractol *fract)
{
	double inv_zoom;

	y = (y / fract->zoom) + fract->julia.y_min;
	x = (x / fract->zoom) + fract->julia.x_min;
	inv_zoom = 1 - (1 / ZOOM);
	if (button == M_WHEELUP || button == M_LCLICK)
	{
		fract->julia.x_min = (fract->julia.x_min / ZOOM) + x * inv_zoom;
		fract->julia.width /= ZOOM;
		fract->julia.y_min = (fract->julia.y_min / ZOOM) + y * inv_zoom;
		fract->julia.height /= ZOOM;
		fract->zoom *= ZOOM;
	}
	else if (button == M_WHEELDOWN || button == M_RCLICK)
	{
		if (fract->zoom > 330)
		{
			fract->julia.x_min = (fract->julia.x_min - x * inv_zoom) * ZOOM;
			fract->julia.width *= ZOOM;
			fract->julia.y_min = (fract->julia.y_min - y * inv_zoom) * ZOOM;
			fract->julia.height *= ZOOM;
			fract->zoom /= ZOOM;
		}
	}
}
