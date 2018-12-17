/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncmp.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:24:02 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:26:15 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (--n && src1[i] && src2[i] && src1[i] == src2[i])
		i++;
	return (src1[i] - src2[i]);
}
