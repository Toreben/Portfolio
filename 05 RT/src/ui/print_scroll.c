/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_scroll.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 22:29:02 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 22:29:05 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static void		ecriture_scroll_box(SDL_Renderer *rdr, t_scroll_box *box)
{
	t_scroll_box_elem	*tmp;
	int					y;

	SDL_SetRenderTarget(rdr, box->box);
	y = box->first_y;
	SDL_SetRenderDrawColor(rdr, 0x0B, 0x34, 0x91, 0xFF);
	SDL_RenderClear(rdr);
	tmp = box->lst;
	while (tmp)
	{
		tmp->rect_pos.y += y;
		SDL_RenderCopy(rdr, tmp->txr, NULL, &(tmp->rect_pos));
		tmp = tmp->next;
	}
	SDL_SetRenderTarget(rdr, NULL);
}

void	print_scroll(SDL_Renderer *rdr, t_scroll_box *to_print, SDL_Texture *txr_target)
{
	ecriture_scroll_box(rdr, to_print);
	SDL_SetRenderTarget(rdr, txr_target);
	SDL_RenderCopy(rdr, to_print->box, NULL, &(to_print->pos));
	SDL_SetRenderTarget(rdr, NULL);
}
