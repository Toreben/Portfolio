/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_error.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/03 00:45:45 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/21 14:04:37 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static int	ft_check_general(char **f, int *l)
{
	int		er;
	char	*tmp;

	er = 0;
	er |= ft_strcmp(f[*l], "\tgeneral :") ? ft_ferr(*l, I_LINE) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_ambiant(f, l);
	*l = ft_skip_com(f, *l + 1, &er);
	if (!ft_strnstr(f[*l], "\t\tanti aliasing = ", ft_strlen(f[*l])))
		er |= ft_ferr(*l, I_LINE);
	tmp = ft_strtrim(f[*l]);
	if (ft_str_is_number(&(tmp[ft_strlen("anti aliasing = ")])) != 1)
		er |= ft_ferr(*l, I_ARG);
	ft_strdel(&tmp);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t}") ? ft_ferr(*l, CBR_EXP) : 0;
	return (er);
}

static int	ft_check_view(char **f, int *l)
{
	int er;

	er = 0;
	er |= ft_strcmp(f[*l], "\tview :") ? ft_ferr(*l, I_LINE) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_strcmp(f[*l], "\t{") ? ft_ferr(*l, CBL_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_camera(f, l);
	*l = ft_skip_com(f, *l + 1, &er);
	er |= ft_check_viewport(f, l);
	*l = ft_skip_com(f, *l + 1, &er);
	if (ft_strstr(f[*l], "spot"))
		er |= ft_check_spot(f, l);
	er |= ft_strcmp(f[*l], "\t}") ? ft_ferr(*l, CBR_EXP) : 0;
	*l = ft_skip_com(f, *l + 1, &er);
	return (er);
}

static int	ft_check_empty_obj(char **f, int *l)
{
	char	*trim;

	trim = ft_strtrim(f[*l]);
	if (trim[0] == '}')
	{
		free(trim);
		if (!ft_strcmp(f[*l], "}") && (*l + 1) == (int)ft_strstrlen(f))
			return (NE_O);
		else
			return (ft_ferr(*l, CBR_EXP));
	}
	free(trim);
	return (ft_ferr(*l, FW_BLOCK));
}

static int	ft_has_obj(char **f, int *l)
{
	int er;
	int f_err;

	er = 0;
	if (ft_strstr(f[*l], "object"))
	{
		er |= ft_strcmp(f[*l], "\tobjects :") ? ft_ferr(*l, I_LINE) : 0;
		*l = ft_skip_com(f, *l + 1, &er);
		er |= ft_strcmp(f[*l], "\t{") ? ft_ferr(*l, CBL_EXP) : 0;
		*l = ft_skip_com(f, *l + 1, &er);
		if (!ft_strchr(f[*l], '}') && *f[0] != '\0')
		{
			if ((f_err = ft_check_object(f, l)))
				return (f_err);
			er |= ft_strcmp(f[*l], "\t}") ? ft_ferr(*l, CBR_EXP) : 0;
		}
		else
			er |= ft_ferr(*l, FE_BLOCK);
	}
	else
		er = ft_check_empty_obj(f, l);
	return (er);
}

int			ft_check_error(char **f)
{
	int		l;
	int		er;
	int		empt_obj;

	er = 0;
	l = ft_skip_com(f, 0, &er);
	er |= ft_strcmp(f[l], "scene :") ? ft_ferr(l, I_LINE) : 0;
	l = ft_skip_com(f, l + 1, &er);
	er |= ft_strcmp(f[l], "{") ? ft_ferr(l, CBL_EXP) : 0;
	l = ft_skip_com(f, l + 1, &er);
	er |= ft_check_general(f, &l);
	l = ft_skip_com(f, l + 1, &er);
	er |= ft_check_view(f, &l);
	empt_obj = ft_has_obj(f, &l);
	if ((empt_obj & (FE_BLOCK | FW_BLOCK | FI_OBJ)) || empt_obj & NE_O)
		return (empt_obj & NE_O ? er : empt_obj);
	er |= empt_obj;
	if ((size_t)l == ft_strstrlen(f))
		return (ft_ferr(l, CBR_EXP));
	l = ft_skip_com(f, l + 1, &er);
	return (er | empt_obj | (ft_strcmp(f[l], "}") ? ft_ferr(l, CBR_EXP) : 0));
}
