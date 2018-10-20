/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   music.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/25 17:38:04 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/09 16:50:59 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	play(int key)
{
	(key == K_1 || key == K_PAD_1) ? system("afplay music/z1 &") : 0;
	(key == K_2 || key == K_PAD_2) ? system("afplay music/z2 &") : 0;
	(key == K_3 || key == K_PAD_3) ? system("afplay music/z3 &") : 0;
	(key == K_4 || key == K_PAD_4) ? system("afplay music/z4 &") : 0;
}

int			play_music(int key)
{
	static t_bool	is_prev_z = FALSE;
	static t_bool	is_playing = FALSE;

	if (key == K_Z)
		return (is_prev_z = TRUE);
	else if (key == K_M && is_playing == TRUE)
	{
		system("killall afplay");
		is_prev_z = FALSE;
		is_playing = FALSE;
		return (1);
	}
	else if ((key == K_1 || key == K_PAD_1 || key == K_2 || key == K_PAD_2
			|| key == K_3 || key == K_PAD_3 || key == K_4 || key == K_PAD_4)
			&& is_prev_z == TRUE)
	{
		if (is_playing)
			system("killall afplay");
		play(key);
		is_prev_z = FALSE;
		is_playing = TRUE;
		return (1);
	}
	else
		return (is_prev_z = FALSE);
}
