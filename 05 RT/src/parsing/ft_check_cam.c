/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_cam.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/10 16:10:32 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 16:31:21 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static int	ft_check_dist(char *src, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	if (!ft_strnstr(src, "\t\t\tdistance = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	tmp = ft_strtrim(src);
	if (ft_str_is_float(&(tmp[ft_strlen("distance = ")])) != 1)
		er |= ft_ferr(l, I_ARG);
	free(tmp);
	return (er);
}

static int	ft_check_angx(char *src, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	if (!ft_strnstr(src, "\t\t\tangle on x = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	tmp = ft_strtrim(src);
	if (!ft_str_is_float(&(tmp[ft_strlen("angle on x = ")])))
		er |= ft_ferr(l, I_ARG);
	free(tmp);
	return (er);
}

static int	ft_check_angy(char *src, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	if (!ft_strnstr(src, "\t\t\tangle on y = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	tmp = ft_strtrim(src);
	if (!ft_str_is_float(&(tmp[ft_strlen("angle on y = ")])))
		er |= ft_ferr(l, I_ARG);
	free(tmp);
	return (er);
}

/*static int	ft_check_tilt(char *src, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	if (!ft_strnstr(src, "\t\t\ttilt = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	tmp = ft_strtrim(src);
	if (!ft_str_is_float(&(tmp[ft_strlen("tilt = ")])))
		er |= ft_ferr(l, I_ARG);
	free(tmp);
	return (er);
}*/

int			ft_check_camera(char **f, int *l)
{
	int er;

	er = 0;
	er |= ft_strcmp(f[*l], "\t\tcamera :") ? ft_ferr(*l, I_LINE) : 0;
	er |= ft_strcmp(f[++*l], "\t\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_pos(f, *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_angx(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_angy(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_dist(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t\t}") ? ft_ferr(*l, CBR_EXP) : 0;
	return (er);

/*	int er;

	er = 0;
	er |= ft_strcmp(f[*l], "\t\tcamera :") ? ft_ferr(*l, I_LINE) : 0;
	er |= ft_strcmp(f[++*l], "\t\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_pos(f, *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_lookat(f, *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_tilt(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_dist(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t\t}") ? ft_ferr(*l, CBR_EXP) : 0;
	return (er);*/

}
