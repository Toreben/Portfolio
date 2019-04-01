/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:08:18 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/22 21:16:46 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp_lst;

	if (f && lst)
	{
		if (!lst->next)
			return ((*f)(lst));
		else
		{
			tmp_lst = ft_lstmap(lst->next, (*f));
			ft_lstadd(&tmp_lst, (*f)(lst));
			return (tmp_lst);
		}
	}
	return (NULL);
}
