/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_newtetri.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/01 22:13:32 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 01:51:29 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_newtetri(void)
{
	t_tetri	*nouveau;

	if (!(nouveau = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	nouveau->next = NULL;
	return (nouveau);
}
