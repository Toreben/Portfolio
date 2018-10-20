/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:18:58 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:25:31 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;

	if (!(maillon = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(maillon->content = (void*)malloc(content_size)))
			return (NULL);
		maillon->content = ft_memcpy(maillon->content, content, content_size);
		maillon->content_size = content_size;
	}
	else
	{
		maillon->content = NULL;
		maillon->content_size = 0;
	}
	maillon->next = NULL;
	return (maillon);
}
