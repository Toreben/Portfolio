/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_rotate.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 14:52:24 by mhervet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 04:03:31 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		ft_get_quat(t_vector v, double angle, double quat[4])
{
	quat[0] = cos(angle / 2);
	quat[1] = v.x * sin(angle / 2);
	quat[2] = v.y * sin(angle / 2);
	quat[3] = v.z * sin(angle / 2);
}

t_vector	ft_apply_quat(t_vector v, double quat[4])
{
	t_vector	rotv;
	t_vector	u;
	double		w;

	w = quat[0];
	u.x = quat[1];
	u.y = quat[2];
	u.z = quat[3];
	rotv = ft_v_add(ft_v_add(ft_v_scal(2.0 * ft_v_dot(u, v), u),
			ft_v_scal(w * w - ft_v_dot(u, u), v)), ft_v_scal(2 * w,
			ft_v_cross(u, v)));
	return (ft_v_normalize(rotv));
}

t_vector	ft_rotate(t_scene *scn, t_vector ray)
{
	double		xquat[4];
	double		yquat[4];
	t_vector	xaxis;
	t_vector	yaxis;

	yaxis.x = 0;
	yaxis.y = 1;
	yaxis.z = 0;
	ft_get_quat(yaxis, scn->cam.ang_y, yquat);
	ray = ft_apply_quat(ray, yquat);
	xaxis.x = 1;
	xaxis.y = 0;
	xaxis.z = 0;
	xaxis = ft_apply_quat(xaxis, yquat);
	ft_get_quat(xaxis, scn->cam.ang_x, xquat);
	ray = ft_apply_quat(ray, xquat);
	return (ray);
}
