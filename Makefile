###############################################################################
##                                                                           ##
##  This is a generalized makefiles made to be used on different kind        ##
##  of projects, such as making libraries , source files etc.                ##
##  Please note that to use this make files you need to posses the `.misc`   ##
##  directory that is included in the repo by default. This path is needed   ##
##  as some files used by make files are included there. Do change anything  ##
##  dependeing on your need.                                                 ##
##                                                                           ##
##  In the file `color` located in `.misc/make` you can find terminal escape ##
##  codes for colors arr or remove or eddid to get result as you want.       ##
##                                                                           ##
##                                                                           ##
##  In the file `path` located in `.misc/make` information about varius paths##
##  are included for to make this Makefile easier and to manage the make file##
##  More easily.                                                             ##
##                                                                           ##
###############################################################################


## Please do not remove the includes
## as they contain impoirtent information
## variables and rules

include .misc/make/color
include .misc/make/paths
include .misc/make/misc_var

## Te `.SILENT` launche evrything specified in
## silent mode so you dont have to put the `@`
.SILENT	: __START	NAME	clean fclean all re object library os_dep
.PHONY	: __START			clean fclean all re object library os_dep


## This is launched if no param given
.DEFAULT_GOAL = __START

## Project name (will be used)
PROJECT	=	COREWAR

## compiler related
CC		?=	clang 		## default compiler is clang

CC_FLAG ?=	-Werror \
			-Wall	\
			-Wextra


CC_FLAG_ASAN ?=	-Werror								\
				-Wall								\
				-Wextra								\
				-g -fsanitize=address				\
				-fno-omit-frame-pointer				\
				-fsanitize-address-use-after-scope	\

## some useful `flags` for memory verifications
##
## -O1 -g -fsanitize=address	\
	## -fno-omit-frame-pointer		\
	## -fsanitize-address-use-after-scope \


## binary, library etc...
MAIN	?=	main.c
NAME	?=	corewar 		## The name of your binary

COREWAR 		?=	corewar
P_COREWAR		?=	$(P_SRC)/core
COREWAR_MAIN	?=	corewar.c

ASM 			?=	asm
P_ASM			?=	$(P_SRC)/asm
ASM_MAIN		?=	asm.c

ifeq ($(MY_OS_NAME), Linux)
	NCURSES_ALERT ?= ""
	COREWAR_LINK	?=	 -lft -lftprintf -lncurses -lftprintferr
else
	#in 42 by default ncurses 5 is installed so we will use this specific link to uses ncurses 6 by brew
	NCURSES_ALERT ?= $(shell printf "$(WARN)[!][$(PROJECT)] USING ncurses from ~/.brew/opt/ncurses/[lib/|include] $(C_DEF)\n")
	COREWAR_LINK	?=	 -lft -lftprintf -lftprintferr  -L  ~/.brew/opt/ncurses/lib/ -lncurses -I ~/.brew/opt/ncurses/include/
endif


ASM		?=	asm

#The name of the library you want to make
LIB_A	?=	one.a

#All LIB_FT stufs
LIBFT		= $(P_LIB)/libft
LIBFT_INC	= $(LIBFT)/include
LIBFT_LIB	= $(LIBFT)/lib
LIBFT_A		= $(LIBFT_LIB)/libft.a
FT_PRINTF_A	= $(LIBFT_LIB)/libftprintf.a
FT_PRINTF_ERR_A	= $(LIBFT_LIB)/libftprintferr.a

SRC_ASM_NAME =	asm.c				\
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
	
SRC_ASM 	= $(addprefix $(P_ASM)/src/,$(SRC_ASM_NAME))


