/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcat.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:21:29 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/19 12:24:20 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, char const *s2)
{
	size_t	i;
	size_t	size;

	if (!s1)
		return(ft_strdup(s2));
	size = ft_strlen(s1);
	i = -1;
	while (s2[++i])
		s1[size + i] = s2[i];
	s1[size + i] = '\0';
	return (s1);
}
