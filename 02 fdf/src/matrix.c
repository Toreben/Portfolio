/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   matrix.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/18 18:42:52 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 08:21:18 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_matrix_3	fill_mat_x(t_matrix_3 mat)
{
	mat.ang = ft_update_angle(mat.ang);
	mat.mat[0][0] = 1;
	mat.mat[0][1] = 0;
	mat.mat[0][2] = 0;
	mat.mat[1][0] = 0;
	mat.mat[1][1] = cos(mat.ang.rad);
	mat.mat[1][2] = -sin(mat.ang.rad);
	mat.mat[2][0] = 0;
	mat.mat[2][1] = sin(mat.ang.rad);
	mat.mat[2][2] = cos(mat.ang.rad);
	return (mat);
}

t_matrix_3	fill_mat_y(t_matrix_3 mat)
{
	mat.ang = ft_update_angle(mat.ang);
	mat.mat[0][0] = cos(mat.ang.rad);
	mat.mat[0][1] = 0;
	mat.mat[0][2] = sin(mat.ang.rad);
	mat.mat[1][0] = 0;
	mat.mat[1][1] = 1;
	mat.mat[1][2] = 0;
	mat.mat[2][0] = -sin(mat.ang.rad);
	mat.mat[2][1] = 0;
	mat.mat[2][2] = cos(mat.ang.rad);
	return (mat);
}

t_matrix_3	fill_mat_z(t_matrix_3 mat)
{
	mat.ang = ft_update_angle(mat.ang);
	mat.mat[0][0] = cos(mat.ang.rad);
	mat.mat[0][1] = -sin(mat.ang.rad);
	mat.mat[0][2] = 0;
	mat.mat[1][0] = sin(mat.ang.rad);
	mat.mat[1][1] = cos(mat.ang.rad);
	mat.mat[1][2] = 0;
	mat.mat[2][0] = 0;
	mat.mat[2][1] = 0;
	mat.mat[2][2] = 1;
	return (mat);
}

t_matrix_3	mult_matrix_matrix(t_matrix_3 mat1, t_matrix_3 mat2)
{
	t_matrix_3	res;
	int			i;
	int			j;
	int			k;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			res.mat[i][j] = 0;
			k = -1;
			while (++k < 3)
				res.mat[i][j] += mat1.mat[i][k] * mat2.mat[k][j];
		}
	}
	return (res);
}

t_point		mult_matrix_point(t_matrix_3 mat, t_point point, int fac_z)
{
	point.x3d_rot = mat.mat[0][0] * point.x3d_rel + mat.mat[0][1]
		* point.y3d_rel + mat.mat[0][2] * point.z3d_or * fac_z;
	point.y3d_rot = mat.mat[1][0] * point.x3d_rel + mat.mat[1][1]
		* point.y3d_rel + mat.mat[1][2] * point.z3d_or * fac_z;
	point.z3d_rot = mat.mat[2][0] * point.x3d_rel + mat.mat[2][1]
		* point.y3d_rel + mat.mat[2][2] * point.z3d_or * fac_z;
	return (point);
}
