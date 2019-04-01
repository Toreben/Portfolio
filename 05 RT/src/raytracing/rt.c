/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   rt.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/21 14:38:06 by mhervet      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/15 21:50:50 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

// static void		ft_put_pixel(uint32_t *dst, int x, int y, t_color col)
// {	
// 	// SDL_SetRenderDrawcol(rdr, col.r, col.g, col.b, col.a);
// 	// if (col.r == 0 && col.b == 0 && col.g == 0)
// 	// 	SDL_SetRenderDrawcol(rdr, 255, 255, 255, 255);
// 	// SDL_RenderDrawPoint(rdr, x, y);
// 	// printf("px[%d][%d] = #%x\n", x, y, (col.r << 24) + (col.g << 16) + (col.b << 8) + col.a);
// 	dst[(y * (int)VWPW) + x] = (col.r << 24) + (col.g << 16) + (col.b << 8) + col.a;
// }

static t_color		ft_closest(t_scene *scn, t_vector ray)
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
		// printf("%p\n", tmp);
	}
	if (min > 0 && obj)
		return (ft_shading(scn, ft_v_add(scn->cam.pos, ft_v_scal(min, ray)),
			obj->norm_obj(ft_v_add(scn->cam.pos, ft_v_scal(min, ray)), obj), obj));
	return ((t_color){.r = 0, .g = 0, .b = 0, .a = 0});
}

static void		ft_aa(t_scene *scn, t_vector ray, int x, int y)
{
	double		delta;
	int			i;
	int			j;
	t_vector	rotray;
	t_color		color_px;

	delta = 1. / (scn->aa + 1.);
	color_px = (t_color){.r = 0, .g = 0, .b = 0, .a = 0};
	j = -1;
	while (++j <= scn->aa)
	{
		ray.y = (1 - 2 * ((y + ((j + 0.5) * delta)) / VWPH)) * TANFOV;
		i = -1;
		while (++i <= scn->aa)
		{
			ray.x = (((x + ((i + 0.5) * delta)) / VWPW) * 2 - 1) * (VWPW / VWPH) * TANFOV;
			rotray = ft_rotate(scn, ray);
			color_px = ft_color_sum(color_px, ft_closest(scn, rotray));
		}
	}
	ft_color_pond(&color_px, (scn->aa + 1) * (scn->aa + 1));
	// printf("%d %d %d\n", color_px.r, color_px.g, color_px.b);
	scn->mypx[(y * (int)VWPW) + x] = (color_px.r << 24) + (color_px.g << 16) + (color_px.b << 8) + color_px.a;
}

static void		*ft_raytracing(void *param)
{
	int			i;
	int			j;
	t_vector	ray;
	t_thread	*thread;
	t_scene		*scn;

	thread = (t_thread*)param;
	scn = (t_scene*)thread->scn;

	j = (thread->num_thread * VWPH / NB_THREAD) - 1;
	ray.z = -1 * scn->cam.dist;
	while (++j < ((thread->num_thread + 1) * VWPH / NB_THREAD))
	{
		i = -1;
		while (++i < VWPW)
			ft_aa(scn, ray, i, j);
	}
	free(thread->scn);
	free(thread);
	pthread_exit(NULL);
}

/*
**	int				rt(t_scene *scn/\*, char *scn_name*\/)
**	{
**		SDL_Event	e;
**		char		**split;
**		char		*name;
**		char		ret;
**	
**		split = ft_strsplit(scn_name, '/');
**		name = ft_strjoin("RT - ", split[ft_strstrlen(split) - 1]);
**		ft_free_strstr(split);
**		ret = ft_init_sdl(scn, name);
**		ft_strdel(&name);
**		if (!ret)
**		if (!ft_init_sdl(scn))
**			return (0);
**		SDL_SetRenderDrawColor(scn->rdr, 0, 0, 0, 255);
**		SDL_RenderClear(scn->rdr);
**		ft_raytracing(scn);
**		SDL_RenderPresent(scn->rdr);
**		while (scn->win)
**			while (SDL_WaitEvent(&e))
**				if (e.type == SDL_QUIT ||
**					e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
**					return (0);
**		return (0);
**	}
*/

int				rt(t_scene *scn)
{
	int				i;
	pthread_t		arr_thd[NB_THREAD];
	t_thread		*thread;


	if (!(scn->mypx = (uint32_t*)ft_memalloc(sizeof(uint32_t) * VWPH * VWPW)))
		return (0); // free
	i = -1;
	while (++i < NB_THREAD)
	{//leaks
		if (!(thread = (t_thread*)ft_memalloc(sizeof(t_thread))))
			exit(0);
		thread->num_thread = i;
		if (!(thread->scn = (t_scene*)ft_memalloc(sizeof(t_scene))))
			exit(0);
		*(thread->scn) = *scn;
		pthread_create(&arr_thd[i], NULL, ft_raytracing, thread);
	}
	i = -1;
	while (++i < NB_THREAD)
		pthread_join(arr_thd[i], NULL);
	SDL_UpdateTexture(scn->viewport.viewport, NULL, (void*)scn->mypx, VWPW * sizeof (uint32_t));
	// SDL_RenderCopy(scn->rdr, scn->viewport.viewport, NULL, &scn->viewport.dst);
	return (0);
}
