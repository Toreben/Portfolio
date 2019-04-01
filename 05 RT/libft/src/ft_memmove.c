/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:19:33 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:25:41 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char	*srccpy;
	unsigned char	*dstcpy;

	dstcpy = (unsigned char*)dst;
	srccpy = (unsigned char*)src;
	if (dstcpy <= srccpy && srccpy <= (dstcpy + len - 1))
		while (len--)
			*dstcpy++ = *srccpy++;
	else
	{
		dstcpy += len - 1;
		srccpy += len - 1;
		while (len--)
			*dstcpy-- = *srccpy--;
	}
	return (dst);
}
