/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:19:13 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:25:36 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;

	i = -1;
	chr = c;
	while (++i < n)
		if (((unsigned char*)s)[i] == chr)
			return (&((unsigned char*)s)[i]);
	return (NULL);
}
