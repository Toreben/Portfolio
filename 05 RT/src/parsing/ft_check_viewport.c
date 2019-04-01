/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_viewport.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/10 16:11:27 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 13:57:32 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static int	ft_check_height(char *src, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	if (!ft_strnstr(src, "\t\t\theight = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	tmp = ft_strtrim(src);
	if (ft_str_is_number(&(tmp[ft_strlen("height = ")])) != 1)
		er |= ft_ferr(l, I_ARG);
	ft_strdel(&tmp);
	return (er);
}

static int	ft_check_width(char *src, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	if (!ft_strnstr(src, "\t\t\twidth = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	tmp = ft_strtrim(src);
	if (ft_str_is_number(&(tmp[ft_strlen("width = ")])) != 1)
		er |= ft_ferr(l, I_ARG);
	ft_strdel(&tmp);
	return (er);
}

int			ft_check_viewport(char **f, int *l)
{
	int er;

	er = 0;
	er |= ft_strcmp(f[*l], "\t\tviewport :") ? ft_ferr(*l, I_LINE) : 0;
	er |= ft_strcmp(f[++*l], "\t\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_height(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_width(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t\t}") ? ft_ferr(*l, CBR_EXP) : 0;
	return (er);
}
