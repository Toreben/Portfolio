/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_handler.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 21:39:34 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/27 22:27:21 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

void key_handler(t_scene *scn, SDL_Event e, SDL_bool *is_sepia_on, SDL_bool *is_bw_on)
{
	if (e.key.keysym.scancode == SDL_SCANCODE_1)
	{
		SDL_RenderCopy(scn->rdr, scn->ui.txr_ui, NULL, NULL);
		if (*is_sepia_on)
		{
			SDL_RenderCopy(scn->rdr, scn->viewport.viewport, NULL, &scn->viewport.dst);
			*is_sepia_on = SDL_FALSE;
		}
		else
		{
			SDL_RenderCopy(scn->rdr, scn->ui.bw, NULL, &scn->viewport.dst);
			SDL_RenderCopy(scn->rdr, scn->ui.sepia, NULL, &scn->viewport.dst);
			*is_sepia_on = SDL_TRUE;
			*is_bw_on = SDL_FALSE;
		}
		SDL_RenderPresent(scn->rdr);
	}
	else if (e.key.keysym.scancode == SDL_SCANCODE_2)
	{
		SDL_RenderCopy(scn->rdr, scn->ui.txr_ui, NULL, NULL);
		if (*is_bw_on)
		{
			SDL_RenderCopy(scn->rdr, scn->viewport.viewport, NULL, &scn->viewport.dst);
			*is_bw_on = SDL_FALSE;
		}
		else
		{
			SDL_RenderCopy(scn->rdr, scn->ui.bw, NULL, &scn->viewport.dst);
			*is_sepia_on = SDL_FALSE;
			*is_bw_on = SDL_TRUE;
		}
		SDL_RenderPresent(scn->rdr);
	}
}
