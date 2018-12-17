/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:23:46 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:26:11 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	i = -1;
	if (!s || !f ||
			!(dest = (char *)malloc((sizeof(char) * (ft_strlen(s) + 1)))))
		return (NULL);
	while (s[++i])
		dest[i] = (*f)(s[i]);
	dest[i] = '\0';
	return (dest);
}
