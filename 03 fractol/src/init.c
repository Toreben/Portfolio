/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 22:39:44 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 23:18:48 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static t_image	create_img(void *mlx_ptr)
{
	t_image	img;

	img.img_ptr = mlx_new_image(mlx_ptr, IMG_G_X, IMG_G_Y);
	img.img_str = (t_uint*)mlx_get_data_addr(img.img_ptr, &img.bpp,
		&img.s_l, &img.endian);
	return (img);
}

t_window		*create_win(void)
{
	t_window	*win;

	if (!(win = (t_window*)malloc(sizeof(t_window))))
		quit(win, 0);
	win->mlx_ptr = mlx_init();
	win->img = create_img(win->mlx_ptr);
	win->fract.itter_max = ITTER_MAX;
	win->fract.colorscheme = WHITE;
	if (!(win->win_ptr =
			mlx_new_window(win->mlx_ptr, WIN_X, WIN_Y, "fract'ol")))
		quit(win, 1);
	ft_ui(win);
	return (win);
}
