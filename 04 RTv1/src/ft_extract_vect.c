/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_extract_vect.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/09 00:27:43 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 00:27:57 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	ft_extract_vect(char *src)
{
	int			itter;
	t_vector	vect;

	itter = ft_strchr(src, '(') - src;
	vect.x = ft_atof(src + ++itter);
	while (!ft_isspace(src[itter]))
		itter++;
	vect.y = ft_atof(src + ++itter);
	while (!ft_isspace(src[itter]))
		itter++;
	vect.z = ft_atof(src + ++itter);
	return (vect);
}
