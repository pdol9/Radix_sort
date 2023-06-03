# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdolinar <pdolinar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 17:12:33 by pdolinar          #+#    #+#              #
#    Updated: 2023/06/02 21:01:53 by pdolinar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap
INC			:=	include
LIBFT_DIR	:=	libft
LIBFT		:=	$(LIBFT_DIR)/libft.a
HEADER		:=	$(INC)/push_swap.h
HEADER_L	:=	$(LIBFT_DIR)/$(INC)/libft.h
INC_L		:=	$(LIBFT_DIR)/include

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -g
RM			:=	rm -rf

CLEAR := \033[0m
PR := \033[1;35m
GR := \033[1;32m

SRC_DIR		:=	src/
OBJ_DIR		:=	build/

SRC			:=	main.c \
				sorting.c \
				parsing.c \
				operations.c \
				utils_pushswap.c \
				utils.c \
				utils_2.c

OBJ = $(addprefix $(OBJ_DIR),$(notdir $(SRC:.c=.o)))

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GR)>> compiling ...							\n \
        ___  _  _ ____ _  _     ____ _ _ _ ____ ___			\n \
        |__] |  | [__  |__|     [__  | | | |__| |__]         \n \
___ ___ |    |__| ___] |  | ___ ___] |_|_| |  | |    ___ ___ \n \
                                                             $(REV)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADER) $(HEADER_L)
	@$(CC) $(CFLAGS) -I $(INC) -I $(INC_L) -c $< -o $@

$(LIBFT):
	@$(MAKE) all -s -C $(LIBFT_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	$(MAKE) fclean -s -C $(LIBFT_DIR)
	@echo "$(PR)All object files deleted$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(PR)$(NAME) deleted$(CLEAR)"

norm:
	norminette $(SRC_DIR) $(INC)

re:	fclean all

.PHONY: all clean fclean re norm
