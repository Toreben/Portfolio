/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_button_handler.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/27 22:13:56 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/04/01 17:10:56 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static void dispaly_content(SDL_Renderer *rdr, SDL_Texture *tb, t_text_box *to_display)
{
	SDL_Rect	dst;

	dst = to_display->pos;
	to_display->content_display = load_text(rdr, to_display->content, to_display->font, (SDL_Color){0, 0, 0, 0xFF});
	SDL_RenderCopy(rdr, tb, NULL, &to_display->pos);
	SDL_QueryTexture(to_display->content_display, NULL, NULL, &dst.w, &dst.h);
	dst.x += 5;
	dst.y += ((to_display->pos.h - dst.h) / 2);
	SDL_RenderSetClipRect(rdr, &to_display->pos);
	SDL_RenderCopy(rdr, to_display->content_display, NULL, &dst);
	SDL_RenderSetClipRect(rdr, NULL);
}

static void display_spot(t_scene *scn, t_spot to_display)
{
	t_edit_zone *zone;
	
	zone = &scn->ui.edit;

	SDL_SetRenderTarget(scn->rdr, scn->ui.txr_ui);
	zone->pos_x.content = ft_itoa(to_display.pos.x);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->pos_x);
	zone->pos_y.content = ft_itoa(to_display.pos.y);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->pos_y);
	zone->pos_z.content = ft_itoa(to_display.pos.z);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->pos_z);
	zone->size.content = ft_itoa(to_display.intensity);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->size);
	zone->colour.content = ft_itoa((to_display.color.r << 16) + (to_display.color.g << 8) + to_display.color.b);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->colour);
	SDL_SetRenderTarget(scn->rdr, NULL);

	draw_window(scn);
}

static void display_obj(t_scene *scn, t_object to_display)
{
	t_edit_zone *zone;
	
	zone = &scn->ui.edit;
	SDL_SetRenderTarget(scn->rdr, scn->ui.txr_ui);

	zone->pos_x.content = ft_itoa(to_display.pos.x);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->pos_x);
	zone->pos_y.content = ft_itoa(to_display.pos.y);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->pos_y);
	zone->pos_z.content = ft_itoa(to_display.pos.z);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->pos_z);

	zone->dir_x.content = ft_itoa(to_display.pos.x);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->dir_x);
	zone->dir_y.content = ft_itoa(to_display.pos.y);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->dir_y);
	zone->dir_z.content = ft_itoa(to_display.pos.z);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->dir_z);

	zone->size.content = ft_itoa(to_display.size);
	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->size);
	zone->colour.content = ft_itoa((to_display.color.r << 16) + (to_display.color.g << 8) + to_display.color.b);

	dispaly_content(scn->rdr, scn->ui.edit.tb_img, &zone->colour);
	SDL_SetRenderTarget(scn->rdr, NULL);

	draw_window(scn);
}

static void	bite(t_scene *scn, void **selected, enum e_type *type, SDL_Point mouse_pos)
{
	if (hoover(scn->ui.objs.pos, mouse_pos) || hoover(scn->ui.spts.pos, mouse_pos))
	{
		*type = get_lst_elem_infos(scn, mouse_pos, selected);
	}
	else if (hoover(scn->ui.rect_modify, mouse_pos) && *type != ERROR)
	{
		if (*type == SPOT)
			display_spot(scn, *(t_spot*)*selected);
		else if (*type == ERROR)
			printf("NONE\n");
		else
			display_obj(scn, *(t_object*)*selected);
	}
}

void mouse_button_handler(t_scene *scn, void **selected, enum e_type *type)
{
	SDL_Point	mouse_pos;

	SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
	if (hoover((SDL_Rect){.x = SELECT_X, .y = SELECT_Y, .w = SELECT_W, .h = SELECT_H}, mouse_pos))
	{
		bite(scn, selected, type, mouse_pos);
		printf("%d\n", *type);
	}
	if (hoover((SDL_Rect){.x = EDIT_X, .y = EDIT_Y, .w = EDIT_W, .h = EDIT_H}, mouse_pos))
	{
		printf("edit zone\n");
	}
}

