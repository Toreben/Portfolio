/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:21:10 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/07 04:30:25 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

double		ft_atof(char const *str)
{
	int		itter;
	int		neg;
	double	nb;
	int		dot;

	itter = 0;
	nb = 0;
	while ((9 <= str[itter] && str[itter] <= 13) || str[itter] == ' ')
		itter++;
	neg = (str[itter] == '-') ? -1 : 1;
	itter += (str[itter] == '-' || str[itter] == '+') ? 1 : 0;
	while (ft_isdigit(str[itter]) && str[itter])
		nb = (nb * 10) + str[itter++] - '0';
	dot = itter;
	if (str[itter] == '.')
		while (ft_isdigit(str[++itter]) && str[itter])
			nb += (double)(str[itter] - '0') / (ft_pow(10, (itter - dot)));
	if (str[itter] == 'e' || str[itter] == 'E')
		nb = ft_pow(nb, ft_atoi(str + itter + 1));
	return (neg * nb);
}
