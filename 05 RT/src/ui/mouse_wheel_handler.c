/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_wheel_handler.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 21:45:48 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 22:23:15 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

void mouse_wheel_handler(t_scene *scn, SDL_Event e)
{
	SDL_Point	mouse_pos;

	SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
	if (hoover(scn->ui.objs.pos, mouse_pos))
	{
		if ((e.wheel.y < 0 && can_scroll_up(scn->ui.objs)) || (0 < e.wheel.y && can_scroll_down(scn->ui.objs)))
		{
			scn->ui.objs.first_y -= 5 * (e.wheel.y < 0 ? -1 : 1);
			print_scroll(scn->rdr, &scn->ui.objs, scn->ui.txr_ui);
			draw_window(scn);
		}
	}
	if (hoover(scn->ui.spts.pos, mouse_pos))
	{
		if ((e.wheel.y < 0 && can_scroll_up(scn->ui.spts)) || (0 < e.wheel.y && can_scroll_down(scn->ui.spts)))
		{
			scn->ui.spts.first_y -= 5 * (e.wheel.y < 0 ? -1 : 1);
			print_scroll(scn->rdr, &scn->ui.spts, scn->ui.txr_ui);
			draw_window(scn);
		}
	}
}
