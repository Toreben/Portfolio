/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_error.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 17:38:59 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/17 21:25:08 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "rt.h"

static int	ft_err(int line, enum e_error mask)
{
	ft_putstr("Error on line ");
	ft_putnbr(line + 1);
	if (mask & I_OBJ_TYPE)
		ft_putendl(" : invalid object type.");
	else if (mask & I_ARG)
		ft_putendl(" : invalid argument.");
	else if (mask & I_NB_ARG)
		ft_putendl(" : invalid number of arguments.");
	else if (mask & CBL_EXP)
		ft_putendl(" : '{' expected.");
	else if (mask & CBR_EXP)
		ft_putendl(" : '}' expected.");
	else if (mask & BL_EXP)
		ft_putendl(" : '(' expected.");
	else if (mask & BR_EXP)
		ft_putendl(" : ')' expected.");
	else if (mask & MISS_LINE)
		ft_putendl(" : missing line.");
	else if (mask & EMPT_LINE)
		ft_putendl(" : empty line.");
	else if (mask & I_LINE)
		ft_putendl(" : invalid line.");
	else if (mask & E_LINE)
		ft_putendl(" : empty line.");
	return (1);
}

int			ft_ferr(int line, enum e_error mask)
{
	if (!(mask & FE_BLOCK) && !(mask & FW_BLOCK) && !(mask & FI_OBJ))
		return (ft_err(line, mask));
	if (mask & FE_BLOCK)
		ft_putendl(
			"Fatal error : empty object block, please, remove or fill it.");
	else if (mask & FW_BLOCK)
		ft_putendl(
			"Fatal error : wrong identificator name for objects block.");
	else if (mask & FI_OBJ)
	{
		ft_putstr("Fatal error : incomplete object type on line ");
		ft_putnbr(line);
		ft_putendl(".");
	}
	return (mask);
}
