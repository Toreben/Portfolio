/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/08 11:55:40 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:20:44 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int	notum_terram(char color, float heigh)
{
	if (color == 'n')
	{
		if (heigh <= 0)
			return (0x79FBFD);
		else if (0 < heigh && heigh <= 20)
			return (0x71FA4C);
		else if (20 < heigh && heigh <= 25)
			return (0xFFFE7F);
		else if (25 < heigh && heigh <= 40)
			return (0xF8CD46);
		else if (40 < heigh && heigh <= 65)
			return (0xF29D4B);
		else if (65 < heigh && heigh <= 90)
			return (0xC06B3F);
		else
			return (0xFFFFFF);
	}
	else
	{
		if (heigh < 0)
			return (0xBC0909);
		else
			return (0xFFFAAA);
	}
}

static int	paon_pan_pan(char color, float heigh)
{
	if (color == 'p')
	{
		if (heigh < -25)
			return (0x18BAC9);
		else if (-25 <= heigh && heigh < 0)
			return (0x0D0B63);
		else if (0 <= heigh && heigh < 25)
			return (0x310B63);
		else
			return (0x0F0223);
	}
	else if (heigh < -10)
		return (0xFF8649);
	else if (-10 <= heigh && heigh < 0)
		return (0xDB3E0F);
	else if (0 <= heigh && heigh < 10)
		return (0xFFD1D1);
	else if (10 <= heigh && heigh < 20)
		return (0xFF96F8);
	else if (20 <= heigh && heigh < 30)
		return (0xC40B39);
	else
		return (0xB10BC4);
}

static int	kouign_amann(float heigh)
{
	if (heigh < -30)
		return (0x895D47);
	else if (-30 <= heigh && heigh < -15)
		return (0xB2998D);
	else if (-15 <= heigh && heigh < 0)
		return (0x282827);
	else if (0 <= heigh && heigh < 30)
		return (0x5B5B5B);
	else if (15 <= heigh && heigh < 30)
		return (0xADA39F);
	else if (30 <= heigh && heigh < 45)
		return (0xFCF2E8);
	else
		return (0xFFFFFF);
}

static int	mars(char color, float heigh)
{
	if (color == 'm')
	{
		if (heigh < 3)
			return (0x7A3022);
		else if (3 <= heigh && heigh < 6)
			return (0x9B6849);
		else if (6 <= heigh && heigh < 9)
			return (0xF49542);
		else if (9 <= heigh && heigh < 12)
			return (0xA34D37);
		else
			return (0xB23A1C);
	}
	else
	{
		if (0 <= heigh && heigh < 5)
			return (0x36748C);
		else if (5 <= heigh && heigh < 10)
			return (0x50AEA0);
		else
			return (0xFFFFFF);
	}
}

int			set_point_color(char colorscheme, t_point point)
{
	if (colorscheme == 'n' || colorscheme == 'f')
		return (notum_terram(colorscheme, point.z3d_or));
	else if (colorscheme == 'p' || colorscheme == 'r')
		return (paon_pan_pan(colorscheme, point.z3d_or));
	else if (colorscheme == 'k')
		return (kouign_amann(point.z3d_or));
	else if (colorscheme == 'm')
		return (mars(colorscheme, point.z3d_or));
	else
		return (mars(colorscheme, point.z3d_or));
}
