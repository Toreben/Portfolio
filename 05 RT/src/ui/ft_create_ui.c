/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_ui.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 22:37:05 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 05:48:19 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static void		ft_generate_scroll_box(t_scene *scn, t_scroll_box *box, TTF_Font *font)
{
	t_scroll_box_elem	*tmp;
	int 				y;

	box->box = SDL_CreateTexture(scn->rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCROLLW, SCROLLH);
	tmp = box->lst;
	y = 0;
	box->first_y = 0;
	while (tmp)
	{
		tmp->txr = load_text(scn->rdr, tmp->name, font, (SDL_Color){0xFF, 0xFF, 0xFF, 0xFF});
		tmp->rect_pos = (SDL_Rect){.x = 5, .y = y};
		SDL_QueryTexture(tmp->txr, NULL, NULL, &(tmp->rect_pos.w), &(tmp->rect_pos.h));
		y += 25;
		tmp = tmp->next;
	}
}
// #0a2460 => elem color
// #0b3491 => box color
// #071B49 => ui color
// #777777 => placeholder color
static void	print_scroll_boxes(t_scene *scn)
{
	print_scroll(scn->rdr, &scn->ui.objs, scn->ui.txr_ui);
	print_scroll(scn->rdr, &scn->ui.spts, scn->ui.txr_ui);
}

void 		ft_create_ui(t_scene *scn)
{
	t_ui		*ui;
	TTF_Font	*font;
	
	ui = &(scn->ui);
	ui->txr_ui = SDL_CreateTexture(scn->rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, scn->window.w, scn->window.h);
	SDL_SetRenderTarget(scn->rdr, ui->txr_ui);
	SDL_SetRenderDrawColor(scn->rdr, 0x07, 0x1B, 0x49, 255);
	SDL_RenderClear(scn->rdr);

	font = TTF_OpenFont("fonts/Arial.ttf", 18);
	
	scn->ui.rect_modify = (SDL_Rect){.x = BUTONX, .y = MODIFY_Y, .w = BUTTONW, .h = BUTTONH};
	rdr_copybmp(scn->rdr, "buttons/modify.bmp", scn->ui.rect_modify);
	
	scn->ui.rect_add = (SDL_Rect){.x = BUTONX, .y = ADD_Y, .w = BUTTONW, .h = BUTTONH};
	rdr_copybmp(scn->rdr, "buttons/add.bmp", scn->ui.rect_add);

	ui->objs.pos = (SDL_Rect){.x = SCROLL_OBJ_X, .y = SCROLLY, .w = SCROLLW, .h = SCROLLH};
	ft_generate_scroll_box(scn, &ui->objs, font);

	ui->spts.pos = (SDL_Rect){.x = SCROLL_SPT_X, .y = SCROLLY, .w = SCROLLW, .h = SCROLLH};
	ft_generate_scroll_box(scn, &scn->ui.spts, font);

	print_scroll_boxes(scn);
	
	SDL_SetRenderTarget(scn->rdr, scn->ui.txr_ui);
	ft_generate_edit_zone(scn->rdr, &(ui->edit), font);
	SDL_SetRenderTarget(scn->rdr, NULL);
}
