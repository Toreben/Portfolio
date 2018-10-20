/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_number.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 07:42:39 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 07:44:10 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_str_is_number(char const *s)
{
	int		i;

	if (s[0] == '+' || s[0] == '-')
	{
		if (!s[1])
			return (0);
		i = 1;
	}
	else
		i = 0;
	while (s[i])
		if (!ft_isdigit(s[i]))
			return (0);
		else
			i++;
	return (1);
}
