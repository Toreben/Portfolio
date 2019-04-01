/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:18:25 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:25:25 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*dst;
	int		nb;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = (0 > n ? -n : n);
	neg = (0 > n ? 1 : 0);
	i = (nb == 0 ? 1 : 0);
	while (nb && 0 <= i++)
		nb /= 10;
	if (!(dst = (char*)ft_memalloc(sizeof(char) * (i += neg) + 1)))
		return (NULL);
	nb = (0 > n ? -n : n);
	while (i--)
	{
		dst[i] = ((i == 0 && neg) ? '-' : nb % 10 + '0');
		nb /= ((i == 0 && neg) ? 1 : 10);
	}
	return (dst);
}
