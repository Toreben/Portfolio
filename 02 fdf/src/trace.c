/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trace.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 03:46:26 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:21:34 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int	new_col(int col_src, int col_dest, int iter, int boucle)
{
	int rgb[3];
	int rgb_src;
	int rgb_dest;
	int rgb_res[3];
	int	i;

	rgb[0] = 0xFF0000;
	rgb[1] = 0x00FF00;
	rgb[2] = 0x0000FF;
	i = -1;
	while (++i <= 2)
	{
		rgb_src = col_src & rgb[i];
		rgb_dest = col_dest & rgb[i];
		rgb_res[i] = (((rgb_dest - rgb_src) / iter) * boucle) + rgb_src;
		rgb_res[i] = rgb_res[i] & rgb[i];
	}
	return (rgb_res[0] + rgb_res[1] + rgb_res[2]);
}

/*
** int dx; -> tab[0]
** int dy; -> tab[1]
** int xinc; -> tab[2]
** int yinc; -> tab[3]
** int p2_col; -> tab[4]
** int cumul;
** int i;
*/

static void	print_seg_dx(int *tab, t_point *p1, t_window *win, char img)
{
	int i;
	int cumul;
	int pos;

	i = 0;
	cumul = tab[0] / 2;
	while (++i <= tab[0])
	{
		p1->x2d += tab[2];
		cumul += tab[1];
		if (cumul >= tab[0])
		{
			cumul -= tab[0];
			p1->y2d += tab[3];
		}
		if (is_in_img(*p1))
		{
			pos = (((unsigned int)p1->y2d * IMG_X) + (unsigned int)p1->x2d);
			if (!img)
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, p1->x2d, p1->y2d,
					new_col(p1->col, tab[4], tab[0], i));
			else
				win->img.img_str[pos] = new_col(p1->col, tab[4], tab[0], i);
		}
	}
}

static void	print_seg_dy(int *tab, t_point *p1, t_window *win, char img)
{
	int i;
	int cumul;
	int pos;

	i = 0;
	cumul = tab[1] / 2;
	while (++i <= tab[1])
	{
		p1->y2d += tab[3];
		cumul += tab[0];
		if (cumul >= tab[1])
		{
			cumul -= tab[1];
			p1->x2d += tab[2];
		}
		if (is_in_img(*p1))
		{
			pos = (((unsigned int)p1->y2d * IMG_X) + (unsigned int)p1->x2d);
			if (!img)
				mlx_pixel_put(win->mlx_ptr, win->win_ptr, p1->x2d, p1->y2d,
					new_col(p1->col, tab[4], tab[1], i));
			else
				win->img.img_str[pos] = new_col(p1->col, tab[4], tab[1], i);
		}
	}
}

void		print_seg(t_window *win, t_point p1, t_point p2, char img)
{
	int		tab[5];
	int		pos;

	if (is_to_print(p1, win) || is_to_print(p2, win) || !img)
	{
		tab[0] = p2.x2d - p1.x2d;
		tab[1] = p2.y2d - p1.y2d;
		tab[2] = (tab[0] > 0) ? 1 : -1;
		tab[3] = (tab[1] > 0) ? 1 : -1;
		tab[0] = (tab[0] < 0) ? -tab[0] : tab[0];
		tab[1] = (tab[1] < 0) ? -tab[1] : tab[1];
		tab[4] = p2.col;
		if (is_in_img(p1))
		{
			pos = (((unsigned int)p1.y2d * IMG_X) + (unsigned int)p1.x2d);
			win->img.img_str[pos] = new_col(p1.col, p1.col, 1, 1);
		}
		if (tab[0] > tab[1])
			print_seg_dx(tab, &p1, win, img);
		else
			print_seg_dy(tab, &p1, win, img);
	}
}
