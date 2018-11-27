#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snassour <snassour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/03 19:15:09 by snassour          #+#    #+#              #
#    Updated: 2018/10/24 07:00:05 by suddin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = clang
CFLAGS = 	-Wall -Wextra -Werror	\
			 #-g						\
			 #-fno-omit-frame-pointer\
 			 #-fsanitize=address 	\
			 #-fsanitize-address-use-after-scope 


SRC_PATH = ./src/
OBJ_PATH = ./obj/
SRC_NAME =	asm.c					\
			data.c					\
			op.c					\
			parse.c					\
			parse_cmd.c				\
			check_arguments.c		\
			asm_write_color.c		\
			asm_error.c				\
			asm_tools.c				\
			asm_checklabel.c		\
			corewar_list.c			\
			asm_labels.c			\
			asm_argument_error.c	\
			asm_create_corfile.c	\
			parse1.c				\
			parse2.c				\
			parse3.c

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_PATH =	./inc/					\
			./libft/includes/

INC_FILES =	./inc/asm.h 			\
			./inc/op.h				\
			./inc/asm_struct.h

BIN_PATH ?= .
NAME = asm


LIB = -L./libft -lft
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

all: lib $(NAME)

lib:
	@make -C ./libft  --no-print-directory

$(NAME):$(OBJ) $(INC_FILES)
#	$(CC) $(CFLAGS) $(OBJ) $(INC) -o $(NAME)
	@$(CC) $(OBJ) $(LIB) $(CFLAGS) -o $(BIN_PATH)/$(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c $(INC_FILES)
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $< $(CFLAGS) $(INC) -o $@

clean:
	@rm -rfv $(OBJ_PATH)
	@make clean -C ./libft   --no-print-directory

fclean:clean
	@rm -fv $(NAME)
	@make fclean -C ./libft  --no-print-directory

re:fclean all
