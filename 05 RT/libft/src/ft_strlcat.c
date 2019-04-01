/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:23:35 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:26:09 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	size_dst;
	size_t	size_src;

	i = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	while (i + size_dst < size - 1 && src[i] && size != 0)
	{
		dst[size_dst + i] = src[i];
		i++;
	}
	dst[size_dst + i] = '\0';
	if (size < size_dst)
		return (size + size_src);
	else
		return (size_dst + size_src);
}
