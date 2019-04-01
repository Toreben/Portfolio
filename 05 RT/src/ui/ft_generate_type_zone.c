/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_generate_type_zone.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/30 02:54:00 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 05:54:49 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static SDL_Texture	*rdr_copyicone(SDL_Renderer *rdr, char *txt)
{
	t_tex		button;
	SDL_Texture *txr_button;
	uint32_t	button_px[ICONE_SIZE][ICONE_SIZE];
	int			x;
	int			y;

	button = ft_parsebmp(open(txt, O_RDONLY));
	if (button.width != ICONE_SIZE || button.height != ICONE_SIZE)//
	{
		printf("Wrong button size\n");
		printf("w = %d h = %d\n", button.width, button.height);
		exit(0);
	}
	txr_button = SDL_CreateTexture(rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, ICONE_SIZE, ICONE_SIZE);
		y = -1;
	while (++y < ICONE_SIZE)
	{
		x = -1;
		while (++x < ICONE_SIZE)
		{
			button_px[y][x] = (button.img[y * ICONE_SIZE + x].r << 24) + (button.img[y * ICONE_SIZE + x].g << 16) + (button.img[y * ICONE_SIZE + x].b << 8) + button.img[y * ICONE_SIZE + x].a;
			// printf("%2x\n", button_px[y][x]);
		}
	}
	SDL_UpdateTexture(txr_button, NULL, (void*)button_px, ICONE_SIZE * sizeof(uint32_t));
	free(button.img);
	return (txr_button);
}

static void create_type(SDL_Renderer *rdr, SDL_Rect *pos, char *txt, char *icone, TTF_Font *font)
{
	SDL_Texture *tmp;
	SDL_Rect	dst;

	tmp = rdr_copyicone(rdr, icone);
 	dst = (SDL_Rect){.x = pos->x + pos->w - ICONE_SIZE, .y = pos->y + (pos->h - ICONE_SIZE) / 2, .w = ICONE_SIZE, .h = ICONE_SIZE};
	SDL_RenderCopy(rdr, tmp, NULL, &dst);	
	SDL_DestroyTexture(tmp);

	tmp = load_text(rdr, txt, font, (SDL_Color){0xFF, 0xFF, 0xFF, 0xFF});
	SDL_QueryTexture(tmp, NULL, NULL, &dst.w, &dst.h);
	dst = (SDL_Rect){.x = pos->x + 15, .y = pos->y + (pos->h - dst.h) / 2, .w = dst.w, .h = dst.h};
	SDL_RenderCopy(rdr, tmp, NULL, &dst);
	SDL_DestroyTexture(tmp);
}

void	ft_generate_type_zone(SDL_Renderer *rdr, t_select_type_zone *zone, TTF_Font *font)
{
	// zone->txr = SDL_CreateTexture(rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, TYPE_ZONE_W, TYPE_ZONE_H);//
	zone->pos = (SDL_Rect){.x = TYPE_ZONE_X, .y = TYPE_ZONE_Y, .w = TYPE_ZONE_W, .h = TYPE_ZONE_H};
	zone->sph =(SDL_Rect){.x = TYPE_ZONE_X, .y = (TYPE_ZONE_ELEM_H * 0) + TYPE_ZONE_Y, .w = TYPE_ZONE_ELEM_W, .h = TYPE_ZONE_ELEM_H};
	create_type(rdr, &zone->sph, "Sphere", "buttons/sphere.bmp", font);
	zone->pln =(SDL_Rect){.x = TYPE_ZONE_X, .y = (TYPE_ZONE_ELEM_H * 1) + TYPE_ZONE_Y, .w = TYPE_ZONE_ELEM_W, .h = TYPE_ZONE_ELEM_H};
	create_type(rdr, &zone->pln, "Plane", "buttons/plane.bmp", font);
	zone->con =(SDL_Rect){.x = TYPE_ZONE_X, .y = (TYPE_ZONE_ELEM_H * 2) + TYPE_ZONE_Y, .w = TYPE_ZONE_ELEM_W, .h = TYPE_ZONE_ELEM_H};
	create_type(rdr, &zone->con, "Cone", "buttons/cone.bmp", font);
	zone->cld =(SDL_Rect){.x = TYPE_ZONE_X, .y = (TYPE_ZONE_ELEM_H * 3) + TYPE_ZONE_Y, .w = TYPE_ZONE_ELEM_W, .h = TYPE_ZONE_ELEM_H};
	create_type(rdr, &zone->cld, "Cylinder", "buttons/cylinder.bmp", font);
	zone->spt =(SDL_Rect){.x = TYPE_ZONE_X, .y = (TYPE_ZONE_ELEM_H * 4) + TYPE_ZONE_Y, .w = TYPE_ZONE_ELEM_W, .h = TYPE_ZONE_ELEM_H};
	create_type(rdr, &zone->spt, "Spot", "buttons/spot.bmp", font);
}
