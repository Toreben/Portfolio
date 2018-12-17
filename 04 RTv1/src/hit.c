/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hit.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 06:45:05 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 19:37:28 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static double	ft_delta(double a, double b, double c)
{
	double		delta;
	double		s_1;
	double		s_2;

	delta = b * b - 4 * a * c;
	if (delta >= 0)
	{
		s_1 = (-b - sqrt(delta)) / (2 * a);
		s_2 = (-b + sqrt(delta)) / (2 * a);
		if ((s_1 < s_2 && 0 <= s_1) || (0 <= s_1 && s_2 < 0))
			return (s_1);
		else if (0 <= s_2)
			return (s_2);
	}
	return (INFINITY);
}

double			ft_hitplane(t_vector origin, t_object *obj, t_vector ray)
{
	double		t;

	t = -((obj->dir.x * (origin.x - obj->pos.x) +
			obj->dir.y * (origin.y - obj->pos.y) +
			obj->dir.z * (origin.z - obj->pos.z)) /
			(obj->dir.x * ray.x + obj->dir.y * ray.y + obj->dir.z * ray.z));
	if (t > 0)
		return (t);
	return (INFINITY);
}

double			ft_hitsphere(t_vector origin, t_object *obj, t_vector ray)
{
	double		a;
	double		b;
	double		c;

	a = ft_v_dot(ray, ray);
	b = 2 * ft_v_dot(ray, ft_v_sub(origin, obj->pos));
	c = ft_v_dot(ft_v_sub(origin, obj->pos), ft_v_sub(origin, obj->pos))
		- pow(obj->size, 2);
	return (ft_delta(a, b, c));
}

double			ft_hitcld(t_vector origin, t_object *obj, t_vector ray)
{
	double		a;
	double		b;
	double		c;

	a = ft_v_dot(ft_v_sub(ray, ft_v_scal(ft_v_dot(ray, obj->dir), obj->dir)),
			ft_v_sub(ray, ft_v_scal(ft_v_dot(ray, obj->dir), obj->dir)));
	b = 2 * ft_v_dot(ft_v_sub(ray, ft_v_scal(ft_v_dot(ray, obj->dir),
			obj->dir)), ft_v_sub(ft_v_sub(origin, obj->pos),
			ft_v_scal(ft_v_dot(ft_v_sub(origin, obj->pos), obj->dir),
			obj->dir)));
	c = ft_v_dot(ft_v_sub(ft_v_sub(origin, obj->pos), ft_v_scal(
			ft_v_dot(ft_v_sub(origin, obj->pos), obj->dir),
			obj->dir)), ft_v_sub(ft_v_sub(origin, obj->pos),
			ft_v_scal(ft_v_dot(ft_v_sub(origin, obj->pos), obj->dir),
			obj->dir))) - pow(obj->size, 2);
	return (ft_delta(a, b, c));
}

double			ft_hitcone(t_vector origin, t_object *obj, t_vector ray)
{
	double		a;
	double		b;
	double		c;

	a = pow(cos(obj->size), 2) * ft_v_dot(ft_v_sub(ray, ft_v_scal(
			ft_v_dot(ray, obj->dir), obj->dir)), ft_v_sub(ray, ft_v_scal(
			ft_v_dot(ray, obj->dir), obj->dir)))
			- pow(sin(obj->size), 2) * pow(ft_v_dot(ray, obj->dir), 2);
	b = 2 * pow(cos(obj->size), 2) * ft_v_dot(ft_v_sub(ray, ft_v_scal(
			ft_v_dot(ray, obj->dir), obj->dir)), ft_v_sub(ft_v_sub(
			origin, obj->pos), ft_v_scal(ft_v_dot(ft_v_sub(origin,
			obj->pos), obj->dir), obj->dir))) - 2 *
			pow(sin(obj->size), 2) * ft_v_dot(ray, obj->dir) * ft_v_dot(
			ft_v_sub(origin, obj->pos), obj->dir);
	c = pow(cos(obj->size), 2) * ft_v_dot(ft_v_sub(ft_v_sub(origin,
			obj->pos), ft_v_scal(ft_v_dot(ft_v_sub(origin,
			obj->pos), obj->dir), obj->dir)), ft_v_sub(ft_v_sub(
			origin, obj->pos), ft_v_scal(ft_v_dot(ft_v_sub(origin,
			obj->pos), obj->dir), obj->dir)))
			- pow(sin(obj->size), 2) * pow(ft_v_dot(ft_v_sub(origin,
			obj->pos), obj->dir), 2);
	return (ft_delta(a, b, c));
}
