/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   gnl.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 15:56:41 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 19:45:20 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_line(char **line, char **save)
{
	char *tmp;
	char *posn;

	if ((posn = ft_strchr(*save, '\n')))
	{
		if (!(*line = ft_strsub(*save, 0, posn - *save)))
			return (-2);
		tmp = *save;
		if (!(*save = ft_strdup(posn + 1)))
			return (-2);
		tmp = ft_strdel(&tmp);
	}
	else
	{
		if (!(*line = ft_strdup(*save)))
			return (-2);
		tmp = *save;
		*save = ft_strdup("");
		tmp = ft_strdel(&tmp);
	}
	return (1);
}

static t_gnl	*ft_is_in_list(int fd, t_gnl **list)
{
	t_gnl	*tmp;

	tmp = *list;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	else
	{
		if (!(tmp = (t_gnl*)malloc(sizeof(t_gnl))))
			return (NULL);
		tmp->next = *list;
		tmp->fd = fd;
		tmp->save = NULL;
		tmp->end = 1;
		*list = tmp;
	}
	return (tmp);
}

int				gnl(int const fd, char **line)
{
	static t_gnl	*list_fd;
	int				ret;
	char			buff[BUFF_SIZE + 1];
	t_gnl			*cur;
	char			*tmp;

	if (fd < 0 || !line || (read(fd, 0, 0) <= -1))
		return (-1);
	if (!(cur = ft_is_in_list(fd, &list_fd))->end || ft_strchr(cur->save, '\n'))
		return (!cur->end ? 0 : ft_get_line(line, &(cur->save)));
	while (0 < (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = cur->save;
		cur->save = ft_strmerge(cur->save, buff);
		ft_strdel(&tmp);
		if (ft_strchr(cur->save, '\n'))
			break ;
	}
	if (ret == -1)
		return (-2);
	if (cur->save && ft_strlen(cur->save))
		return (ft_get_line(line, &(cur->save)));
	ft_strdel(&(cur->save));
	return ((cur->end = 0) - 1);
}
