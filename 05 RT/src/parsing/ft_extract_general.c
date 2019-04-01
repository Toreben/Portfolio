/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_extract_general.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 03:10:19 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/28 17:02:31 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

t_scene *ft_extract_ambient(t_scene *scn, char **f, int *l)
{
	
	*l = ft_skip_com(f, *l + 1, NULL);
	*l = ft_skip_com(f, *l + 1, NULL);
	if (ft_strcmp(f[*l], "\t\t\tOFF"))
	{
		scn->amb.intensity = ft_atof(&(f[*l][ft_strlen("\t\t\tintensity = ")]));
		*l = ft_skip_com(f, *l + 1, NULL);
		ft_get_color(&(scn->amb.color), ft_atox(&(f[*l][ft_strlen("\t\t\tcolor = ")])));
	}
	else
	{
		scn->amb.intensity = 0;
		ft_get_color(&(scn->amb.color), 0x0);
	}
	*l = ft_skip_com(f, *l + 1, NULL);
	return (scn);
}
