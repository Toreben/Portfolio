/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_spot.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/10 16:08:00 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 02:56:51 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_check_intensity(char *src, int l)
{
	int er;

	er = 0;
	if (!ft_strnstr(src, "\t\t\tintensity = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	if (ft_str_is_float(&(src[ft_strlen("\t\t\tintensity = ")])) != 1)
		er |= ft_ferr(l, I_ARG);
	return (er);
}

int			ft_check_spot(char **f, int *l)
{
	int er;

	er = 0;
	er |= ft_strcmp(f[*l], "\t\tspot :") ? ft_ferr(*l, I_LINE) : 0;
	er |= ft_strcmp(f[++*l], "\t\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_pos(f, *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_intensity(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_color(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t\t}") ? ft_ferr(*l, CBR_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	if (ft_strstr(f[*l], "spot"))
		er |= ft_check_spot(f, l);
	return (er);
}
