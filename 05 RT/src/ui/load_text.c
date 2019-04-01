/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   load_text.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 21:19:31 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/29 20:04:38 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

SDL_Texture *load_text(SDL_Renderer *rdr, char *txt, TTF_Font *font, SDL_Color col)
{
	SDL_Texture	*ret;
	SDL_Surface *srf;

	srf = TTF_RenderText_Blended(font, txt, (SDL_Color){col.r, col.g, col.b, col.a}/*, (SDL_Color){0x0A, 0x24, 0x60, 0xFF}*/);
	ret = SDL_CreateTextureFromSurface(rdr, srf);
	SDL_FreeSurface(srf);
	return (ret);
}
