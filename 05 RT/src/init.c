/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/08 05:32:56 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/20 03:16:56 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

int	ft_init_sdl(t_scene *scn)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("SDL_Init Error : ");
		ft_putendl(SDL_GetError());
		return (0);
	}
	if (!(scn->win = SDL_CreateWindow("RT",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1, 1,
		SDL_WINDOW_FULLSCREEN_DESKTOP)))
	{
		ft_putstr("SDL_CreateWindow Error : ");
		ft_putendl(SDL_GetError());
		SDL_Quit();
		return (0);
	}
	/*
	if (!(scn->win = SDL_CreateWindow("RT",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		1, 1,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED)))
	{
		ft_putstr("SDL_CreateWindow Error : ");
		ft_putendl(SDL_GetError());
		SDL_Quit();
		return (0);
	}
	SDL_SetWindowResizable(scn->win, 0);
	*/
	if (!(scn->rdr = SDL_CreateRenderer(scn->win, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE)))
	{
		ft_putstr("SDL_CreateRenderer Error : ");
		ft_putendl(SDL_GetError());
		SDL_DestroyWindow(scn->win);
		SDL_Quit();
		return (0);
	}
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
