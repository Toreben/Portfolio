# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/03 19:56:23 by bnoyer       #+#   ##    ##    #+#        #
#    Updated: 2018/11/27 23:21:37 by bnoyer      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, re, clean, fclean, lib

NAME = rtv1

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
FRAMEWORK_PATH = frameworks
SDL = SDL2
SDL_INC = $(FRAMEWORK_PATH)/$(SDL).framework/Headers
FLAG_SDL = -F$(FRAMEWORK_PATH) -framework $(SDL) -rpath $(FRAMEWORK_PATH)
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

LIBVECT_PATH = libvect
LIBVECT = $(LIBVECT_PATH)/libvect.a

SRC_NAME =	rtv1.c

SRC_PATH =	src

INC_NAME =	rtv1.h

INC_PATH =	includes
INCLUDES =	-I$(LIBFT_PATH)

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ_PATH =	obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

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

SRC_NAME = 	ft_check_cam.c 					\
			ft_check_color.c 				\
			ft_check_error.c 				\
			ft_check_object.c 				\
			ft_check_pos_dir.c 				\
			ft_check_spot.c 				\
			ft_check_vector.c 				\
			ft_check_viewport.c 			\
			ft_extract_object.c 			\
			ft_extract_vect.c 				\
			ft_extract_view.c 				\
			ft_norm.c						\
			ft_pars.c 						\
			ft_print_error.c 				\
			ft_rotate.c						\
			ft_shading.c					\
			ft_skip_comm.c 					\
			hit.c							\
			ligth.c							\
			main.c 							\
			rtv1.c

SRC_PATH =	src

INC_NAME =	rtv1.h

INC_PATH =	includes

INCLUDES =	-I$(LIBFT_INC) -I$(LIBVECT_INC) -I$(INC_PATH) -I$(SDL_INC)

OBJ_NAME =	$(SRC_NAME:.c=.o)
OBJ_PATH =	obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: makelib message $(NAME)

message:
	@make -q $(NAME) && echo "\033[1mLe projet est deja a jour\033[0m" || true

$(NAME): $(LIBFT) $(LIBVECT) $(OBJ)
	@ printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
	@ $(CC) $(CC_FLAGS) $(OPTI_FLAG) -o $@ $(OBJ) $(INCLUDES) $(FLAG_LIB) $(FLAG_SDL)

libft: $(LIBFT)
$(LIBFT):
	@ make -C $(LIBFT_PATH)

libvect: $(LIBVECT)
$(LIBVECT):
	@ make -C $(LIBVECT_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ printf "\033[1mCompilation de \033[36m%-20s\033[37m\ten \033[32m%-25s\033[0m ✅\n" $< $@
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
