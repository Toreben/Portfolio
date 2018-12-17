/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_vector.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/24 17:55:21 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 18:47:54 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

void			ft_free_strstr(char **src)
{
	int max;
	int itter;

	max = ft_strstrlen(src);
	itter = -1;
	while (++itter < max)
		free(src[itter]);
	free(src);
	src = NULL;
}

static int		ft_check_input_float(char **src)
{
	int max;
	int itter;

	max = ft_strstrlen(src);
	itter = -1;
	while (++itter < max)
		if (!ft_str_is_float(src[itter]))
			return (0);
	return (1);
}

int				ft_check_vector(char *src, int l)
{
	char	**tmp;
	int		er;

	er = 0;
	tmp = ft_strsplit(src, ' ');
	er |= (ft_strstrlen(tmp) != 3) ? ft_ferr(l, I_NB_ARG) : 0;
	if (!ft_check_input_float(tmp))
		er |= ft_ferr(l, I_ARG);
	ft_free_strstr(tmp);
	return (er);
}
