/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:21:50 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 22:46:53 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*src2;

	i = 0;
	if (!s1)
		return (s2[0]);
	if (!s2)
		return (s1[0]);
	src1 = (unsigned char*)s1;
	src2 = (unsigned char*)s2;
	while (src1[i] && src1[i] == src2[i])
		i++;
	return (src1[i] - src2[i]);
}
