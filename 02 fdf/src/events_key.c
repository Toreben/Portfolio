/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   events_key.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/03 21:17:04 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 14:55:50 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void		update_point(t_window *win, int key)
{
	size_t	i;
	size_t	j;

	if (key == K_E || key == K_Q || key == K_PAD_0)
		win->rx = fill_mat_x(win->rx);
	if (key == K_W || key == K_S || key == K_PAD_0)
		win->ry = fill_mat_y(win->ry);
	if (key == K_A || key == K_D || key == K_PAD_0)
		win->rz = fill_mat_z(win->rz);
	if (key == K_E || key == K_Q || key == K_W || key == K_S || key == K_A
			|| key == K_D || key == K_PAD_0)
		win->rot = mult_matrix_matrix(mult_matrix_matrix(win->rz, win->rx),
			win->ry);
	i = (size_t)win->map[0][0].y2d;
	while (++i <= (size_t)win->map[0][0].x2d)
	{
		j = 0;
		while (++j <= (size_t)win->map[i][0].x2d)
			win->map[i][j] = calcul_point_2d(win->map[i][j], win);
	}
	print_map(win);
}

static void	reset_win(t_window *win)
{
	win->fac_z = 1;
	win->rx.ang.deg = 0;
	win->ry.ang.deg = 0;
	win->rz.ang.deg = 0;
	win->repere.x0 = IMG_X / 2 + UID_X;
	win->fac = win->fac_aj;
}

static void	modify_point(t_window *win, int key)
{
	if (key == K_PAD_PLUS || key == K_PAD_MINUS)
		win->fac_z += (key == K_PAD_PLUS) ? 1 : -1;
	else if (key == K_LEFT || key == K_RIGHT)
		win->repere.x0 += (key == K_RIGHT) ? 5 : -5;
	else if (key == K_DOWN || key == K_UP)
		win->repere.y0 += (key == K_DOWN) ? 5 : -5;
	else if (key == K_W || key == K_S)
		win->ry.ang.deg += (key == K_S) ? 5 : -5;
	else if (key == K_A || key == K_D)
		win->rz.ang.deg += (key == K_A) ? 5 : -5;
	else if (key == K_E || key == K_Q)
		win->rx.ang.deg += (key == K_Q) ? 5 : -5;
	else if (key == K_PAD_0)
		reset_win(win);
	update_point(win, key);
}

int			deal_key(int key, void *param)
{
	static int	music_playing;
	static char *easter;
	t_window	*win;

	if (!easter)
		if (!(easter = ft_strnew(2)))
			exit(0);
	easter[2] = '\0';
	easter = easter_egg(key, &music_playing, easter);
	win = (t_window*)param;
	if (key == K_ESC)
	{
		easter = ft_strdel(&easter);
		(music_playing) ? stop_music() : 0;
		quit(win, NULL);
	}
	if (key == K_M)
		music_playing = (music_playing) ? stop_music() : 0;
	if (key == K_PAD_PLUS || key == K_PAD_MINUS || key == K_LEFT ||
		key == K_RIGHT || key == K_DOWN || key == K_UP || key == K_W ||
		key == K_S || key == K_A || key == K_D || key == K_E || key == K_Q ||
		key == K_PAD_0)
		modify_point(win, key);
	return (0);
}
