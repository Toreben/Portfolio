/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   angle.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 18:47:53 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:20:32 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_wrap_angle(int angle)
{
	angle %= 360;
	if (180 < angle)
		angle -= 360;
	if (angle <= -180)
		angle += 360;
	return (angle);
}

t_angle		ft_update_angle(t_angle angle)
{
	angle.deg = ft_wrap_angle(angle.deg);
	angle.rad = (angle.deg * M_PI / 180);
	angle.cos_ang = cos(angle.rad);
	angle.sin_ang = sin(angle.rad);
	return (angle);
}
