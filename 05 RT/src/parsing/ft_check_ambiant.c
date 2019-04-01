/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_ambiant.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 03:02:00 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 16:58:08 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

int	ft_check_ambiant(char **f, int *l)
{
	int		er;
	char	*trim;

	er = 0;
	er |= ft_strcmp(f[*l], "\t\tambient :") ? ft_ferr(*l, I_LINE) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	ft_lower((trim = ft_strtrim(f[*l])));
	if (ft_strstr(trim, "off"))
	{
		ft_strdel(&trim);
		er |= ft_strcmp(f[*l], "\t\t\tOFF") ? ft_ferr(*l, I_LINE) : 0;
	}
	else
	{
		er |= ft_check_intensity(f[*l], *l);
		*l = ft_skip_com(f, *l + 1, &er);
		er |= ft_check_color(f[*l], *l);
	}
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t\t}") ? ft_ferr(*l, CBR_EXP) : 0;
	return (er);
}