SRC_CORE	=	$(P_COREWAR)/$(COREWAR_MAIN)			\
				$(P_COREWAR)/get_arg/set_warr_file.c	\
				$(P_COREWAR)/get_arg/check_number.c		\
				$(P_COREWAR)/get_arg/get_dump.c			\
				$(P_COREWAR)/get_arg/get_n.c			\
				$(P_COREWAR)/get_arg/set_warr_nb.c		\
				$(P_COREWAR)/get_arg/read_data.c		\
				$(P_COREWAR)/get_arg/read_file.c		\
				$(P_COREWAR)/get_arg/get_arg.c			\
				$(P_COREWAR)/ft_atol.c					\
				$(P_COREWAR)/show_winner.c				\
				$(P_COREWAR)/inst_id.c					\
				$(P_COREWAR)/copy_register.c			\
				$(P_COREWAR)/get_param_size.c			\
				$(P_COREWAR)/param_type.c				\
				$(P_COREWAR)/set_pc.c					\
				$(P_COREWAR)/core_init.c				\
				$(P_COREWAR)/core_init2.c				\
				$(P_COREWAR)/bytes_to_int.c				\
				$(P_COREWAR)/int_to_bytes.c				\
				$(P_COREWAR)/load_warrior.c				\
				$(P_COREWAR)/shutdown_core.c			\
				$(P_COREWAR)/is_reg_regular.c			\
				$(P_COREWAR)/vproc_new.c				\
				$(P_COREWAR)/vproc_push.c				\
				$(P_COREWAR)/memory/write_mem.c			\
				$(P_COREWAR)/memory/tui_write_mem_spe.c	\
				$(P_COREWAR)/memory/tui_write_mem_nor.c	\
				$(P_COREWAR)/memory/tui_write_mem_tog.c	\
				$(P_COREWAR)/memory/read_mem.c			\
				$(P_COREWAR)/inst/inst_live.c			\
				$(P_COREWAR)/inst/inst_ld.c				\
				$(P_COREWAR)/inst/inst_st.c				\
				$(P_COREWAR)/inst/inst_add.c			\
				$(P_COREWAR)/inst/inst_sub.c			\
				$(P_COREWAR)/inst/inst_and.c			\
				$(P_COREWAR)/inst/inst_or.c				\
				$(P_COREWAR)/inst/inst_xor.c			\
				$(P_COREWAR)/inst/inst_zjmp.c			\
				$(P_COREWAR)/inst/inst_ldi.c			\
				$(P_COREWAR)/inst/inst_sti.c			\
				$(P_COREWAR)/inst/inst_fork.c			\
				$(P_COREWAR)/inst/inst_lld.c			\
				$(P_COREWAR)/inst/inst_lldi.c			\
				$(P_COREWAR)/inst/inst_lfork.c			\
				$(P_COREWAR)/inst/inst_aff.c			\
				$(P_COREWAR)/inst/inst_nop.c			\
				$(P_COREWAR)/inst/inst_load_mem.c		\
				$(P_COREWAR)/inst/inst_set_param.c		\
				$(P_COREWAR)/inst/inst_set_pc.c			\
				$(P_COREWAR)/tui/manage_mouse.c			\
				$(P_COREWAR)/tui/manage_input.c			\
				$(P_COREWAR)/tui/update_tui_cycle.c		\
				$(P_COREWAR)/tui/update_tui_cycle2.c	\
				$(P_COREWAR)/tui/set_exec_speed.c		\
				$(P_COREWAR)/tui/exec_next.c			\
				$(P_COREWAR)/tui/togle_exec_stat.c		\
				$(P_COREWAR)/tui/init_tui.c				\
				$(P_COREWAR)/tui/init_tui1.c			\
				$(P_COREWAR)/tui/init_tui2.c			\
				$(P_COREWAR)/tui/init_tui3.c			\
				$(P_COREWAR)/tui/init_tui_core.c		\
				$(P_COREWAR)/tui/init_tui_reg_af.c		\
				$(P_COREWAR)/tui/init_tui_reg_af_name.c	\
				$(P_COREWAR)/tui/init_tui_reg_bf.c		\
				$(P_COREWAR)/tui/init_tui_reg_bf_name.c	\
				$(P_COREWAR)/tui/init_tui_winbox.c		\
				$(P_COREWAR)/tui/clear_reg_val.c		\
				$(P_COREWAR)/tui/update_reg_val.c		\
				$(P_COREWAR)/tui/update_proc_list.c		\
				$(P_COREWAR)/tui/tui_add_list.c			\
				$(P_COREWAR)/exec/cycle_to_die_check.c      \
				$(P_COREWAR)/exec/delay.c                   \
				$(P_COREWAR)/exec/delete_proc.c             \
				$(P_COREWAR)/exec/dump_mem.c                \
				$(P_COREWAR)/exec/exec_vproc_q_tui.c        \
				$(P_COREWAR)/exec/exec_vproc_q.c            \
				$(P_COREWAR)/exec/exec_vproc.c              \
				$(P_COREWAR)/exec/init_vproc_q.c            \

## Objects without path names
OBJ		:=	$(notdir $(SRC:.c=.o))

## Objects with their path name
OBJ_P	=	$(addprefix $(P_OBJ)/,$(OBJ))	## addprefix add the
## path name to the files...



## Start making here
__START: all
	printf "$(OK)[+][$(PROJECT)] Done$(C_DEF)\n"

