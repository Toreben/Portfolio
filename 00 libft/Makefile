# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bnoyer <bnoyer@le-101.fr>                  +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/22 21:16:56 by bnoyer       #+#   ##    ##    #+#        #
#    Updated: 2018/08/14 15:08:03 by bnoyer      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all, re, clean, fclean

NAME = libft.a

SRC_NAME = 	ft_memset.c				\
			ft_memcpy.c				\
			ft_memccpy.c			\
			ft_memmove.c			\
			ft_memchr.c				\
			ft_memalloc.c			\
			ft_memdel.c				\
			ft_bzero.c				\
									\
			ft_strclr.c				\
			ft_striter.c			\
			ft_striteri.c			\
									\
			ft_lower.c				\
			ft_upper.c				\
									\
			ft_putchar.c			\
			ft_putstr.c				\
			ft_putendl.c			\
			ft_putnbr.c				\
			ft_putchar_fd.c			\
			ft_putstr_fd.c			\
			ft_putendl_fd.c			\
			ft_putnbr_fd.c			\
									\
			ft_strlcat.c			\
			ft_strlen.c				\
			ft_strstrlen.c			\
									\
			ft_strcmp.c				\
			ft_strncmp.c			\
			ft_strequ.c				\
			ft_strnequ.c			\
									\
			ft_str_is_alpha.c		\
			ft_str_is_lowercase.c	\
			ft_str_is_uppercase.c	\
			ft_str_is_number.c		\
			ft_str_is_float.c		\
			ft_islower.c			\
			ft_isupper.c			\
			ft_isalpha.c			\
			ft_isdigit.c			\
			ft_isalnum.c			\
			ft_isascii.c			\
			ft_isprint.c			\
			ft_isspace.c			\
			ft_toupper.c			\
			ft_tolower.c			\
			ft_memcmp.c				\
			ft_atoi.c				\
			gnl.c					\
									\
			ft_lstdelone.c			\
			ft_lstdel.c				\
			ft_lstadd.c				\
			ft_lstiter.c			\
			ft_lstnew.c				\
			ft_lstmap.c				\
									\
			ft_itoa.c				\
			ft_strcat.c				\
			ft_strchr.c				\
			ft_strcpy.c				\
			ft_strdel.c				\
			ft_strdup.c				\
			ft_strjoin.c			\
			ft_strmap.c				\
			ft_strmapi.c			\
			ft_strmerge.c			\
			ft_strncat.c			\
			ft_strncpy.c			\
			ft_strnew.c				\
			ft_strnstr.c			\
			ft_strrchr.c			\
			ft_strstr.c				\
			ft_strsub.c				\
			ft_strtrim.c			\
			ft_strsplit.c			\
									\
			ft_atof.c				\
			ft_pow.c				\
			ft_atoi16.c				\
			ft_brackets.c
SRC_PATH = src

INC_NAME = libft.h
INC_PATH = includes
INCLUDES = -I$(LIBFT_PATH)

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

all: $(NAME)
	@ echo "\033[1mCompilation de la libft reussie\033[0m"

$(NAME): $(OBJ)
	@ ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC)
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@ $(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@ /bin/rm -rf $(OBJ_PATH)
	@ printf "\033[1mSuppression des objets \033[31m%s\033[0m ✅\n" $(OBJ_PATH)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ printf "\033[1mSuppression du binaire \033[31m%s\033[0m ✅\n" $(NAME)

re: fclean all
