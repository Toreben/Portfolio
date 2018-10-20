/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi16.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:21:10 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/17 02:18:35 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned int	ft_atoi16(char const *str)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	i += (str[i] == '+') ? 1 : 0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	else
		i += 1;
	while ((ft_isdigit(str[i]) || ('A' <= str[i] && str[i] <= 'F')
		|| ('a' <= str[i] && str[i] <= 'f')) && str[i])
	{
		nb = (nb * 16) + str[i];
		if (ft_isdigit(str[i]))
			nb -= '0';
		else if ('A' <= str[i] && str[i] <= 'F')
			nb -= 'A' - 10;
		else
			nb -= 'a' - 10;
		i++;
	}
	return (nb);
}
