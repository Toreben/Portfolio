/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_pos_dir.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/10 15:43:41 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/02 20:18:21 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_check_pos(char **f, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	tmp = ft_strtrim(f[l]);
	if (ft_strnstr(f[l], "\t\t\tposition = (", ft_strlen(f[l])) - f[l])
		er |= ft_ferr(l, I_LINE);
	f[l][ft_strlen(f[l]) - 1] != ')' ? er |= ft_ferr(l, BR_EXP) : 0;
	tmp[ft_strlen(tmp) - 1] = '\0';
	er |= ft_check_vector(&(tmp[ft_strlen("position = (")]), l);
	free(tmp);
	return (er);
}

int			ft_check_org(char **f, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	tmp = ft_strtrim(f[l]);
	if (ft_strnstr(f[l], "\t\t\torigin = (", ft_strlen(f[l])) - f[l])
		er |= ft_ferr(l, I_LINE);
	f[l][ft_strlen(f[l]) - 1] != ')' ? er |= ft_ferr(l, BR_EXP) : 0;
	tmp[ft_strlen(tmp) - 1] = '\0';
	er |= ft_check_vector(&(tmp[ft_strlen("origin = (")]), l);
	free(tmp);
	return (er);
}

int			ft_check_dir(char **f, int l)
{
	int		er;
	char	*tmp;

	er = 0;
	tmp = ft_strtrim(f[l]);
	if (!ft_strnstr(f[l], "\t\t\tdirection = (", ft_strlen(f[l])))
		er |= ft_ferr(l, I_LINE);
	f[l][ft_strlen(f[l]) - 1] != ')' ? er |= ft_ferr(l, BR_EXP) : 0;
	tmp[ft_strlen(tmp) - 1] = '\0';
	er |= ft_check_vector(&(tmp[ft_strlen("direction = (")]), l);
	free(tmp);
	return (er);
}
