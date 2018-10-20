# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 21:16:56 by bnoyer       #+#   ##    ##    #+#        #
#    Updated: 2018/08/14 15:07:40 by bnoyer      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all re clean fclean

NAME = fillit

FLAG_FT = -Llibft -lft
FLAG_LIB = $(FLAG_FT)

export CC = gcc
export CC_FLAGS = -Wall -Werror -Wextra

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_INC = $(LIBFT_PATH)/includes


CC_FLAGS = -Wall -Werror -Wextra

SRC_NAME =	main.c							\
			ft_check.c						\
			ft_tetrasplit.c					\
			ft_newtetri.c					\
			ft_chartolist.c					\
			ft_check_position.c				\
			ft_resol.c						\
			ft_makegrid.c					\
			ft_check_tetri.c				\
			ft_calcul_size_min.c

SRC_PATH =	src

INC_NAME = 	fillit.h

INC_PATH = includes

INCLUDES = -I $(LIBFT_INC) -I $(INC_PATH)

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))


all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@ printf "\033[1mCompilation du projet \033[34m$@\033[0m \033[1men \033[31m$@\033[0m ✅\n"
	 $(CC) $(CC_FLAGS) -o $@ $(OBJ) $(INCLUDES) $(FLAG_LIB)

libft: $(LIBFT)
$(LIBFT):
	@ make -C $(LIBFT_PATH)

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
	@ make -C $(LIBFT_PATH) fclean
	@ printf "\033[1mSuppression du binaire \033[31m%s\033[0m ✅\n" $(NAME)

re: fclean all
