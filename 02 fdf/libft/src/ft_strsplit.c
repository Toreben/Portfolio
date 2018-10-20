/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:24:36 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:26:22 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	**ft_split(char const *s, char c, char **dest)
{
	int		i;
	int		nb_mots;
	int		nb_lettres;

	i = -1;
	nb_mots = 0;
	while (s[++i])
	{
		nb_lettres = 0;
		while (s[i + nb_lettres] != c && s[i + nb_lettres])
			nb_lettres++;
		if (nb_lettres)
		{
			dest[nb_mots++] = ft_strsub(s, i, nb_lettres);
			i += nb_lettres - 1;
		}
	}
	dest[nb_mots] = NULL;
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_mots;
	int		i;
	char	**dest;

	if (!s)
		return (NULL);
	i = -1;
	nb_mots = 0;
	while (s[++i])
		(s[i] != c && (s[i + 1] == c || s[i + 1] == '\0')) ? nb_mots++ : 0;
	if (!(dest = (char**)malloc(sizeof(char*) * (nb_mots + 1))))
		return (NULL);
	dest = ft_split(s, c, dest);
	return (dest);
}
