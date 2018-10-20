/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_uppercase.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:21:23 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:25:54 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_str_is_uppercase(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		if (!ft_isupper(s[i]))
			return (0);
		else
			i++;
	return (1);
}
