/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ui.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/28 19:28:51 by bnoyer       #+#   ##    ##    #+#       */
/*   Updated: 2019/03/30 13:32:36 by bnoyer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

# include "text_box_pos.h"

# define VWPW 1874.
# define VWPH 1158.
# define VWPX 686
# define VWPY 282

# define BUTTONW 180
# define BUTTONH 45
# define BUTONX 264

# define MODIFY_Y 510
# define ADD_Y 1254

# define SCROLLW 234
# define SCROLLH 394
# define SCROLLY 92

# define SCROLL_OBJ_X 73
# define SCROLL_SPT_X 400

# define TYPE_ZONE_W 240
# define TYPE_ZONE_H 190
# define TYPE_ZONE_X 60
# define TYPE_ZONE_Y 683

# define TYPE_ZONE_ELEM_W 240
# define TYPE_ZONE_ELEM_H 38

# define ICONE_SIZE 32

# define EDIT_X 60
# define EDIT_Y 683
# define EDIT_W 587
# define EDIT_H 406

# define SELECT_X 73
# define SELECT_Y 92
# define SELECT_W 583
# define SELECT_H 460

typedef struct			s_scroll_box_elem
{
	char						*name;
	void						*address;
	SDL_Texture					*txr;	//a proteger
	SDL_Rect					rect_pos;
	struct s_scroll_box_elem	*next;
}						t_scroll_box_elem;

typedef struct 			s_scroll_box
{
	SDL_Texture			*box;	//a proteger

	t_scroll_box_elem	*lst;
	SDL_Rect 			pos;
	int					first_y;
}						t_scroll_box;

typedef struct			s_text_box
{
	SDL_Rect	pos;
	TTF_Font	*font;
	char		*content;	//A proteger
	SDL_Texture	*content_display;
	SDL_Texture	*placeholder;	//A proteger
}						t_text_box;


typedef struct 			s_select_type_zone
{
	SDL_Texture 			*txr;
	SDL_Rect				pos;

	SDL_Rect	sph;
	SDL_Rect	pln;
	SDL_Rect	con;
	SDL_Rect	cld;
	SDL_Rect	spt;
}						t_select_type_zone;

typedef struct			s_edit_zone
{
	SDL_Texture			*tb_img;
	t_select_type_zone	sel;
	t_text_box			pos_x;
	t_text_box			pos_y;
	t_text_box			pos_z;
	t_text_box			dir_x;
	t_text_box			dir_y;
	t_text_box			dir_z;
	t_text_box			size;
	t_text_box			colour;
	t_text_box			transparency;
	t_text_box			txr_path;
}						t_edit_zone;

typedef struct			s_ui
{
	SDL_Texture		*txr_ui;	//a proteger
	SDL_Color		bbg;

	t_scroll_box	objs;
	t_scroll_box	spts;

	SDL_Texture		*bw;	//a proteger
	SDL_Texture		*sepia;	//a proteger
	SDL_Rect 		rect_add;
	SDL_Rect		rect_modify;
	t_edit_zone		edit;
}						t_ui;

typedef struct s_scene	t_scene;

// void		ecriture_scroll_box(SDL_Renderer *rdr, t_scroll_box *box);
SDL_bool 				can_scroll_down(t_scroll_box box);
SDL_bool 				can_scroll_up(t_scroll_box box);
void					print_scroll(SDL_Renderer *rdr, t_scroll_box *to_print, SDL_Texture *txr_target);
enum e_type				get_lst_elem_infos(t_scene *scn, SDL_Point mouse_pos, void **selected);
SDL_bool				hoover(SDL_Rect rect, SDL_Point point);

void					key_handler(t_scene *scn, SDL_Event e, SDL_bool *is_sepia_on, SDL_bool *is_bw_on);
void 					mouse_wheel_handler(t_scene *scn, SDL_Event e);
void					mouse_button_handler(t_scene *scn, void **selected, enum e_type *type);
void					draw_window(t_scene *scn);
void 					rdr_copybmp(SDL_Renderer *rdr, char *txt, SDL_Rect pos);
void					ft_generate_edit_zone(SDL_Renderer *rdr, t_edit_zone *zone, TTF_Font *font);
SDL_Texture				*load_text(SDL_Renderer *rdr, char *txt, TTF_Font *font, SDL_Color col);
void					ft_generate_type_zone(SDL_Renderer *rdr, t_select_type_zone *zone, TTF_Font *font);
#endif
