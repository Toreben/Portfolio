/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atof.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:21:10 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 16:49:30 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static double	ft_dot(char const *str, int itter, double nb, int exp)
{
	int		dot;

	dot = itter;
	if (str[itter] == '.')
		while (ft_isdigit(str[++itter]) && str[itter])
			nb += (double)(str[itter] - '0') / (ft_pow(10, (itter - dot)));
	if (str[itter] == 'e' || str[itter] == 'E')
	{
		exp += ft_atoi(str + itter + 1);
		if ((exp <= -38 && nb < 1.175494) || (exp >= 38 && nb > 3.402823))
			nb = 0;
		else
			nb *= ft_pow(10, exp);
	}
	return (nb);
}

double			ft_atof(char const *str)
{
	int		itter;
	int		neg;
	double	nb;
	int		exp;

	itter = 0;
	nb = 0;
	while ((9 <= str[itter] && str[itter] <= 13) || str[itter] == ' ')
		itter++;
	neg = (str[itter] == '-') ? -1 : 1;
	itter += (str[itter] == '-' || str[itter] == '+') ? 1 : 0;
	exp = 1;
	while (ft_isdigit(str[itter]) && str[itter])
	{
		nb = (nb * 10) + str[itter++] - '0';
		exp++;
	}
	return (neg * ft_dot(str, itter, nb, exp));
}
