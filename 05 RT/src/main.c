/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/04 19:14:32 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/28 04:20:15 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static char	**ft_get_file(int const fd_y, int const fd_line)
{
	int		nb_lines;
	char	**file;
	char	*test;

	nb_lines = 0;
	test = NULL;
	while (gnl(fd_y, &test) > 0)
	{
		ft_strdel(&test);
		nb_lines++;
	}
	ft_strdel(&test);
	close(fd_y);
	if (!(file = (char**)malloc(sizeof(char*) * (nb_lines + 1))))
		return (NULL);
	file[nb_lines] = NULL;
	nb_lines = 0;
	while (gnl(fd_line, &(file[nb_lines])) > 0)
		nb_lines++;
	return (file);
}

int			free_file(char **f, int er)
{
	int itter;

	itter = 0;
	while (f[itter])
		ft_strdel(&(f[itter++]));
	ft_strdel(&(f[itter]));
	free(f);
	if (er == 1)
		ft_putendl("\033[38;5;196mNO ERROR ALLOWED, CORRECT "
			"YOUR FILE TO HAVE A RESULT");
	if (er == 2)
		ft_putendl("\033[38;5;196mA malloc failed");
	return (0);
}

void		free_scn(t_scene *scn)
{
	t_object	*o;
	t_spot		*s;
	void		*tmp;

	o = scn->content;
	s = scn->spt;
	while (o || s)
		if (o)
		{
			tmp = o->next;
			free(o);
			o = tmp;
		}
		else if (s)
		{
			tmp = s->next;
			free(s);
			s = tmp;
		}
	SDL_DestroyRenderer(scn->rdr);
	SDL_DestroyWindow(scn->win);
	SDL_Quit();
	TTF_Quit();
	free(scn);
}

static int	ft_cant_read(void)
{
	ft_putendl("\033[38;5;196mIMPOSSIBLE TO READ THE FILE.");
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd_y;
	int		fd_line;
	char	**file;
	t_scene *scn;

printf("%d\n", TB_COL_Y);
	if (argc != 2)
	{
		ft_putendl("\033[38;5;196mUsage : ./RT scene_file.");
		return (0);
	}
	if (NB_THREAD <= 0)
	{
		ft_putendl("\033[38;5;196mNumber of threads must be greater than 0.");
		return (0);
	}
	if ((fd_y = open(argv[1], O_RDONLY)) == -1
		|| (fd_line = open(argv[1], O_RDONLY)) == -1)
		return (ft_cant_read());
	if (!(file = ft_get_file(fd_y, fd_line)))
		return (0);
	if (ft_check_error(file) > 0)
		return (free_file(file, 1));
	
	scn = ft_pars(file);
	free_file(file, 0);
	//UI
	ft_ui(scn);
	// rt(scn, argv[1]);
	// free_scn(scn);
	return (0);
}
