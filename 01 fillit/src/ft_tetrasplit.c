/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_tetrasplit.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@student.le-101.>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 20:27:14 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 00:53:55 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_char(char const *s, size_t i)
{
	int count_char;

	count_char = 0;
	while (s[i] != '\n' && s[i])
	{
		count_char++;
		i++;
	}
	return (count_char);
}

static int		ft_countlines(char const *s)
{
	int		i;
	int		count_lines;

	count_lines = 0;
	i = -1;
	while (s[++i])
		if (s[i] == '\n')
			count_lines++;
	return (count_lines);
}

char			**ft_tetrasplit(char const *s)
{
	int		j;
	int		k;
	int		i;
	char	**lines;

	j = 0;
	i = -1;
	if (!s || !(lines = (char**)malloc(sizeof(char*) * (ft_countlines(s) + 1))))
		return (NULL);
	while (s[++i])
		if ((s[i] != '\n' || (s[i] == '\n' && s[i - 1] == '\n')))
		{
			if (!(lines[j] = (char*)malloc(sizeof(char) * (ft_char(s, i) + 1))))
				return (NULL);
			k = 0;
			if (!(s[i] == '\n' && s[i - 1] == '\n'))
			{
				while (s[i] != '\n' && s[i])
					lines[j][k++] = s[i++];
				i--;
			}
			lines[j++][k] = '\0';
		}
	lines[j] = NULL;
	return (lines);
}
