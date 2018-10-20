/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   comp.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 18:58:38 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/14 22:38:04 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_comp	bop_comp(t_comp n1, t_comp n2, t_bopcomp op)
{
	t_comp res;

	if (op == MULT)
	{
		res.rea = (n1.rea * n2.rea) - (n1.ima * n2.ima);
		res.ima = (n1.rea * n2.ima) + (n1.ima * n2.rea);
	}
	else if (op == ADD)
	{
		res.rea = n1.rea + n2.rea;
		res.ima = n1.ima + n2.ima;
	}
	else if (op == SUB)
	{
		res.rea = n1.rea - n2.rea;
		res.ima = n1.ima - n2.ima;
	}
	else
	{
		res.rea = ((n2.rea * n1.rea) + (n2.ima * n1.ima)) / ((n2.rea * n2.rea)
			+ (n2.ima * n2.ima));
		res.ima = ((n2.rea * n1.ima) - (n2.ima * n1.rea)) / ((n2.rea * n2.rea)
			+ (n2.ima * n2.ima));
	}
	return (res);
}

double	mod_comp(t_comp zn)
{
	return (sqrt(zn.rea * zn.rea) + (zn.ima * zn.ima));
}
