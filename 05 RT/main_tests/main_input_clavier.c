/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_input_clavier.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/16 12:46:44 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/02/04 01:53:03 by bnoyer      ###    #+. /#+    ###.fr     */
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
		SDL_WINDOW_FULLSCREEN_DESKTOP)))
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

static	int ecriture(t_scene *scn)
{
	SDL_Event e;
	char	*texte;
	char	*tmp;
	SDL_Rect dstrect;
	t_ui	ui;

	texte = ft_strdup("");
	ui.font = TTF_OpenFont("fonts/Comic Sans MS.ttf", 15);
	ui.color.r = 255;
	ui.color.g = 255;
	ui.color.b = 255;
	SDL_StartTextInput();
	while (scn->win)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT || e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				ft_strdel(&texte);
				return (0);
			}
			else if ((e.type == SDL_TEXTINPUT || e.key.keysym.sym == SDLK_BACKSPACE || e.key.keysym.sym == SDLK_RETURN))
			{
				tmp = texte;
				if ((e.type = SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && ft_strlen(texte) > 0))
				{
					texte = ft_strsub(texte, 0, ft_strlen(texte) - 1);
					ft_strdel(&tmp);
				}
				else if (ft_strlen(texte) < 32)
				{
					texte = ft_strjoin(texte, e.text.text);
					ft_strdel(&tmp);
				}
			}
			else if (e.type == SDL_TEXTEDITING)
			{
				
			}
		}

		SDL_SetRenderDrawColor(scn->rdr, 0, 0, 0, 255);
		SDL_RenderClear(scn->rdr);

		ui.surface = TTF_RenderText_Blended(ui.font, texte, ui.color);
		ui.texture = SDL_CreateTextureFromSurface(scn->rdr, ui.surface);
		SDL_QueryTexture(ui.texture, NULL, NULL, &dstrect.w, &dstrect.h);
		SDL_RenderCopy(scn->rdr, ui.texture, NULL, &dstrect);
		SDL_RenderPresent(scn->rdr);
		SDL_Delay(1000 / 60);
	}
	return (0);
}

int			main()
{
	t_scene	scn;

	// printf("%dx%d\n",scn.window.w, scn.window.h );
	ft_init_sdl(&scn, "test");
	// scn.window.x = 800;
	// scn.window.y = 800;
	SDL_GetWindowSize(scn.win, &scn.window.w, &scn.window.h);
	ecriture(&scn);


	SDL_DestroyRenderer(scn.rdr);
	SDL_DestroyWindow(scn.win);
	SDL_StopTextInput();
	SDL_Quit();
	TTF_Quit();
	return (0);
}
