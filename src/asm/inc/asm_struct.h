/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snassour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:55:01 by snassour          #+#    #+#             */
/*   Updated: 2018/10/04 01:55:05 by snassour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_STRUCT_H
# define ASM_STRUCT_H
# include <stdlib.h>
# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include <op.h>
# include <stdint.h>
# include <stdio.h>
# include <asm.h>

/*
**	struct	s_op
**	{
**		const char		*cmd;
**		uint8_t			n_arg;
**		uint32_t		*arg;
**		uint8_t			opc;
**		uint16_t		cycles;
**		const char		*desc;
**		uint8_t			ocp;
**		uint8_t			jane_doe;
**	};
**
**	typedef struct s_op t_op;
**
**	nom, nb_args, types d'args, opcode, cycles, explication nom,
**	presence de l'OCP - 1 == oui et 0 == non,
*/

struct	s_op
{
	const char		*cmd;
	uint8_t			n_arg;
	uint32_t		arg[3];
	uint8_t			opc;
	uint16_t		cycles;
	const char		*desc;
	uint8_t			ocp;
	uint8_t			index;
	uint8_t			len;
};

struct	s_clst
{
	int				opcode;
	int				ocparam;
	int				nb_arg;
	int				arg[3];
	int				arg_type[3];
	int				arg_len[3];
	int				pc;
	int				nb_bytes;
	char			*labels[3];
	int				label_in_arg[3];
	struct s_clst	*next;
};

struct	s_lbl
{
	char			*name;
	int				pc;
	int				set_label;
	int				line_label;
	struct s_lbl	*next;
};

/*
**	file descriptor
**	current line
**	not used yet
**	file name
**	cor file name
**	not used yet
**	not used yet
**	tab with all the operations
**	indicator of name encounter
**	indicator of comment encounter
**	name length
**	comment length
**	line that contains an error
**	not used yet
**	type of error
**	not used yet
**	not used yet
**	current instruction found
**	calculated ocp
**	number of arguments
**	arguments value
**	types of arguments 1 == reg, 2 == dir, 3 == ind
**	which arg has a label
**	label names in arg
*/

struct	s_asm
{
	int				fd;
	char			*str;
	char			*dot_s_name;
	char			*dot_cor_name;
	t_header		*header;
	struct s_op		op_tab[17];
	int				name;
	int				comment;
	int				lname;
	int				lcom;
	int				line_error;
	int				error_type;
	int				cmd;
	int				nb_arg;
	int				curr_arg;
	int				arg[3];
	int				arg_len[3];
	int				arg_type[3];
	int				label_in_arg[3];
	char			*labels[3];
	struct s_clst	*begin;
	struct s_lbl	*lablist;
	int				pc;
	int				pc_label;
	int				set_label;
	int				get_label;
	int				new_line;
};

#endif
