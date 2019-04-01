/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_generate_edit_zone.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 04:37:35 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 11:27:59 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static SDL_Texture *tb_rdr_copybmp(SDL_Renderer *rdr)
{
	t_tex		button;
	SDL_Texture *txr_button;
	uint32_t	button_px[TEXT_BOX_H][TEXT_BOX_W];
	int			x;
	int			y;

	button = ft_parsebmp(open("buttons/tb.bmp", O_RDONLY));
	if (button.width != TEXT_BOX_W || button.height != TEXT_BOX_H)//
	{
		printf("Wrong TB size\n");
		exit(0);
	}
	txr_button = SDL_CreateTexture(rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, TEXT_BOX_W, TEXT_BOX_H);//
	y = -1;
	while (++y < TEXT_BOX_H)
	{
		x = -1;
		while (++x < TEXT_BOX_W)
		{
			button_px[y][x] = (button.img[y * TEXT_BOX_W + x].r << 24) + (button.img[y * TEXT_BOX_W + x].g << 16) + (button.img[y * TEXT_BOX_W + x].b << 8) + button.img[y * TEXT_BOX_W + x].a;
			// printf("%2x\n", button_px[y][x]);
		}
	}
	SDL_UpdateTexture(txr_button, NULL, (void*)button_px, TEXT_BOX_W * sizeof(uint32_t));
	free(button.img);
	return (txr_button);
}

static void	generate_text_box(SDL_Renderer *rdr, t_text_box *tb, SDL_Rect dst, char *ph, SDL_Texture *tb_img)
{
	tb->pos = dst;
	tb->placeholder = load_text(rdr, ph, tb->font, (SDL_Color){0x77, 0x77, 0x77, 0xFF});
	tb->content = NULL;
	SDL_RenderCopy(rdr, tb_img, NULL, &tb->pos);
	SDL_QueryTexture(tb->placeholder, NULL, NULL, &dst.w, &dst.h);
	dst.x += 5;
	dst.y += ((tb->pos.h - dst.h) / 2);
	SDL_RenderSetClipRect(rdr, &tb->pos);
	SDL_RenderCopy(rdr, tb->placeholder, NULL, &dst);
	SDL_RenderSetClipRect(rdr, NULL);
}

void	ft_generate_edit_zone(SDL_Renderer *rdr, t_edit_zone *zone, TTF_Font *font)
{
	zone->tb_img = tb_rdr_copybmp(rdr);
	zone->pos_x.font = font;
	generate_text_box(rdr, &zone->pos_x, (SDL_Rect){.x = TB_PX_X, .y = TB_PX_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "x position", zone->tb_img);
	zone->pos_y.font = font;
	generate_text_box(rdr, &zone->pos_y, (SDL_Rect){.x = TB_PY_X, .y = TB_PY_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "y position", zone->tb_img);
	zone->pos_z.font = font;
	generate_text_box(rdr, &zone->pos_z, (SDL_Rect){.x = TB_PZ_X, .y = TB_PZ_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "z position", zone->tb_img);

	zone->dir_x.font = font;
	generate_text_box(rdr, &zone->dir_x, (SDL_Rect){.x = TB_DX_X, .y = TB_DX_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "x direction", zone->tb_img);
	zone->dir_y.font = font;
	generate_text_box(rdr, &zone->dir_y, (SDL_Rect){.x = TB_DY_X, .y = TB_DY_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "y direction", zone->tb_img);
	zone->dir_z.font = font;
	generate_text_box(rdr, &zone->dir_z, (SDL_Rect){.x = TB_DZ_X, .y = TB_DZ_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "z direction", zone->tb_img);

	zone->size.font = font;
	generate_text_box(rdr, &zone->size, (SDL_Rect){.x = TB_SIZE_X, .y = TB_SIZE_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "Size", zone->tb_img);
	zone->colour.font = font;
	generate_text_box(rdr, &zone->colour, (SDL_Rect){.x = TB_COL_X, .y = TB_COL_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "Colour", zone->tb_img);
	zone->transparency.font = font;
	generate_text_box(rdr, &zone->transparency, (SDL_Rect){.x = TB_TRANSP_X, .y = TB_TRANSP_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "Transparency", zone->tb_img);
	zone->txr_path.font = font;
	generate_text_box(rdr, &zone->txr_path, (SDL_Rect){.x = TB_TXR_PATH_X, .y = TB_TXR_PATH_Y, .w = TEXT_BOX_W, .h = TEXT_BOX_H}, "Texture path", zone->tb_img);
	ft_generate_type_zone(rdr, &zone->sel, font);
}
