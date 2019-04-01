/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mainaffichagettf.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 12:46:44 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 19:26:50 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static int	ft_init_ttf(t_scene *scn)
{
	if (TTF_Init() == -1)
	{
		ft_putstr("TTF_Init Error : ");
		ft_putendl(TTF_GetError());
		SDL_DestroyWindow(scn->win);
		SDL_Quit();
		return (0);
	}
	return (1);
}

int	ft_init_sdl(t_scene *scn, char *name)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("SDL_Init Error : ");
		ft_putendl(SDL_GetError());
		return (0);
	}
	if (!(scn->win = SDL_CreateWindow(name,
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1, 1,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED)))
	{
		ft_putstr("SDL_CreateWindow Error : ");
		ft_putendl(SDL_GetError());
		SDL_Quit();
		return (0);
	}
	if (!(scn->rdr = SDL_CreateRenderer(scn->win, -1,
		SDL_RENDERER_ACCELERATED)))
	{
		ft_putstr("SDL_CreateRenderer Error : ");
		ft_putendl(SDL_GetError());
		SDL_DestroyWindow(scn->win);
		SDL_Quit();
		return (0);
	}
	return (ft_init_ttf(scn));
}

static	int ecriture(t_scene *scn, SDL_Texture *text)
{
	SDL_Event e;

	int texW = 0;
	int texH = 0;
	SDL_Rect dstrect;

	SDL_QueryTexture(text, NULL, NULL, &texW, &texH);
	dstrect.x = scn->window.w / 2;
	dstrect.y = scn->window.h / 2;
	dstrect.w = texW;
	dstrect.h = texH;

	while (scn->win)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT ||
				e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				return (0);
			else if (e.type == SDL_WINDOWEVENT)
				if (e.window.event == SDL_WINDOWEVENT_RESIZED)
				{
					printf("Window resized to %d * %d\n", e.window.data1, e.window.data2);
					printf("Old window : %d * %d\n", scn->window.w, scn->window.h);
					scn->window.w = e.window.data1;
					scn->window.h = e.window.data2;
					printf("New window : %d * %d\n", scn->window.w, scn->window.h);
					dstrect.x = scn->window.w / 2;
					dstrect.y = scn->window.h / 2;
					ft_redraw_ui(scn);
				}
		}
		SDL_SetRenderDrawColor(scn->rdr, 0, 0, 0, 255);
		SDL_RenderClear(scn->rdr);
		SDL_RenderCopy(scn->rdr, text, NULL, &dstrect);
		SDL_RenderPresent(scn->rdr);
		SDL_Delay(1000 / 60);
	}
	return (0);
}

int			main()
{
	t_ui	ui;
	t_scene	scn;

	ft_init_sdl(&scn, "test");
	scn.window.x = 0;
	scn.window.y = 0;
	SDL_GetWindowSize(scn.win, &scn.window.w, &scn.window.h);
	printf("Size : %d %d\n",scn.window.w, scn.window.h );
	ui.font = TTF_OpenFont("fonts/Comic Sans MS.ttf", 15);
	ui.color.r = 255;
	ui.color.g = 255;
	ui.color.b = 255;
	ui.surface = TTF_RenderText_Blended(ui.font, "Hello World !", ui.color);
	ui.texture = SDL_CreateTextureFromSurface(scn.rdr, ui.surface);
	ecriture(&scn, ui.texture);

	SDL_DestroyTexture(ui.texture); //?
	SDL_FreeSurface(ui.surface);
	SDL_DestroyRenderer(scn.rdr);
	SDL_DestroyWindow(scn.win);
	SDL_Quit();
	TTF_Quit();
	return (0);
}
