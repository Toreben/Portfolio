/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rtv1.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/21 14:38:06 by mhervet      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 18:45:15 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static void		ft_put_pixel(SDL_Renderer *rdr, int x, int y, t_uint color)
{
	Uint8	r;
	Uint8	g;
	Uint8	b;
	Uint8	a;

	r = (color & 0xFF000000) >> 24;
	g = (color & 0x00FF0000) >> 16;
	b = (color & 0x0000FF00) >> 8;
	a = color & 0x000000FF;
	SDL_SetRenderDrawColor(rdr, r, g, b, a);
	SDL_RenderDrawPoint(rdr, x, y);
}

static void		ft_closest(t_scene *scn, t_vector ray, int i, int j)
{
	t_object	*tmp;
	t_object	*obj;
	double		dist;
	double		min;

	tmp = scn->content;
	obj = NULL;
	min = INFINITY;
	while (tmp)
	{
		dist = tmp->hit(scn->cam.pos, tmp, ray);
		if (dist < min)
		{
			min = dist;
			obj = tmp;
		}
		tmp = tmp->next;
	}
	if (min > 0 && obj)
		ft_put_pixel(scn->rdr, i, j, ft_shading(scn, ft_v_add(scn->cam.pos,
	ft_v_scal(min, ray)),
		obj->norm_obj(ft_v_add(scn->cam.pos, ft_v_scal(min, ray)), obj), obj));
}

static void		ft_raytracing(t_scene *scn)
{
	int			i;
	int			j;
	t_vector	ray;
	t_vector	rotray;

	j = -1;
	ray.z = -1 * scn->cam.dist;
	while (++j < scn->view.h)
	{
		i = -1;
		ray.y = (1 - 2 * ((j + 0.5) / scn->view.h)) * tan(FOV);
		while (++i < scn->view.w)
		{
			ray.x = (((i + 0.5) / scn->view.w) * 2 - 1) *
										(scn->view.w / scn->view.h) * tan(FOV);
			ft_v_normalize(ray);
			rotray = ft_rotate(scn, ray);
			ft_closest(scn, rotray, i, j);
		}
	}
}

static int		ft_init_sdl(t_scene *scn, char *name)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_putstr("SDL_Init Error : ");
		ft_putendl(SDL_GetError());
		return (0);
	}
	if (!(scn->win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, scn->view.w, scn->view.h, SDL_WINDOW_SHOWN)))
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
	return (1);
}

int				rtv1(t_scene *scn, char *scn_name)
{
	SDL_Event	e;
	char		**split;
	char		*name;

	split = ft_strsplit(scn_name, '/');
	name = ft_strjoin("RTv1 - ", split[ft_strstrlen(split) - 1]);
	ft_free_strstr(split);
	if (!ft_init_sdl(scn, name))
	{
		ft_strdel(&name);
		return (0);
	}
	ft_strdel(&name);
	SDL_SetRenderDrawColor(scn->rdr, 0, 0, 0, 255);
	SDL_RenderClear(scn->rdr);
	ft_raytracing(scn);
	SDL_RenderPresent(scn->rdr);
	while (scn->win)
		while (SDL_PollEvent(&e))
			if (e.type == SDL_QUIT ||
				e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				return (0);
	return (0);
}
