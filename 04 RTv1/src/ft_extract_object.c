/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_extract_object.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 15:41:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 04:05:00 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static t_object	*ft_extract_type(char *src, t_object *obj)
{
	if (!ft_strcmp(src, "\t\tsphere :"))
	{
		obj->type = SPHERE;
		obj->hit = &ft_hitsphere;
		obj->norm_obj = &ft_sphnorm;
	}
	else if (!ft_strcmp(src, "\t\tcone :"))
	{
		obj->type = CONE;
		obj->hit = &ft_hitcone;
		obj->norm_obj = &ft_conenorm;
	}
	else if (!ft_strcmp(src, "\t\tcylinder :"))
	{
		obj->type = CYLINDER;
		obj->hit = &ft_hitcld;
		obj->norm_obj = &ft_cldnorm;
	}
	else if (!ft_strcmp(src, "\t\tplane :"))
	{
		obj->type = PLANE;
		obj->hit = &ft_hitplane;
		obj->norm_obj = &ft_planenorm;
	}
	return (obj);
}

static t_object	*ft_extract_size(char *src, t_object *obj)
{
	if ((ft_strnstr(src, "\t\t\tradius = ", ft_strlen("\t\t\tradius = "))
			&& (obj->type == SPHERE || obj->type == CYLINDER)))
		obj->size = ft_atof(src + ft_strlen("\t\t\tradius = "));
	else if (ft_strnstr(src, "\t\t\tangle = ", ft_strlen("\t\t\tangle = "))
				&& obj->type == CONE)
		obj->size = ft_atof(src + ft_strlen("\t\t\tangle = ")) * M_PI / 180;
	else if (obj->type == PLANE)
		obj->size = 0;
	return (obj);
}

t_object		*ft_extract_object(char **f, int *l, t_scene *scn)
{
	t_object	*obj;

	if (!(obj = (t_object*)ft_memalloc(sizeof(t_object))))
	{
		free_file(f, 2);
		free_scn(scn);
		exit(0);
	}
	obj = ft_extract_type(f[*l], obj);
	*l = ft_skip_com(f, *l + 2, NULL);
	obj->pos = ft_extract_vect(f[*l]);
	*l = ft_skip_com(f, *l + 1, NULL);
	obj->dir = ft_v_normalize(ft_extract_vect(f[*l]));
	*l = ft_skip_com(f, *l + 1, NULL);
	obj = ft_extract_size(f[*l], obj);
	obj->type != PLANE ? *l = ft_skip_com(f, *l + 1, NULL) : 0;
	obj->color = ft_atox(&(f[*l][ft_strlen("\t\t\tcolor = ")]));
	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	if (ft_strcmp(f[*l], "\t}"))
		obj->next = ft_extract_object(f, l, scn);
	return (obj);
}
