/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 22:04:59 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 17:46:13 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		get_rgb(t_rgb *col, uint32_t src)
{
	col->r = (src >> 16) & 0xFF;
	col->g = (src >> 8) & 0xFF;
	col->b = src & 0xFF;
}

static void		get_new_val(uint8_t *c1, uint8_t *c2, double rap)
{
	if (*c1 <= *c2)
		*c1 += (*c2 - *c1) * rap;
	else
		*c1 -= (*c1 - *c2) * rap;
	*c1 &= 0xFF;
}

static uint32_t	px_col(uint32_t col_src, uint32_t col_dest, double rap)
{
	t_rgb	src;
	t_rgb	dest;

	get_rgb(&src, col_src);
	get_rgb(&dest, col_dest);
	get_new_val(&src.r, &dest.r, rap);
	get_new_val(&src.g, &dest.g, rap);
	get_new_val(&src.b, &dest.b, rap);
	return ((src.r << 16) + (src.g << 8) + src.b);
}

t_uint			ft_color(t_uint itter, t_uint max, t_colorscheme color)
{
	uint32_t		ret;
	int				cmpt;
	static t_color	palette[10] = {
		{1, {0x000000, 0xFFFFFF}},
		{1, {0x000000, 0xFF0000}},
		{1, {0x000000, 0x00FF00}},
		{1, {0x000000, 0x0000FF}},
		{1, {0x000000, 0xFFFF00}},
		{1, {0x000000, 0xFF00FF}},
		{1, {0x000000, 0x00FFFF}},
		{4, {0x7F0000, 0xDA0000, 0xFFFFFF, 0xFFFFC4, 0xFFFF30}},
		{4, {0x006800, 0x00FF00, 0xFFFFFF, 0xFF0000, 0xFF0080}},
		{4, {0x00FFCC, 0x0000FF, 0xFFFFFF, 0xFF3A00, 0xF837FF}}};

	if (max == 0)
		return (palette[color].ar[0]);
	cmpt = 0;
	while (itter > (max * (++cmpt) / palette[color].nb_col))
		;
	ret = px_col(palette[color].ar[cmpt - 1], palette[color].ar[cmpt], (itter)
		/ (double)(max * cmpt / palette[color].nb_col));
	return (ret);
}