## For multiple Binarys
all : $(LIBFT_A) $(FT_PRINTF_A) $(COREWAR) $(ASM)
	# @make $(COREWAR) --no-print-directory
	# Put assembler here

$(COREWAR): $(LIBFT_A) $(FT_PRINTF_A) $(SRC_CORE) $(P_INCLUDE)/$(COREWAR).h $(P_INCLUDE)/tui.h $(FT_PRINTF_ERR_A)
	@$(CC) $(CC_FLAG) $(SRC_CORE) -I $(P_INCLUDE) -I $(LIBFT_INC) -L $(LIBFT_LIB) $(COREWAR_LINK)  -o $(COREWAR)
	@printf "$(OK)[+][$(PROJECT)] Made $(COREWAR)$(C_DEF)\n"

$(ASM): $(SRC_ASM) $(P_ASM)/inc/asm.h $(P_ASM)/inc/asm_struct.h  $(P_ASM)/inc/op.h
	@make -C $(P_ASM) BIN_PATH=$(P_ROOT) --no-print-directory
	@printf "$(OK)[+][$(PROJECT)] Made $(ASM)$(C_DEF)\n"

$(LIBFT_A):
	@make -C $(LIBFT) --no-print-directory

$(FT_PRINTF_A):
	@make -C $(LIBFT) ft_printf --no-print-directory

$(FT_PRINTF_ERR_A):
	@make -C $(LIBFT) ft_printf_err --no-print-directory

## Clean objects and others
clean:		$(OBJ_P)
	@make	-C $(LIBFT) clean --no-print-directory
	@make	-C $(P_ASM) BIN_PATH=$(P_ROOT) clean --no-print-directory
	@printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	@printf	"$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean
	@make	-C $(LIBFT) fclean BIN_PATH=$(P_ROOT) --no-print-directory
	@make	-C $(P_ASM) fclean BIN_PATH=$(P_ROOT) --no-print-directory
	@rm		-f $(COREWAR)
	@rm		-f $(ASM)
	@printf	"$(WARN)[!][$(PROJECT)] Removed all binary ./$(P_BIN)$(C_DEF)\n"
	@printf	"$(OK)[+][$(PROJECT)] Fully cleaned$(C_DEF)\n"

re:			fclean all

## This function creat object files from sources.
## It treates the string of large source names as
## individual names, when it creat objects it do
## not gives al the names in the same time to gcc
## but one by one.
object:		$(SRC) $(P_SRC) $(P_OBJ)
	$(foreach SOURCE, $(SRC), \
		$(CC) $(CC_FLAG) -I$(P_INCLUDE) -c $(SOURCE) -o $(P_OBJ)/$(notdir $(SOURCE:.c=.o))	&& \
		printf "$(OK)[+][$(PROJECT)] $(SOURCE)$(C_DEF)" && sleep $(SLEEP)	&& \
		printf "\r\033[K" \
		;)
	printf "$(OK)[+][$(PROJECT)] Objects are made in ./$(P_OBJ)$(C_DEF)\n"

## Make the actual library (archive)
library:	object $(P_OBJ) $(OBJ_P)
	printf "$(WARN)[!][$(PROJECT)] Creating archive $(LIB_A)$(C_DEF)\n"
	@ar rc $(LIB_A) $(OBJ_P)
	printf "$(WARN)[!][$(PROJECT)] Generating index in $(LIB_A)$(C_DEF)\n"
	@ranlib $(LIB_A)
	printf "$(OK)[+][$(PROJECT)] The $(LIB_A) library was made$(C_DEF)\n"



## This rule is called when a difference in operating sistem has been
## detected. You can put your prerequisite to be changed if a different
## os has been detected
os_dep: #put your prerequisite for os dependent stufs
	## put your os dependent comands here
	## this will be launched if the os name is
	## different then what read from the os file.
	## ex: make re
	printf "[$(PROJECT)] Os dependent stufs\n"

## Useful Makefile tricks
##
## ?= 			// let you put a default variable then later change it
## j<number>	// let you launche the number of job at the same time
## ifdef		// let you verify if used defined something or not
## .SILENT		// This parameter let you launch rules in silent mod
## .IGNORE		// Ignore parameter used as .SILENT
#
## --stop-on-faliur			// stop the program if error occures
## -k or --keep-going		// To keep ignoring all errors
## -i or --ignore-errors	// To Ignor error
## --no-print-directory		// This do not show the 'entered ... directory' warning
