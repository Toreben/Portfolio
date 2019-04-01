/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_norm.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 23:36:45 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 21:25:09 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

t_vector	ft_planenorm(t_vector hit, t_object *pln)
{
	hit = ft_v_scal(-1, hit);
	return (ft_v_scal(-1, pln->dir));
}

t_vector	ft_sphnorm(t_vector hit, t_object *sph)
{
	return (ft_v_normalize(ft_v_sub(hit, sph->pos)));
}

t_vector	ft_cldnorm(t_vector hit, t_object *cld)
{
	t_vector	norm;
	double		dis;

	dis = sqrt(pow(ft_v_norme(ft_v_sub(hit, cld->pos)), 2) - pow(cld->size, 2));
	if (ft_v_dot(ft_v_sub(hit, cld->pos), cld->dir) < 0)
		dis *= -1;
	norm.x = dis * cld->dir.x + cld->pos.x;
	norm.y = dis * cld->dir.y + cld->pos.y;
	norm.z = dis * cld->dir.z + cld->pos.z;
	return (ft_v_normalize(ft_v_sub(hit, norm)));
}

t_vector	ft_conenorm(t_vector hit, t_object *cone)
{
	t_vector	norm;
	double		dist;

	dist = ft_v_norme(ft_v_sub(hit, cone->pos)) / cos(cone->size);
	if (ft_v_dot(ft_v_sub(hit, cone->pos), cone->dir) < 0)
		dist *= -1;
	norm.x = dist * cone->dir.x + cone->pos.x;
	norm.y = dist * cone->dir.y + cone->pos.y;
	norm.z = dist * cone->dir.z + cone->pos.z;
	return (ft_v_normalize(ft_v_sub(hit, norm)));
}
