/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:24:52 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/29 22:50:32 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		size;
	size_t	index;
	size_t	end;
	char	*dst;

	if (!s)
		return (NULL);
	index = 0;
	while (s[index] == ' ' || s[index] == '\n' || s[index] == '\t')
		index++;
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	size = ++end - index;
	size = ((0 <= size) ? size : 0);
	if (!(dst = (char*)malloc(size + 1)) || !s)
		return (NULL);
	ft_strncpy(dst, s + index, size);
	dst[size] = '\0';
	return (dst);
}
