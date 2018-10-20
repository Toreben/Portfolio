/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/26 18:35:50 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/12 23:48:16 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# if defined __linux__
#  include <stdint.h>
#  include "key_map_linux.h"
# elif __APPLE__
#  include "key_map_macos.h"
# endif

# include <math.h>
# include <pthread.h>
# include "libft.h"
# include "mlx.h"
# include "comp.h"
# include "mandel.h"
# include "burning.h"
# include "julia.h"

# define WIN_X		1855
# define WIN_Y		1028
# define IMG_G_X	1469
# define IMG_G_Y	882
# define UI_X		1469
# define UI_Y		140
# define BORDER   	6
# define IMG_D_X	WIN_X - IMG_G_X - BORDER
# define IMG_D_Y	(WIN_Y - (BORDER * (NB_FRACT - 1))) / NB_FRACT

# define ITTER_MAX 	50
# define NB_THREAD	8
# define NB_COLOR	10
# define NB_FRACT	3
# define ZOOM		1.1

typedef unsigned int	t_uint;

typedef enum			e_typefract
{
	MANDEL,
	BURNING,
	JULIA
}						t_typefract;

typedef enum			e_colorscheme
{
	WHITE,
	RED,
	GREEN,
	BLUE,
	YELLOW,
	PURPLE,
	CYAN,
	MRED,
	MGREEN,
	MBLUE
}						t_colorscheme;

typedef struct			s_image
{
	int					bpp;
	int					s_l;
	int					endian;
	void				*img_ptr;
	t_uint				*img_str;
}						t_image;

typedef struct			s_fractol
{
	t_typefract			current_fract;

	t_mandel			mandel;
	t_burning			burning;
	t_julia				julia;
	t_colorscheme		colorscheme;

	t_uint				itter_max;
	double				zoom;
}						t_fractol;

typedef struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_image				img;

	t_fractol			fract;
}						t_window;

typedef struct			s_thread
{
	void				*fract;
	t_uint				*img_str;
	double				zoom;
	t_uint				itter_max;
	int					num_thread;
	t_colorscheme		colorscheme;
}						t_thread;

typedef struct			s_color
{
	int					nb_col;
	uint32_t			ar[16];
}						t_color;

typedef struct			s_rgb
{
	uint8_t				r;
	uint8_t				g;
	uint8_t				b;
}						t_rgb;

/*
**MAIN.C
*/
void					loop_fract(t_window *win);

/*
**INIT.C
*/
t_window				*create_win(void);

/*
**EVENTS_KEY.C
*/
int						deal_key(int key, void *param);

/*
**QUIT.C
*/
void					quit(t_window *win, int ex);

/*
**EVENT_MOUSE.C
*/
int						deal_mouse(int button, int x, int y, void *param);
void					red_cross(void *param);

/*
**COLOR.C
*/
t_uint					ft_color(t_uint itter, t_uint max,
							t_colorscheme color);

/*
**UI.C
*/
void					ft_ui(t_window *win);

/*
**PRINT_SEG.C
*/
void					print_seg(t_window *win, t_comp p1, t_comp p2);

/*
**MUSIC.C
*/
int						play_music(int key);

/*
**MOUSE_FRACTS.C
*/
void					mouse_mandel(int button, double x, double y,
							t_fractol *fract);
void					mouse_burning(int button, double x, double y,
							t_fractol *fract);
void					mouse_julia(int button, double x, double y,
							t_fractol *fract);
#endif
