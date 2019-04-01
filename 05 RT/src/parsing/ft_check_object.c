/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_object.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/06 15:41:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 21:25:16 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static enum e_type	ft_check_type(char *src)
{
	if (!ft_strcmp(src, "\t\tsphere :"))
		return (SPHERE);
	else if (!ft_strcmp(src, "\t\tcone :"))
		return (CONE);
	else if (!ft_strcmp(src, "\t\tcylinder :"))
		return (CYLINDER);
	else if (!ft_strcmp(src, "\t\tplane :"))
		return (PLANE);
	else
		return (ERROR);
}

static int			ft_check_size(char *src, int l, enum e_type type)
{
	int er;

	er = 0;
	if (ft_strnstr(src, "\t\t\tradius = ", ft_strlen("\t\t\tradius = "))
		&& (type == SPHERE || type == CYLINDER))
	{
		if (!ft_str_is_float(&(src[ft_strlen("\t\t\tradius = ")])))
			er |= ft_ferr(l, I_ARG);
		return (er);
	}
	else if (ft_strnstr(src, "\t\t\tangle = ", ft_strlen("\t\t\tangle = "))
			&& type == CONE)
	{
		if (!ft_str_is_float(&(src[ft_strlen("\t\t\tangle = ")])))
			er |= ft_ferr(l, I_ARG);
		return (er);
	}
	else if (type == PLANE)
		return (0);
	else
		return (ft_ferr(l, I_LINE));
}

static int			ft_check_next(char **f, int *l, enum e_type type)
{
	int		er;
	char	*triml;
	char	*trimp;

	er = 0;
	if (!f[*l])
		return (0);
	triml = ft_strtrim(f[*l]);
	trimp = ft_strtrim(f[*l - 1]);
	if (ft_strcmp(triml, "}"))
		er |= ft_check_object(f, l);
	else if (type == ERROR && ft_strcmp(trimp, "}"))
	{
		type == ERROR ? --(*l) : 0;
		er |= ft_check_object(f, l);
	}
	free(trimp);
	free(triml);
	return (er);
}

static int			ft_check_obj_size(char **f, int l, enum e_type type)
{
	int		itter;
	char	*trim;
	int		com;

	itter = l + 1;
	com = 0;
	trim = ft_strtrim(f[itter]);
	while (f[itter] && !ft_strstr(trim, "}"))
	{
		if (trim[0] == '#')
			com++;
		free(trim);
		trim = ft_strtrim(f[++itter]);
	}
	free(trim);
	if (!f[itter])
		return (0);
	itter -= (1 + com + l);
	if (type != PLANE && itter % 4)
		return (0);
	if ((type == PLANE || type == ERROR) && (itter) % 3)
		return (0);
	else
		return (1);
}

int					ft_check_object(char **f, int *l)
{
	enum e_type	type;
	int			er;

	er = 0;
	if ((type = ft_check_type(f[*l])) == ERROR)
		er |= ft_ferr(*l, I_OBJ_TYPE);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	if (!ft_check_obj_size(f, *l, type))
		return (ft_ferr(*l, FI_OBJ));
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_org(f, *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_dir(f, *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_size(f[*l], *l, type);
	type != PLANE ? *l = ft_skip_com(f, *l + 1, &er) : 0;
	er |= ft_check_color(f[*l], *l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= (ft_strcmp(f[*l], "\t\t}")) ? ft_ferr(*l, CBR_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_next(f, l, type);
	return (er);
}
