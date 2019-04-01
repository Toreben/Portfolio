/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   scene.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 19:29:28 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 08:10:07 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

/*
** Structure creee pour l'AA
*/
typedef unsigned int	t_uint;
typedef struct			s_color
{
	t_uint			r;
	t_uint			g;
	t_uint			b;
	t_uint			a;

}						t_color;


typedef struct			s_spot
{
	t_vector		pos;
	double			intensity;
	t_color			color;

	struct s_spot	*next;
}						t_spot;

typedef struct 			s_ambient
{
	double			intensity;
	t_color			color;
}						t_ambient;

typedef struct			s_camera
{
	t_vector		pos;
	double			dist;
	double			ang_x;
	double			ang_y;
}						t_camera;

enum					e_type
{
	SPOT = 0,
	ERROR,
	SPHERE,
	CONE,
	CYLINDER,
	PLANE
};

struct s_scene;

typedef	struct			s_object
{
	enum e_type		type;
	t_vector		pos;
	t_vector		dir;
	double			size;
	t_color			color;
	double			(*hit)(t_vector, struct s_object*, t_vector);
	t_vector		(*norm_obj)(struct s_vector, struct s_object*);

	struct s_object	*next;
}						t_object;

typedef struct			s_quat
{
	double			x;
	double			y;
	double			z;
	double			w;
}						t_quat;


enum					e_error
{
	I_OBJ_TYPE = 0x00000001,
	I_ARG = 0x00000002,
	I_NB_ARG = 0x00000004,
	CBL_EXP = 0x00000008,
	CBR_EXP = 0x00000010,
	BL_EXP = 0x00000020,
	BR_EXP = 0x00000040,
	MISS_LINE = 0x00000080,
	EMPT_LINE = 0x00000100,
	I_LINE = 0x00000200,
	E_LINE = 0x00000400,
	FE_BLOCK = 0x00000800,
	FW_BLOCK = 0x00001000,
	FI_OBJ = 0x00002000,
	NE_O = 0x10000000
};

#endif
