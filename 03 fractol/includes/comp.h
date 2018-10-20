/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   comp.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/10 10:17:42 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/05/14 22:38:11 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COMP_H
# define COMP_H

typedef enum		e_bopcom
{
	MULT,
	DIVI,
	ADD,
	SUB
}					t_bopcomp;

typedef struct		s_comp
{
	double			rea;
	double			ima;
}					t_comp;

/*
**COMP.C
*/
t_comp				bop_comp(t_comp n1, t_comp n2, t_bopcomp op);
double				mod_comp(t_comp zn);

#endif
