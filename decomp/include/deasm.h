/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deasm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrian <cbrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 16:03:43 by cbrian            #+#    #+#             */
/*   Updated: 2018/10/24 11:16:18 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEASM_H
# define DEASM_H

# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/stat.h>
# include <limits.h>
# include <errno.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_printf_err.h"

# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

# define REGISTER 1
# define DIRECT 2
# define INDIRECT 3
# define BUFF_SIZE 4000

# define FLAG_V 0b00000001
# define FLAG_I 0b00000010

int		check_arg(int argc, char **argv, int *opt, int *k);
int		check_instruction(uint8_t buffer[BUFF_SIZE], int tab_fd[3], char *argv,
																	char *cor);
int		check_magic(uint8_t buffer[BUFF_SIZE]);
int		opc(uint8_t *nb, uint8_t tab[3]);
void	created_file(char *argv, char **cor);
void	ft_printc(int fd, char *str, ...);
int		is_direct_char(int inst, int param_n);
void	w_name(uint8_t buffer[BUFF_SIZE], int fd);
void	w_comment(uint8_t buffer[BUFF_SIZE], int fd);
int		w_instructions(uint8_t buffer[BUFF_SIZE], int fd, int opt, char *argv);
int		w_direct(uint8_t buffer[BUFF_SIZE], int *i);
int		w_indirect(uint8_t buffer[BUFF_SIZE], int *i);
void	w_arg(uint8_t tab[3], int nb[4], uint8_t buffer[BUFF_SIZE], int fd);
void	init_tab(const char *tab[16]);

#endif
