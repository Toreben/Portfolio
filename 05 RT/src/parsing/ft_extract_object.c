/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_extract_object.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 15:41:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 02:45:00 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

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

static t_scroll_box_elem	*ft_generate_lst_obj(t_object *obj)
{
	t_scroll_box_elem	*new;

	//a proteger
	if (!(new = (t_scroll_box_elem*)ft_memalloc(sizeof(t_scroll_box_elem))))
		exit(0);
	if (obj->type == SPHERE)
		//a proteger
		new->name = ft_strdup("SPHERE");
	else if (obj->type == CONE)
		//a proteger
		new->name = ft_strdup("CONE");
	else if (obj->type == CYLINDER)
		//a proteger
		new->name = ft_strdup("CYLINDER");
	else
		//a proteger
		new->name = ft_strdup("PLANE");
	new->address = (void*)obj;
	return (new);
}	

static	void	ft_add_to_lst_ui(t_scroll_box_elem **head, t_object *cnt)
{
	t_scroll_box_elem *tail;

	if (!*head)
	{
		*head = ft_generate_lst_obj(cnt);
		return;
	}	
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = ft_generate_lst_obj(cnt);
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
	ft_get_color(&(obj->color), ft_atox(&(f[*l][ft_strlen("\t\t\tcolor = ")])));
	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	ft_add_to_lst_ui(&scn->ui.objs.lst, obj);
	if (ft_strcmp(f[*l], "\t}"))
		obj->next = ft_extract_object(f, l, scn);
	return (obj);
}
