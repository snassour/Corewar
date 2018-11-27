# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/04 15:40:33 by cbrian            #+#    #+#              #
#    Updated: 2018/10/24 12:22:22 by suddin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = 	get_arg.c check_arg.c w_name.c w_comment.c w_instructions.c\
			w_direct.c w_indirect.c w_arg.c opc.c created_file.c ft_printc.c\
			is_direct_char.c check_instruction.c check_magic.c init_tab.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = src
OBJ_PATH = obj

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

LIBFT = libft
LIBFT_LIB		= $(LIBFT)/lib
LIBFT_INC		= $(LIBFT)/include
LIBFT_A			= $(LIBFT_LIB)/libft.a
FT_PRINTF_A		= $(LIBFT_LIB)/libftprintf.a
FT_PRINTF_ERR_A	= $(LIBFT_LIB)/libftprintferr.a


NAME = deasm

#FLAGS
CPPFLAGS = -I include -I libft/include
CFLAGS = -Wall -Werror -Wextra\
		# -fsanitize=address

#COMPILER
CC = clang

#RULES
all:  $(NAME)

$(NAME): $(LIBFT_A) $(FT_PRINTF_A) $(FT_PRINTF_ERR_A) $(OBJ) include/deasm.h
	 $(CC) $(OBJ) $(CFLAGS) -I include -I $(LIBFT_INC) -L $(LIBFT_LIB) -lft -lftprintf -lftprintferr  -o $(NAME)
	@ echo "\033[32m[$(NAME)] compilation done\033[0m"
	@ echo "\033[32m[$(NAME)] executable created\033[0m"

$(LIBFT_A):
	@make -C $(LIBFT)

$(FT_PRINTF_A):
	@make -C $(LIBFT) ft_printf

$(FT_PRINTF_ERR_A):
	@make -C $(LIBFT) ft_printf_err

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@ mkdir $(OBJ_PATH) 2> /dev/null || true
	@#@$(CC) -c $< $(CFLAGS)  -I include -I $(LIBFT_INC) -L $(LIBFT_LIB) -lft -lftprintf -lftprintferr -o $@
	@$(CC) -c $< $(CFLAGS)  -I include -I $(LIBFT_INC) -o $@

clean:
	@ rm -f $(OBJ)
	@make -C ./libft clean
	@ rmdir $(OBJ_PATH) 2>/dev/null || true

fclean: clean
	@ rm -f $(NAME)
	@make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
