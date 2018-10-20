/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   creation.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 14:28:18 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:20:49 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static t_image	create_img(void *mlx_ptr)
{
	t_image	img;

	img.img_ptr = mlx_new_image(mlx_ptr, IMG_X, WIN_Y);
	img.img_str = (unsigned int*)mlx_get_data_addr(img.img_ptr, &img.bpp,
		&img.s_l, &img.endian);
	return (img);
}

static char		create_color(char *color)
{
	if (!ft_strcmp(color, "notum terram"))
		return ('n');
	else if (!ft_strcmp(color, "fire"))
		return ('f');
	else if (!ft_strcmp(color, "paon pan pan"))
		return ('p');
	else if (!ft_strcmp(color, "rafletnaug"))
		return ('r');
	else if (!ft_strcmp(color, "kouign amann"))
		return ('k');
	else if (!ft_strcmp(color, "mars"))
		return ('m');
	else
		return ('l');
}

t_window		*create_win(t_window *win, char *title, char *color)
{
	win->mlx_ptr = mlx_init();
	win->img = create_img(win->mlx_ptr);
	win->title = title;
	win->fac = FAC;
	win->fac_z = 1;
	win->omega.deg = OMEGA;
	win->alpha.deg = ALPHA;
	win->omega = ft_update_angle(win->omega);
	win->alpha = ft_update_angle(win->alpha);
	win->rx.ang.deg = 0;
	win->rx = fill_mat_x(win->rx);
	win->ry.ang.deg = 0;
	win->ry = fill_mat_y(win->ry);
	win->rz.ang.deg = 0;
	win->rz = fill_mat_z(win->rz);
	win->rot = mult_matrix_matrix(mult_matrix_matrix(win->rz, win->ry),
		win->rx);
	win->color = create_color(color);
	if (!(win->win_ptr =
			mlx_new_window(win->mlx_ptr, WIN_X, WIN_Y, win->title)))
		exit(0);
	return (win);
}

t_point			**create_map(int fd, size_t map_y)
{
	t_point		**map;

	if (!(map = (t_point**)malloc(sizeof(t_point*) * (map_y + 1))))
		exit(0);
	if (!(map[0] = (t_point*)malloc(sizeof(t_point))))
		exit(0);
	map[0][0].x2d = map_y;
	map[0][0].y2d = 0;
	map = fill_map(fd, map, NULL, 1);
	if (map[0][0].y2d == map[0][0].x2d)
	{
		ft_putendl("The file is empty.");
		free(map[0]);
		free(map);
		exit(0);
	}
	return (map);
}
