/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_brackets.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/19 10:57:55 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/19 10:58:12 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_brackets(char *str, int len)
{
	int		prev;
	int		error;
	char	brack[len];

	ft_bzero(brack, len);
	prev = 0;
	len = -1;
	error = 0;
	while (str[++len] && !error)
		if (str[len] == '{' || str[len] == '[' || str[len] == '(')
			brack[prev++] = str[len];
		else if (str[len] == '}' || str[len] == ']' || str[len] == ')')
		{
			if (prev == 0 || !((brack[prev - 1] == '{' && str[len] == '}')
				|| (brack[prev - 1] == '[' && str[len] == ']')
				|| (brack[prev - 1] == '(' && str[len] == ')')))
				error = 1;
			else
				brack[--prev] = '\0';
		}
	return (!(ft_strlen(brack) || error));
}
