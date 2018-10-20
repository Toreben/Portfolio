/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_seg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/01 15:30:03 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 17:49:04 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_seg_dx(int *tab, t_comp p1, t_window *win)
{
	int i;
	int cumul;

	i = 0;
	cumul = tab[0] / 2;
	while (++i <= tab[0])
	{
		p1.rea += tab[2];
		cumul += tab[1];
		if (cumul >= tab[0])
		{
			cumul -= tab[0];
			p1.ima += tab[3];
		}
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, p1.rea, p1.ima, 0xD5D9E0);
	}
}

static void	print_seg_dy(int *tab, t_comp p1, t_window *win)
{
	int i;
	int cumul;

	i = 0;
	cumul = tab[1] / 2;
	while (++i <= tab[1])
	{
		p1.ima += tab[3];
		cumul += tab[0];
		if (cumul >= tab[1])
		{
			cumul -= tab[1];
			p1.rea += tab[2];
		}
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, p1.rea, p1.ima, 0xD5D9E0);
	}
}

void		print_seg(t_window *win, t_comp p1, t_comp p2)
{
	int		tab[5];

	tab[0] = p2.rea - p1.rea;
	tab[1] = p2.ima - p1.ima;
	tab[2] = (tab[0] > 0) ? 1 : -1;
	tab[3] = (tab[1] > 0) ? 1 : -1;
	tab[0] = (tab[0] < 0) ? -tab[0] : tab[0];
	tab[1] = (tab[1] < 0) ? -tab[1] : tab[1];
	if (tab[0] > tab[1])
		print_seg_dx(tab, p1, win);
	else
		print_seg_dy(tab, p1, win);
}
