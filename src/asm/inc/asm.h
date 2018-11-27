/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:55:01 by snassour          #+#    #+#             */
/*   Updated: 2018/10/04 01:55:05 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <asm_struct.h>
# include <stdlib.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <op.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# define MFAIL 2
# define LABEL_SET 1
# define LABEL_NOTSET 0
# define NO_FILE 100
# define TOO_MANY_FILES 200
# define WRONG_EXTENSION 300
# define FILE_NO_OPEN 400
# define ERR_CREATE_FILE 450
# define FILE_NO_INSTR 460
# define CHAMPION_NAME_ERROR 500
# define COMMENT_ERROR 600
# define UNKNOWN_FUNCTION 700
# define INVALID_ARGUMENT 40
# define INVALID_ARG_NUM 50
# define INV_TYPE_R 10
# define INV_TYPE_D 11
# define INV_TYPE_I 12
# define INV_TYPE_RD 21
# define INV_TYPE_RI 22
# define INV_TYPE_DI 23
# define INV_TYPE_RDI 33
# define INVALID_LABEL 900
# define UNDEFINED_LABEL 910
# define NO_NEW_LINE 920
# define YES 1
# define NO 0
# define NO_LABEL_NAME 1000

/*
**	on a les combinaisons suivantes :
**	REGISTRE ;
**	DIRECT ;
**	INDIRECT
**	REGISTRE DIRECT ;
**	REGISTRE INDIRECT ;
**	REGISTRE DIRECT INDIRECT ;
**	DIRECT INDIRECT ;
*/

typedef struct s_op		t_op;
typedef struct s_lbl	t_lbl;
typedef struct s_clst	t_clst;
typedef struct s_asm	t_asm;

int		asm_verify_entry(int ac, char **av, int i);
void	asm_get_optab(t_asm *data);

int		asm_verify_format(t_asm *data);
t_asm	*asm_init_data();
int		asm_destroy_data(t_asm **data);
int		asm_instruction(char *line, t_asm *data);
int		asm_parse_file(t_asm *data);
char	*asm_removecomment(char *line);

int		asm_checkvalidlabel(char *line);
int		asm_checkcmd(char *line, int begin, t_asm *data);
int		asm_checklabel(char *line, char *label, t_asm *data);
int		asm_check_new_line(char *nc, t_asm *data);

int		asm_checkargument(char *s, int begin, t_asm *data, int conv);
int		asm_checkreg(char *line, int begin, int nb_arg, t_asm *data);
int		asm_checkind(char *line, int begin, t_asm *data, int nb_arg);
int		asm_checkdir(char *line, int begin, t_asm *data, int nb_arg);
int		asm_addclist(t_asm *data, char *line, int begin, int conv);

void	asm_write_color(char *color, int len, int output);

int		asm_parse_file_error(t_asm *data, char **line, char **nc);

void	asm_exit_success(t_asm *data);

void	asm_error(int toto, char *str, t_asm *data);
void	asm_error_format_line(int format, t_asm *data);
void	asm_error_format_name_comment(int format);
void	asm_gcc_format_error(char *str);
int		asm_max(int a, int b);
int		asm_blank(char *line, int begin);
void	toggle_endianess(int *n);
int		asm_bigendian(int number, int size);
void	asm_dellabel(t_asm *data);
void	asm_reinit_data(t_asm **data);

void	asm_set_corlist(t_asm *data, t_clst **new);
void	asm_destroy_corlist(t_asm *data);
int		asm_create_corlist(t_asm *data);

int		asm_replace_labels(t_asm *data);
int		asm_check_label_used(t_asm *data);
int		asm_set_lablist(t_asm *data, char *s, int error);
int		asm_lablist(t_asm *data, char *s);
void	asm_destroy_lablist(t_asm *data);

void	asm_error_format_argument_type(int err, t_asm *data);
void	asm_error_format_argument(int err, t_asm *data);

void	asm_write_corfile(t_asm *data, int fd, int j);
int		asm_generate_corfile(t_asm *data, int i);

int		asm_search_end_comment(t_asm *data);
int		asm_check_comment_name(t_asm *data, char buf[1], int type);
int		asm_error_header(t_asm *d, int nb_char, int empty, int r);
int		asm_extend1_header(t_asm *d, char **str, char *buf, int *i);
int		asm_extend2_header(t_asm *d, char **str, int *i);

int		asm_strdel(char **str);
int		asm_set_name_comment(t_asm *d, int j, int l, int type);
int		asm_realloc(t_asm *d, char **str, int size);
int		asm_get_name_comment(t_asm *d, int r[4], int type);
int		asm_search_name_comment(t_asm *d, int type);

int		asm_parse_file_error(t_asm *data, char **line, char **nc);
int		asm_close_error(t_asm *data);
int		asm_extend3_header(t_asm *d, char **str, int var[5]);
int		asm_extend4_header(t_asm *d, char **str, int var[5]);
int		asm_header_2(t_asm *d);

#endif
