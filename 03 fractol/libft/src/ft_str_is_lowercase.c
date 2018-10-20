/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_str_is_lowercase.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:21:18 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:25:53 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_str_is_lowercase(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
		if (!ft_islower(s[i]))
			return (0);
		else
			i++;
	return (1);
}
