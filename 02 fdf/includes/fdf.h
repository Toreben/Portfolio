/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 23:35:23 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/14 12:15:14 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "sys/types.h"
# include "sys/stat.h"
# define FAC 25
# define OMEGA 120
# define ALPHA 120
# ifdef __APPLE__
#  define WIN_X 2560
#  define WIN_Y 1395
#  define UID_X 260
#  include "key_map_macos.h"
# endif
# ifdef linux
#  define WIN_X 1920
#  define WIN_Y 1080
#  define UID_X 260
#  include "key_map_linux.h"
# endif
# define IMG_X (WIN_X - UID_X)

typedef struct		s_origin
{
	int				x0;
	int				y0;
}					t_origin;

typedef struct		s_point
{
	float			x3d_or;
	float			y3d_or;
	float			z3d_or;
	float			x3d_rel;
	float			y3d_rel;
	float			x3d_rot;
	float			y3d_rot;
	float			z3d_rot;
	float			x2d;
	float			y2d;
	int				col;
}					t_point;

typedef struct		s_angle
{
	int				deg;
	float			rad;
	float			sin_ang;
	float			cos_ang;
}					t_angle;

typedef struct		s_matrix_3
{
	t_angle			ang;
	float			mat[3][3];
}					t_matrix_3;

typedef struct		s_image
{
	int				bpp;
	int				s_l;
	int				endian;
	void			*img_ptr;
	unsigned int	*img_str;
}					t_image;

typedef struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			img;
	char			*title;
	char			*colorscheme;

	t_origin		repere;

	t_point			**map;
	float			fac;
	float			fac_aj;
	t_angle			omega;
	t_angle			alpha;
	int				fac_z;
	t_matrix_3		rx;
	t_matrix_3		ry;
	t_matrix_3		rz;
	t_matrix_3		rot;
	char			color;
}					t_window;

/*
**FILE_MANIP.C
*/
int					open_map(const char *name);
void				close_map(int fd);
size_t				get_map_y(int fd);

/*
**CREATION.C
*/
t_point				**create_map(int fd, size_t map_y);
t_point				calcul_point_2d(t_point point, t_window *win);
t_window			*create_win(t_window *win, char *title, char *color);

/*
**PRE_PRINT.C
*/
void				init_print(t_point ***map, char *title, char *colorscheme);

/*
**EVENTS_KEY.C
*/
int					deal_key(int key, void *param);
void				update_point(t_window *win, int key);

/*
**EVENTS_MOUSE.C
*/
int					deal_mouse(int button, int x, int y, void *param);
void				red_cross(void *param);

/*
**PRINT.C
*/
void				print_map(t_window *win);

/*
**BONUS.C
*/
char				*easter_egg(int key, int *music_playing, char *easter);
int					stop_music(void);

/*
**ANGLE.C
*/
t_angle				ft_update_angle(t_angle angle);

/*
**MATRIX.C
*/
t_matrix_3			fill_mat_x(t_matrix_3 mat);
t_matrix_3			fill_mat_y(t_matrix_3 mat);
t_matrix_3			fill_mat_z(t_matrix_3 mat);
t_matrix_3			mult_matrix_matrix(t_matrix_3 mat1, t_matrix_3 mat2);
t_point				mult_matrix_point(t_matrix_3 mat, t_point point, int fac_z);

/*
**UDI.C
*/
void				ft_uid(t_window *win);

/*
**QUIT.C
*/
void				quit(t_window *win, t_point **map);

/*
**COLOR.C
*/
int					set_point_color(char colorscheme, t_point point);

/*
**CHECK_TRACE.C
*/
int					is_in_img(t_point point);
int					is_to_print(t_point point, t_window *win);

/*
**TRACE.C
*/
void				print_seg(t_window *win, t_point p1, t_point p2, char img);

/*
**FILL_MAP.C
*/
t_point				**fill_map(int fd, t_point **map, char *line, size_t map_y);
#endif
