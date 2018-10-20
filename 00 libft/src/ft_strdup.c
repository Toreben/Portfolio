/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:22:06 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/21 21:03:12 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char const *s1)
{
	char	*dest;

	if (!s1)
		return (NULL);
	if (!(dest = (char*)malloc(ft_strlen(s1) + 1)))
		return (NULL);
	else
		return (ft_strcpy(dest, s1));
}
