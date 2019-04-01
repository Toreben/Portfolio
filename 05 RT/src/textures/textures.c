/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   textures.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 12:04:09 by mhervet      #+#   ##    ##    #+#       */
/*   Updated: 2019/03/26 20:33:45 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static void	ft_convert_bpp(unsigned char *pixels, t_tex *tex)
{
	t_uint			i;
	t_uint			j;
	t_uint			k;

	k = 0;
	j = 0;
	while (j < tex->height)
	{
		i = 0;
		while (i < tex->width)
		{
			tex->img[(tex->height - j - 1) * tex->width + i].b = ((t_uint)pixels[k++]);
			tex->img[(tex->height - j - 1) * tex->width + i].g = ((t_uint)pixels[k++]);
			tex->img[(tex->height - j - 1) * tex->width + i].r = ((t_uint)pixels[k++]);
			i++;
		}
		j++;
	}
}

static t_tex	ft_img_size(unsigned char *header)
{
	t_tex			tex;

	tex.width = ((t_uint)header[0x12]);
	tex.width += ((t_uint)header[0x13]) * 0x0100;
	tex.width += ((t_uint)header[0x14]) * 0x010000;
	tex.width += ((t_uint)header[0x15]) * 0x01000000;
	tex.height = ((t_uint)header[0x16]);
	tex.height += ((t_uint)header[0x17]) * 0x0100;
	tex.height += ((t_uint)header[0x18]) * 0x010000;
	tex.height += ((t_uint)header[0x19]) * 0x01000000;
	return (tex);
}

t_tex	ft_parsebmp(int fd)
{
	t_tex			tex;
	unsigned char	header[55];
	unsigned char	*pixels;

	if (fd == -1)
		ft_putstr("open() error\n");
	read(fd, header, 54);
	tex = ft_img_size(header);
	if (!(tex.img = malloc(tex.width * tex.height * sizeof(t_color))))
		tex.img = NULL;
	if (!(pixels = malloc(tex.width * tex.height * 3 * sizeof(unsigned char))))
		pixels = NULL;
	else
	{
		read(fd, pixels, tex.width * tex.height * 3);
		ft_convert_bpp(pixels, &tex);
		free(pixels);
	}
	close(fd);
	return (tex);
}
