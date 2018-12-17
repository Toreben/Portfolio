# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 21:16:56 by bnoyer       #+#   ##    ##    #+#        #
#    Updated: 2018/12/03 21:48:03 by bnoyer      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, re, clean, fclean

NAME = libvect.a
CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_NAME = 	ft_v_add.c				\
			ft_v_dot.c				\
			ft_v_normalize.c		\
			ft_v_norme.c			\
			ft_v_scal.c				\
			ft_v_sub.c				\
			ft_v_cross.c
SRC_PATH = src

INC_NAME = vector.h
INC_PATH = includes
INCLUDES = -I$(INC_PATH)

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: message $(NAME)

message:
	@make -q $(NAME) && echo "\033[1mLibvect est a jour\033[0m" || true

$(NAME): $(OBJ)
	@ ar rcs $(NAME) $(OBJ)
	@ echo "\033[1mCompilation de la libvect reussie\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ $(CC) $(CC_FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ_PATH)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
