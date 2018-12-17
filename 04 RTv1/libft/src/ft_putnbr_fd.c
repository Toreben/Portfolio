/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:20:18 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:20:43 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n != -2147483648)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		else if (10 <= n)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (ft_isdigit(n + '0'))
			ft_putchar_fd(n + '0', fd);
	}
	else
		ft_putstr_fd("-2147483648", fd);
}
