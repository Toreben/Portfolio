/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hoover.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/03/24 23:38:20 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/24 23:40:08 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

SDL_bool	hoover(SDL_Rect rect, SDL_Point point)
{
	if ((rect.x <= point.x) && (point.x <= rect.x + rect.w) && (rect.y <= point.y) && (point.y <= rect.y + rect.h))
		return (SDL_TRUE);
	return (SDL_FALSE);
}