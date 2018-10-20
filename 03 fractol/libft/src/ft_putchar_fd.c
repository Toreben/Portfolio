/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putchar_fd.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:19:49 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:25:45 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	chr;

	if (0 <= c)
		write(fd, &c, 1);
	else
	{
		chr = c + 128;
		if (chr < 64)
		{
			c = 0xc2;
			write(fd, &c, 1);
		}
		else
		{
			c = 0xc3;
			write(fd, &c, 1);
			chr -= 64;
		}
		c = 0x80;
		c = c + chr;
		write(fd, &c, 1);
	}
}
