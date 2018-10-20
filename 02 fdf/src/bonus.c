/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bonus.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/04 01:10:18 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 12:47:20 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	play_music(char *track)
{
	char *to_play;

	to_play = ft_strdup("afplay music/");
	to_play = ft_strjoin(to_play, track);
	to_play = ft_strjoin(to_play, " &");
	system(to_play);
}

int			stop_music(void)
{
	system("killall afplay");
	return (0);
}

char		*easter_egg(int key, int *music_playing, char *easter)
{
	if (key == K_Z)
		easter[0] = 'z';
	else if (easter[0] == 'z' && key != K_1 && key != K_2 && key != K_3 &&
			key != K_4 && key != K_PAD_1 && key != K_PAD_2 && key != K_PAD_3
			&& key != K_PAD_4)
		ft_strdel(&easter);
	else if (easter[0] == 'z' && (key == K_1 || key == K_2 || key == K_3 ||
			key == K_4 || key == K_PAD_1 || key == K_PAD_2 || key == K_PAD_3
			|| key == K_PAD_4))
	{
		if (key <= 48)
			easter[1] = key + 31;
		else
			easter[1] = key - 34;
		if (*music_playing == 1)
			stop_music();
		*music_playing = 1;
		play_music(easter);
		ft_strdel(&easter);
	}
	return (easter);
}
