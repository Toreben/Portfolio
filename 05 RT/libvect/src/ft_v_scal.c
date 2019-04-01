/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_v_scal.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/24 00:47:35 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/24 01:04:47 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "vector.h"

t_vector	ft_v_scal(double a, t_vector v)
{
	t_vector	res;

	res.x = v.x * a;
	res.y = v.y * a;
	res.z = v.z * a;
	return (res);
}