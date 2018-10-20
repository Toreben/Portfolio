# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/04/03 19:56:23 by bnoyer       #+#   ##    ##    #+#        #
#    Updated: 2018/08/14 15:07:27 by bnoyer      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, re, clean, fclean, lib, mlx

NAME = fractol

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
FRAME = -framework
OGL = OpenGl
APPK = AppKit
FLAG_OS = $(FRAME) $(APPK) $(FRAME) $(OGL)
MLX_PATH = mlx_macos
endif
ifeq ($(UNAME), Linux)
FLAG_X11 = -lXext -lX11
FLAG_THREAD = -lpthread
FLAG_MATH = -lm
FLAG_OS = $(FLAG_THREAD) $(FLAG_X11) $(FLAG_MATH)
MLX_PATH = mlx_x11
endif

export CC = gcc
export CC_FLAGS = -Wall -Werror -Wextra
OPTI_FLAG = -O2

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)/includes

MLX = $(MLX_PATH)/libmlx.a
MLX_INC = $(MLX_PATH)

FLAG_FT = -Llibft -lft
FLAG_MLX = -L$(MLX_PATH) -lmlx
FLAG_LIB = $(FLAG_FT) $(FLAG_MLX)

SRC_NAME =	burning.c		\
			color.c			\
			comp.c			\
			events_key.c	\
			events_mouse.c	\
			init.c			\
			julia.c			\
			main.c			\
			mandel.c		\
			mouse_fracts.c	\
			music.c			\
			print_seg.c		\
			quit.c 			\
			ui.c

SRC_PATH = src

INC_NAME =	burning.h	\
			comp.h		\
			fractol.h	\
			julia.h		\
			mandel.h	

INC_PATH = includes
INCLUDES = -I$(LIBFT_INC) -I$(INC_PATH) -I$(MLX_INC)

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))



all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@ printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
	@ $(CC) $(CC_FLAGS) $(OPTI_FLAG) -o $@ $(OBJ) $(INCLUDES) $(FLAG_LIB) $(FLAG_OS)

libft: $(LIBFT)
$(LIBFT):
	@ make -C $(LIBFT_PATH)

mlx : $(MLX)
$(MLX):
	@ make -C $(MLX_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ printf "\033[1mCompilation de \033[36m%-20s\033[37m\ten \033[32m%-20s\033[0m ✅\n" $< $@
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ_PATH)
	@ make -C $(LIBFT_PATH) clean
	@ printf "\033[1mSuppression des objets \033[31m%s\033[0m ✅\n" $(OBJ_PATH)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make -C $(MLX_PATH) clean
	@ make -C $(LIBFT_PATH) fclean
	@ printf "\033[1mSuppression du binaire \033[31m%s\033[0m ✅\n" $(NAME)

re: fclean all
