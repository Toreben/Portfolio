/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ui.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 12:46:44 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 09:50:38 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static void	ft_get_bw(uint32_t *src)
{
	int		coord;
	uint8_t	v;

	coord = -1;
	while (++coord < (int)VWPH * (int)VWPW)
	{
		// Uint8 v = 0.212671f * r + 0.715160f * g + 0.072169f * b
		v = 0.212671f * ((src[coord] >> 24) & 0xFF) + 0.715160f * ((src[coord] >> 16) & 0xFF) + 0.072169f * ((src[coord] >> 8) & 0xFF);
		src[coord] = (v << 24) + (v << 16) + (v << 8) + 0xFF;
	}
}

static void	create_filter(t_scene *scn)
{
	uint32_t *bw_px;

	if (!(bw_px = (uint32_t*)ft_memalloc(sizeof(uint32_t) * VWPW * VWPH)))
		exit(0);//leaks
	scn->ui.bw = SDL_CreateTexture(scn->rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, VWPW, VWPH);
	bw_px = ft_memcpy(bw_px, scn->mypx, sizeof(uint32_t) * VWPW * VWPH);
	ft_get_bw(bw_px);
	SDL_UpdateTexture(scn->ui.bw, NULL, (void*)bw_px, VWPW * sizeof (uint32_t));
	free(bw_px);
	scn->ui.sepia = SDL_CreateTexture(scn->rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, VWPW, VWPH);
	SDL_SetRenderTarget(scn->rdr, scn->ui.sepia);
	SDL_SetRenderDrawColor(scn->rdr, 0xBC, 0x6F, 0x3C, 123);
	SDL_RenderClear(scn->rdr);
	SDL_SetRenderTarget(scn->rdr, NULL);
	SDL_SetTextureBlendMode(scn->ui.sepia, SDL_BLENDMODE_MOD);
}

void	draw_window(t_scene *scn)
{
	SDL_RenderCopy(scn->rdr, scn->ui.txr_ui, NULL, NULL);
	SDL_RenderCopy(scn->rdr, scn->viewport.viewport, NULL, &scn->viewport.dst);
	SDL_RenderPresent(scn->rdr);
}

static	int ecriture(t_scene *scn)
{
	SDL_Event 		e;
	SDL_bool		is_sepia_on;
	SDL_bool		is_bw_on;
	void			*selected;
	enum e_type 	elem_type;

	ft_create_ui(scn);
	// print_scroll_boxes(scn);
	rt(scn);
	create_filter(scn);
	draw_window(scn);
	// SDL_RenderCopy(scn->rdr, scn->ui.txr_ui, NULL, NULL);
	// SDL_RenderCopy(scn->rdr, scn->viewport.viewport, NULL, &scn->viewport.dst);
	// SDL_RenderPresent(scn->rdr);
	is_sepia_on = SDL_FALSE;
	is_bw_on = SDL_FALSE;
	elem_type = ERROR;
	while (scn->win)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				SDL_DestroyTexture(scn->ui.sepia);
				SDL_DestroyTexture(scn->ui.bw);
				return (0);
			}
		}
		if (e.type == SDL_KEYUP && e.key.state == SDL_RELEASED)
			key_handler(scn, e, &is_sepia_on, &is_bw_on);
		else if (e.type == SDL_MOUSEWHEEL)
			mouse_wheel_handler(scn, e);
		else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
			mouse_button_handler(scn, &selected, &elem_type);
		SDL_FlushEvent(SDL_MOUSEWHEEL);
		SDL_FlushEvent(SDL_KEYUP);
		SDL_FlushEvent(SDL_MOUSEBUTTONUP);
		e.type = 0;
		SDL_Delay(1000 / 60);
		// printf("%d\n", elem_type);
	}
	TTF_CloseFont(scn->ui.edit.pos_x.font);
	SDL_DestroyTexture(scn->ui.sepia);
	SDL_DestroyTexture(scn->ui.bw);
	return (0);
}

int			ft_ui(t_scene *scn)
{
	// t_scene	scn;

	ft_init_sdl(scn);
	SDL_GetWindowSize(scn->win, &scn->window.w, &scn->window.h);
	printf("%d*%d\n", scn->window.w, scn->window.h);
	//init VP :
	if (!(scn->viewport.viewport = SDL_CreateTexture(scn->rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, (int)VWPW, (int)VWPH)))
		return (0); // free

	scn->viewport.dst = (SDL_Rect){VWPX, VWPY, VWPW, VWPH};

	ecriture(scn);

	free_scn(scn);

	// SDL_DestroyRenderer(scn->rdr);
	// SDL_DestroyWindow(scn->win);
	// SDL_Quit();
	// TTF_Quit();
	return (0);
}
