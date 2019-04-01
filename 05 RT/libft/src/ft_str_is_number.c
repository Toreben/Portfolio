/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_number.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 07:42:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/07 02:55:22 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_number(char const *s)
{
	int		i;
	int		sign;

	sign = 1;
	if (s[0] == '+' || s[0] == '-')
	{
		if (!s[1])
			return (0);
		i = 0;
		s[0] == '-' ? sign = -1 : 0;
	}
	else
		i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
			return (0);
	return (sign);
}
