# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/03 19:56:23 by bnoyer       #+#   ##    ##    #+#        #
#    Updated: 2019/03/30 02:57:25 by bnoyer      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, re, clean, fclean, lib

NAME = rt

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
FRAMEWORK_PATH = frameworks

SDL = SDL2
SDL_INC = $(FRAMEWORK_PATH)/$(SDL).framework/Headers
FLAG_SDL2 = -F$(FRAMEWORK_PATH) -framework $(SDL) -rpath $(FRAMEWORK_PATH)

SDL_TTF = SDL2_TTF
SDL_TTF_INC = $(FRAMEWORK_PATH)/$(SDL_TTF).framework/Headers
FLAG_SDL_TTF = -F$(FRAMEWORK_PATH) -framework $(SDL_TTF) -rpath $(FRAMEWORK_PATH)

FLAG_SDL = $(FLAG_SDL2) $(FLAG_SDL_TTF)
endif
ifeq ($(UNAME), Linux)
SDL_INC = /usr/include/SDL2 -D_REENTRANT
FLAG_SDL = -L/usr/lib64 -lSDL2 -lm
endif

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra
OPTI_FLAG = -O2

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)/includes

LIBVECT_PATH = libvect
LIBVECT = $(LIBVECT_PATH)/libvect.a
LIBVECT_INC = $(LIBVECT_PATH)/includes

FLAG_FT = -Llibft -lft
FLAG_VECT = -Llibvect -lvect
FLAG_LIB = $(FLAG_FT) $(FLAG_VECT)

SRC_UI_NAME =	ft_create_ui.c			\
				ft_ui.c					\
				get_lst_elem_infos.c	\
				hoover.c				\
				can_scroll.c			\
				mouse_button_handler.c	\
				key_handler.c			\
				mouse_wheel_handler.c	\
				ft_generate_edit_zone.c	\
				rdr_copybmp.c			\
				load_text.c				\
				print_scroll.c			\
				ft_generate_type_zone.c

SRC_UI_PATH = ui
SRC_UI = $(addprefix $(SRC_UI_PATH)/,$(SRC_UI_NAME))

SRC_PARSING_NAME =	ft_check_ambiant.c				\
					ft_check_cam.c					\
					ft_check_color.c				\
					ft_check_error.c				\
					ft_check_intensity.c			\
					ft_check_object.c				\
					ft_check_pos_dir.c				\
					ft_check_spot.c					\
					ft_check_vector.c				\
					ft_check_viewport.c				\
					ft_extract_general.c			\
					ft_extract_object.c				\
					ft_extract_vect.c				\
					ft_extract_view.c				\
					ft_get_color.c					\
					ft_pars.c						\
					ft_skip_comm.c
SRC_PARSING_PATH = parsing

SRC_PARSING = $(addprefix $(SRC_PARSING_PATH)/,$(SRC_PARSING_NAME))

SRC_TEXTRUES_NAME =	textures.c
SRC_TEXTRUES_PATH = textures
SRC_TEXTRUES = $(addprefix $(SRC_TEXTRUES_PATH)/,$(SRC_TEXTRUES_NAME))

SRC_RAYTRACING_NAME =	ft_norm.c						\
						ft_rotate.c						\
						ft_shading.c					\
						hit.c							\
						ligth.c							\
						rt.c
SRC_RAYTRACING_PATH = raytracing
SRC_RAYTRACING = $(addprefix $(SRC_RAYTRACING_PATH)/,$(SRC_RAYTRACING_NAME))

SRC_NAME =	ft_print_error.c				\
			init.c							\
			main.c							\
			$(SRC_UI)						\
			$(SRC_PARSING)					\
			$(SRC_TEXTRUES)					\
			$(SRC_RAYTRACING)
SRC_PATH =	src
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

INC_NAME =	rt.h	\
			scene.h	\
			ui.h	
INC_PATH =	includes
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

INCLUDES =	-I$(LIBFT_INC) -I$(LIBVECT_INC) -I$(INC_PATH) -I$(SDL_INC) -I$(SDL_TTF_INC)

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ_PATH =	obj

SUB_PATH = 	$(SRC_UI_PATH)						\
			$(SRC_PARSING_PATH)					\
			$(SRC_TEXTRUES_PATH)				\
			$(SRC_RAYTRACING_PATH)
OBJ_SUB = $(addprefix $(OBJ_PATH)/,$(SUB_PATH))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: makelib message $(NAME)

message:
	@make -q $(NAME) && echo "\033[1mLe projet est deja a jour\033[0m" || true

$(NAME): $(LIBFT) $(LIBVECT) $(OBJ) Makefile
	@ printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
	@ $(CC) $(CC_FLAGS) $(OPTI_FLAG) -o $@ $(OBJ) $(INCLUDES) $(FLAG_LIB) $(FLAG_SDL)

libft: $(LIBFT)
$(LIBFT):
	@ make -C $(LIBFT_PATH)

libvect: $(LIBVECT)
$(LIBVECT):
	@ make -C $(LIBVECT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) Makefile
	@ mkdir -p $(OBJ_SUB) 2> /dev/null || true
	@ printf "\033[1mCompilation de \033[36m%-30s\033[37m\ten \033[01;34m%-35s\033[0m ✅\n" $< $@
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ_PATH)
	@ make -C $(LIBFT_PATH) clean
	@ make -C $(LIBVECT_PATH) clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C $(LIBFT_PATH) fclean
	@ make -C $(LIBVECT_PATH) fclean

makelib:
	@ make -C $(LIBFT_PATH)
	@ make -C $(LIBVECT_PATH)

re: fclean all
