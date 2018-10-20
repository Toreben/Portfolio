/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:23:51 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:26:12 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	i = -1;
	if (!s || !f ||
			!(dest = (char *)malloc((sizeof(char) * (ft_strlen(s) + 1)))))
		return (NULL);
	while (s[++i])
		dest[i] = (*f)(i, s[i]);
	dest[i] = '\0';
	return (dest);
}
