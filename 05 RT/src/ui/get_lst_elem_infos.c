/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_lst_elem_infos.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 23:35:33 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 09:51:27 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static void *find_select(t_scroll_box_elem *lst, SDL_Point mouse_pos)
{
	t_scroll_box_elem *tmp;

	tmp = lst;
	while (tmp && !hoover(tmp->rect_pos, mouse_pos))
		tmp = tmp->next;
	printf("%p\n", tmp);
	if (tmp)
		return (tmp->address);
	printf("test\n");
	return (NULL);
}

enum e_type get_lst_elem_infos(t_scene *scn, SDL_Point mouse_pos, void **selected)
{
	if (hoover(scn->ui.objs.pos, mouse_pos))
	{
		printf("hoover objs\n");
		*selected = find_select(scn->ui.objs.lst, (SDL_Point){.x = mouse_pos.x - scn->ui.objs.pos.x, .y = mouse_pos.y - scn->ui.objs.pos.y});
		if (*selected)
			return (((t_object*)(*selected))->type);
	}
	else if (hoover(scn->ui.spts.pos, mouse_pos))
	{
		printf("hoover spts\n");
		*selected = find_select(scn->ui.spts.lst, (SDL_Point){.x = mouse_pos.x - scn->ui.spts.pos.x, .y = mouse_pos.y - scn->ui.spts.pos.y});
		if (*selected)
			return (SPOT);
	}
	return (ERROR);
}

