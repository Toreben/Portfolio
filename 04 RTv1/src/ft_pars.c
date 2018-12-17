/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_pars.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 15:41:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 22:40:51 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static t_scene	*ft_get_view(char **f, int *l, t_scene *scn)
{
	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	scn->cam = ft_extract_camera(f, l);
	*l = ft_skip_com(f, *l + 1, NULL);
	scn->view = ft_extract_viewport(f, l);
	*l = ft_skip_com(f, *l + 1, NULL);
	if (!ft_strcmp(f[*l], "\t\tspot :"))
		scn->spt = ft_extract_spot(f, l, scn);
	else
		scn->spt = NULL;
	return (scn);
}

t_scene			*ft_pars(char **f)
{
	t_scene	*scene;
	int		l;

	if (!(scene = (t_scene*)ft_memalloc(sizeof(t_scene))))
		exit(0);
	scene->spt = NULL;
	scene->content = NULL;
	l = ft_skip_com(f, 0, NULL);
	l = ft_skip_com(f, l + 1, NULL);
	l = ft_skip_com(f, l + 1, NULL);
	scene = ft_get_view(f, &l, scene);
	l = ft_skip_com(f, l + 1, NULL);
	if (!ft_strcmp(f[l], "\tobjects :"))
	{
		l = ft_skip_com(f, l + 1, NULL);
		l = ft_skip_com(f, l + 1, NULL);
		scene->content = ft_extract_object(f, &l, scene);
	}
	else
		scene->content = NULL;
	return (scene);
}
