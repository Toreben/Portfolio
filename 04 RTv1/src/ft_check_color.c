/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check_color.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/10 15:53:03 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 02:57:25 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_check_color(char *src, int l)
{
	int	c;

	if (!ft_strnstr(src, "\t\t\tcolor = ", ft_strlen("\t\t\tcolor = ")))
		return (ft_ferr(l, I_LINE));
	else
	{
		c = ft_strlen("\t\t\tcolor = ");
		if (src[c] == '0' && (src[c + 1] == 'X' || src[c + 1] == 'x'))
			c += 2;
		else if (src[c] == '#')
			c += 1;
		else
			return (ft_ferr(l, I_ARG));
		if (ft_strlen(src) - c != 8)
			return (ft_ferr(l, I_ARG));
		while ((ft_isdigit(src[c]) || ('A' <= src[c] && src[c] <= 'F')
			|| ('a' <= src[c] && src[c] <= 'f')) && src[c])
			c++;
		if (src[c])
			return (ft_ferr(l, I_ARG));
		else
			return (0);
	}
}
