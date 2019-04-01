/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_float.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/14 14:50:35 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 03:07:12 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_float(char const *src)
{
	int		dot;
	int		iter;
	int		sign;

	sign = 1;
	if (src[0] == '+' || src[0] == '-')
	{
		if (!src[1])
			return (0);
		iter = 0;
		src[0] == '-' ? sign = -1 : 0;
	}
	else
		iter = -1;
	dot = 1;
	while (src[++iter])
		if (ft_isdigit(src[iter]))
			continue;
		else if (src[iter] == '.' && dot)
			dot = 0;
		else
			return (0);
	return (sign);
}
