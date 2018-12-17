/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_skip_comm.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/23 00:14:38 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 17:53:29 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static void	ft_crash(char **f)
{
	ft_putendl("\033[38;5;196mINCOMPLETE FILE, PLEASE COMPLETE AND TRY AGAIN.");
	free_file(f, 1);
	exit(0);
}

int			ft_skip_com(char **f, int l, int *er)
{
	char	*trim;

	if (!f[l])
		ft_crash(f);
	trim = ft_strtrim(f[l]);
	while (trim[0] == '#' || !ft_strlen(trim))
	{
		if (!ft_strlen(trim))
			*er |= ft_ferr(l, E_LINE);
		ft_strdel(&trim);
		if (!f[++l])
			ft_crash(f);
		trim = ft_strtrim(f[l]);
	}
	ft_strdel(&trim);
	return (l);
}
