/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmerge.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/24 18:42:09 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 21:08:32 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmerge(char const *s1, char const *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	else
		return (ft_strjoin(s1, s2));
}
