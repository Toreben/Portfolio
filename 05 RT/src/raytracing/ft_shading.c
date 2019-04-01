/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_shading.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 15:46:58 by mhervet      #+#   ##    ##    #+#       */
/*   Updated: 2019/02/21 23:30:11 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static t_color	ft_col_and_col(t_color c_1, t_color c_2)
{
	c_1.r &= c_2.r;
	c_1.g &= c_2.g;
	c_1.b &= c_2.b;
	c_1.a &= c_2.a;
	return (c_1);
}

static t_color	ft_diffuse(t_vector norm, t_vector hit, t_color color, t_spot *spt)
{
	t_vector		light_dir;
	double			light_power;
	double			light_reflect;

	light_dir = ft_v_normalize(ft_v_sub(spt->pos, hit));
	light_power = pow(fmax(0.0, ft_v_dot(norm, light_dir)), 1)
		* spt->intensity;
	light_reflect = 1 / (4 * M_PI * ft_v_norme(ft_v_sub(spt->pos, hit)));
	return (ft_mult_color(ft_col_and_col(color, spt->color), light_power * light_reflect));
}

static t_color	ft_specular(t_scene *scn, t_vector hit, t_vector norm, t_spot *spt)
{
	t_vector		light_dir;
	t_vector		view_dir;
	t_vector		grand_r;
	double			light_power;

	light_dir = ft_v_normalize(ft_v_sub(spt->pos, hit));
	view_dir = ft_v_normalize(ft_v_sub(scn->cam.pos, hit));
	grand_r = ft_v_sub(ft_v_scal(2 * ft_v_dot(norm, light_dir), norm),
		light_dir);
	light_power = 0.5 * pow(fmax(0.0, ft_v_dot(grand_r, view_dir)), 20)
		* spt->intensity;
	return (ft_mult_color(spt->color, light_power
				/ (4 * M_PI * ft_v_norme(ft_v_sub(spt->pos, hit)))));
}

static double	ft_in_shadow(t_scene *scn, t_object *obj, t_vector ray, double dist)
{
	t_object	*tmp;

	tmp = scn->content;
	dist *= 0.9999;
	while (tmp)
	{
		if (tmp != obj)
			if (tmp->hit(scn->cam.pos, tmp, ray) < dist)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_color			ft_shading(t_scene *scn, t_vector hit, t_vector norm, t_object *obj)
{
	t_color		dif;
	t_color		spec;
	t_vector	cam_tmp;
	t_spot		*spt;

	spt = scn->spt;
	dif = (t_color){.r = 0, .g = 0, .b = 0, .a = 0};
	spec = (t_color){.r = 0, .g = 0, .b = 0, .a = 0};
	cam_tmp = scn->cam.pos;
	while (spt)
	{
		scn->cam.pos = ft_v_add(hit, ft_v_scal(0.00000001, norm));
		if (!ft_in_shadow(scn, obj, ft_v_normalize(ft_v_sub(spt->pos, hit)),
					ft_v_norme(ft_v_sub(spt->pos, hit))))
		{
			scn->cam.pos = cam_tmp;
			dif = ft_color_sum(ft_diffuse(norm, hit, obj->color, spt), dif);
			spec = ft_color_sum(ft_specular(scn, hit, norm, spt), spec);
		}
		spt = spt->next;
	}
	scn->cam.pos = cam_tmp;
	return (ft_light_sum(ft_col_and_col(obj->color, ft_mult_color(scn->amb.color, 1 / scn->amb.intensity)), dif, spec));
}
