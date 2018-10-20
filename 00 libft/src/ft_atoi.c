/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:21:10 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/03 23:53:43 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(char const *str)
{
	int		i;
	int		neg;
	int		nb;

	i = 0;
	nb = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	neg = (str[i] == '-') ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+') ? 1 : 0;
	while (ft_isdigit(str[i]) && str[i])
		nb = (nb * 10) + str[i++] - 48;
	return (neg * nb);
}
