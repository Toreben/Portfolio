/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:24:31 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:26:21 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(char const *s, int c)
{
	size_t	i;
	size_t	size;
	char	chr;

	i = -1;
	size = ft_strlen(s);
	chr = c;
	while (++i <= size)
		if (((char*)s)[size - i] == chr)
			return (&((char*)s)[size - i]);
	return (NULL);
}
