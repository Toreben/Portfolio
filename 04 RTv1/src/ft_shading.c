/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_shading.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 15:46:58 by mhervet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 18:03:33 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_uint		ft_diffuse(t_vector norm, t_vector hit, t_uint color, t_spot *spt)
{
	t_vector		light_dir;
	double			light_power;
	double			light_reflect;

	light_dir = ft_v_normalize(ft_v_sub(spt->dir, hit));
	light_power = pow(fmax(0.0, ft_v_dot(norm, light_dir)), 1)
		* spt->intensity;
	light_reflect = 1 / (4 * M_PI * ft_v_norme(ft_v_sub(spt->dir, hit)));
	return (ft_mult_color(color, light_power * light_reflect));
}

t_uint		ft_specular(t_scene *scn, t_vector hit, t_vector norm, t_spot *spt)
{
	t_vector		light_dir;
	t_vector		view_dir;
	t_vector		grand_r;
	double			light_power;

	light_dir = ft_v_normalize(ft_v_sub(spt->dir, hit));
	view_dir = ft_v_normalize(ft_v_sub(scn->cam.pos, hit));
	grand_r = ft_v_sub(ft_v_scal(2 * ft_v_dot(norm, light_dir), norm),
		light_dir);
	light_power = 0.5 * pow(fmax(0.0, ft_v_dot(grand_r, view_dir)), 20)
		* spt->intensity;
	return (ft_mult_color(spt->color, light_power
				/ (4 * M_PI * ft_v_norme(ft_v_sub(spt->dir, hit)))));
}

double		ft_in_shadow(t_scene *scn, t_object *obj, t_vector ray, double dist)
{
	t_object	*tmp;

	tmp = scn->content;
	dist *= 0.9999;
	while (tmp)
	{
		if (tmp != obj)
		{
			if (tmp->hit(scn->cam.pos, tmp, ray) < dist)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_uint		ft_shading(t_scene *scn, t_vector hit, t_vector norm, t_object *obj)
{
	t_uint		dif;
	t_uint		spec;
	t_vector	cam_tmp;
	t_spot		*spt;

	spt = scn->spt;
	dif = 0;
	spec = 0;
	cam_tmp = scn->cam.pos;
	while (spt)
	{
		scn->cam.pos = ft_v_add(hit, ft_v_scal(0.00000001, norm));
		if (!ft_in_shadow(scn, obj, ft_v_normalize(ft_v_sub(spt->dir, hit)),
					ft_v_norme(ft_v_sub(spt->dir, hit))))
		{
			scn->cam.pos = cam_tmp;
			dif = ft_light_sum(ft_diffuse(norm, hit, obj->color, spt), dif, 0);
			spec = ft_light_sum(ft_specular(scn, hit, norm, spt), spec, 0);
		}
		spt = spt->next;
	}
	scn->cam.pos = cam_tmp;
	return (ft_light_sum(ft_mult_color(ft_mult_color(0xFFFFFF00, 0.5)
				+ ft_mult_color(obj->color, 0.5), 0.2), dif, spec));
}
