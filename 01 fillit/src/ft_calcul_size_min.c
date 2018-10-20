/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_calcul_size_min.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dewalter <dewalter@le-101.fr>              +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/07 18:43:22 by dewalter     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 13:09:50 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_calcul_size_min(t_tetri *list)
{
	int		size_min;

	size_min = 0;
	while (list)
	{
		list = list->next;
		size_min++;
	}
	return (size_min);
}
