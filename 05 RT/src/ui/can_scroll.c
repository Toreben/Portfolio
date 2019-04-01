/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   can_scroll.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 00:34:19 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 21:40:27 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static SDL_bool is_in_txr(SDL_Rect txr, SDL_Rect label)
{
	// printf("label : %d %d %d %d\t", label.x, label.y, label.w, label.h);
	// printf("txr : %d %d %d %d\n", 0, 0, txr.w, txr.h);
	if (0 <= label.x && label.x + label.w <= txr.w
		&& 0 <= label.y && label.y + label.h <= txr.h)
		return (SDL_TRUE);
	return (SDL_FALSE);
}

SDL_bool can_scroll_down(t_scroll_box box)
{
	t_scroll_box_elem	*tmp;
	t_scroll_box_elem	*tail;

	tmp = box.lst;
	tail = tmp;
	while (tmp)
	{
		tail = tmp;
		tmp = tmp->next;
	}
	return (!is_in_txr(box.pos, tail->rect_pos));
}

SDL_bool can_scroll_up(t_scroll_box box)
{
	return (!is_in_txr(box.pos, box.lst->rect_pos));
}
