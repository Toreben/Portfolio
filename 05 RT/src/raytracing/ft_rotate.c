/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rotate.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 14:52:24 by mhervet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 04:30:38 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static t_quat	ft_get_quat(t_vector v, double angle)
{
	t_quat		quat;

	quat.w = cos(angle / 2);
	quat.x = v.x * sin(angle / 2);
	quat.y = v.y * sin(angle / 2);
	quat.z = v.z * sin(angle / 2);
	return (quat);
}

t_vector		ft_apply_quat(t_vector v, t_quat quat)
{
	t_vector	rotv;
	t_vector	u;
	double		w;

	w = quat.w;
	u.x = quat.x;
	u.y = quat.y;
	u.z = quat.z;
	rotv = ft_v_add(ft_v_add(ft_v_scal(2.0 * ft_v_dot(u, v), u),
			ft_v_scal(w * w - ft_v_dot(u, u), v)), ft_v_scal(2 * w,
			ft_v_cross(u, v)));
	return (ft_v_normalize(rotv));
}

t_vector		ft_rotate(t_scene *scn, t_vector ray)
{
	t_quat		xquat;
	t_quat		yquat;
	t_vector	xaxis;
	t_vector	yaxis;

	yaxis.x = 0;
	yaxis.y = 1;
	yaxis.z = 0;
	yquat = ft_get_quat(yaxis, scn->cam.ang_y);
	ray = ft_apply_quat(ray, yquat);
	xaxis.x = 1;
	xaxis.y = 0;
	xaxis.z = 0;
	xaxis = ft_apply_quat(xaxis, yquat);
	xquat = ft_get_quat(xaxis, scn->cam.ang_x);
	ray = ft_apply_quat(ray, xquat);
	return (ray);
}
