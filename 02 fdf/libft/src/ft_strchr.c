/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:21:38 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/18 23:44:19 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(char const *s, int c)
{
	size_t	i;
	char	chr;
	size_t	size;

	if (!s)
		return (NULL);
	i = -1;
	chr = c;
	size = ft_strlen(s);
	while (++i <= size)
		if (s[i] == chr)
			return (&((char*)s)[i]);
	return (NULL);
}
