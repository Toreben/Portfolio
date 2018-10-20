/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/30 10:17:00 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 19:57:52 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_put_colorscheme(void)
{
	ft_putendl("\tnotum terram\t->\tclassic map colors");
	ft_putendl("\tle 101\t\t->\tle-101-school colorscheme (Default)");
	ft_putendl("\tfire\t\t->\tfire-like color");
	ft_putendl("\tpaon pan pan\t->\tpeacock-blue");
	ft_putendl("\trafletnaug\t->\tpink-orange colorscheme");
	ft_putendl("\tkouign amann\t->\tbutter-like colorscheme");
	ft_putendl("\tmars\t\t->\tMars inspired colorscheme");
}

static int	check_color(char *colorscheme)
{
	return ((ft_strcmp(colorscheme, "notum terram"))
		&& (ft_strcmp(colorscheme, "le 101"))
		&& (ft_strcmp(colorscheme, "fire"))
		&& (ft_strcmp(colorscheme, "paon pan pan"))
		&& (ft_strcmp(colorscheme, "rafletnaug"))
		&& (ft_strcmp(colorscheme, "kouign amann"))
		&& (ft_strcmp(colorscheme, "mars")));
}

static int	bad_param(char c)
{
	if (c == 1)
		ft_putendl(
			"Usage : ./fdf map.fdf [colorscheme]\nAvailable colorschemes :");
	else
		ft_putendl("Unknown colorscheme. Please use one of the following :");
	ft_put_colorscheme();
	return (0);
}

int			main(int argc, char **argv)
{
	t_point		**map;
	size_t		size_y;
	int			fd_gety;
	int			fd_recup;
	char		*colorscheme;

	if (argc != 2 && argc != 3)
		return (bad_param(1));
	if (check_color(colorscheme = (argc == 3) ? (char*)argv[2] : "le 101"))
		return (bad_param(2));
	fd_gety = open_map(argv[1]);
	size_y = get_map_y(fd_gety);
	fd_recup = open_map(argv[1]);
	close_map(fd_gety);
	map = create_map(fd_recup, size_y);
	close_map(fd_recup);
	init_print(&map, (char*)argv[1], colorscheme);
	return (0);
}
