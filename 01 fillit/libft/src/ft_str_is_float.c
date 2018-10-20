/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_float.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 14:50:35 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/07/14 19:36:16 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_str_is_float(char const *src)
{
	int		dot;
	int		itter;

	if (!src)
		return (0);
	if (src[0] == '+' || src[0] == '-')
	{
		if (!s[1])
			return (0);
		itter = 0;
	}
	else
		itter = -1;
	dot = 1;
	while (src[++itter])
		if (ft_isdigit(src[itter]))
			continue;
		else if (src[itter] == '.' && dot)
			dot = 0;
		else
			return (0);
	return (1);
}
