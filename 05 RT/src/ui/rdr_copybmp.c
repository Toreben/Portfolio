/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rdr_copybmp.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/28 04:35:56 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 23:56:27 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

void rdr_copybmp(SDL_Renderer *rdr, char *txt, SDL_Rect pos)
{
	t_tex		button;
	SDL_Texture *txr_button;
	uint32_t	button_px[BUTTONH][BUTTONW];
	int			x;
	int			y;

	button = ft_parsebmp(open(txt, O_RDONLY));
	if (button.width != BUTTONW || button.height != BUTTONH)//
	{
		printf("Wrong button size\n");
		printf("w = %d h = %d\n", button.width, button.height);
		exit(0);
	}
	txr_button = SDL_CreateTexture(rdr, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, BUTTONW, BUTTONH);
		y = -1;
	while (++y < BUTTONH)
	{
		x = -1;
		while (++x < BUTTONW)
		{
			button_px[y][x] = (button.img[y * BUTTONW + x].r << 24) + (button.img[y * BUTTONW + x].g << 16) + (button.img[y * BUTTONW + x].b << 8) + button.img[y * BUTTONW + x].a;
			// printf("%2x\n", button_px[y][x]);
		}
	}
	SDL_UpdateTexture(txr_button, NULL, (void*)button_px, BUTTONW * sizeof(uint32_t));
	SDL_RenderCopy(rdr, txr_button, NULL, &pos);
	SDL_DestroyTexture(txr_button);
	free(button.img);
}
