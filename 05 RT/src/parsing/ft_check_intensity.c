/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_intensity.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 03:04:34 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 03:05:08 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

int	ft_check_intensity(char *src, int l)
{
	int er;

	er = 0;
	if (!ft_strnstr(src, "\t\t\tintensity = ", ft_strlen(src)))
		er |= ft_ferr(l, I_LINE);
	if (ft_str_is_float(&(src[ft_strlen("\t\t\tintensity = ")])) != 1)
		er |= ft_ferr(l, I_ARG);
	return (er);
}
