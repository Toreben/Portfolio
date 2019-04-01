/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_extract_view.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/13 18:52:07 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 03:24:17 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

t_camera	ft_extract_camera(char **f, int *l)
{
	t_camera	cam;

	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.pos = ft_extract_vect(f[*l]);
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.ang_x = ft_atof(&f[*l][ft_strlen("\t\t\tangle on x = ")]) * M_PI / 180;
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.ang_y = ft_atof(&f[*l][ft_strlen("\t\t\tangle on y = ")]) * M_PI / 180;
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.dist = ft_atof(&(f[*l][ft_strlen("\t\t\tdistance = ")]));
	*l = ft_skip_com(f, *l + 1, NULL);
	return (cam);


/*
	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.pos = ft_extract_vect(f[*l]);
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.dir = ft_extract_vect(f[*l]);
	if (cam.pos == cam.dir) //a tester
	{
		ft_putendl("The direction and view of the camera are the same.");
		free_file(f, 1);
		if (scn->amb)
			free(scn->amb);
		free(scn);
		exit(0);
	}
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.tilt = ft_atof(&f[*l][ft_strlen("\t\t\ttilt = ")]) * M_PI / 180;
	*l = ft_skip_com(f, *l + 1, NULL);
	cam.dist = ft_atof(&(f[*l][ft_strlen("\t\t\tdistance = ")]));
	*l = ft_skip_com(f, *l + 1, NULL);
	return (cam);
*/
}

/*t_viewport	ft_extract_viewport(char **f, int *l)
{
	t_viewport	view;

	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	// view.h = (double)ft_atoi(&(f[*l][ft_strlen("\t\t\theight = ")]));
	*l = ft_skip_com(f, *l + 1, NULL);
	// view.w = (double)ft_atoi(&(f[*l][ft_strlen("\t\t\twidth = ")]));
	*l = ft_skip_com(f, *l + 1, NULL);
	return (view);
}*/

static t_scroll_box_elem		*ft_generate_lst_spt(t_spot *spt)
{
	t_scroll_box_elem	*new;

	//a proteger
	if (!(new = (t_scroll_box_elem*)ft_memalloc(sizeof(t_scroll_box_elem))))
		exit(0);
	//a proteger
	new->name = ft_strdup("SPOT");
	new->address = (void*)spt;
	return (new);
}

static	void	ft_add_to_lst_ui(t_scroll_box_elem **head, t_spot *spt)
{
	t_scroll_box_elem *tail;

	if (!*head)
	{
		*head = ft_generate_lst_spt(spt);
		return;
	}	
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = ft_generate_lst_spt(spt);
}

t_spot		*ft_extract_spot(char **f, int *l, t_scene *scn)
{
	t_spot	*spot;

	if (!(spot = (t_spot*)ft_memalloc(sizeof(t_spot))))
	{
		free_file(f, 2);
		free_scn(scn);
		exit(0);
	}
	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	spot->pos = ft_extract_vect(f[*l]);
	*l = ft_skip_com(f, *l + 1, NULL);
	spot->intensity = ft_atof(&(f[*l][ft_strlen("\t\t\tintensity = ")]));
	*l = ft_skip_com(f, *l + 1, NULL);
	ft_get_color(&(spot->color), ft_atox(&(f[*l][ft_strlen("\t\t\tcolor = ")])));
	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	ft_add_to_lst_ui(&scn->ui.spts.lst, spot);
	if (!ft_strcmp(f[*l], "\t\tspot :"))
		spot->next = ft_extract_spot(f, l, scn);
	return (spot);
}
