/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:39:09 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/23 12:39:12 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# define MIN_BOT_SIZE (4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4)
# define MAX_BOT_SIZE (MIN_BOT_SIZE + CHAMP_MAX_SIZE)

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <stdint.h>

typedef struct			s_bot
{
	int					id_bot;
	int					header;
	int					code_size;
	char				*name;
	char				*comment;
	unsigned char		*code;
}						t_bot;

typedef struct			s_vmka
{
	t_bot				**bot;
}						t_vmka;

/*
** main.c
*/

void					pars(int argc, char **argv, t_vmka **vmka);

/*
** init_vm.c
*/

void					init_vm(t_vmka **vmka);

/*
** add_bot.c
*/

void					add_bot_to_battle(char *bot_file, t_bot **bot);
void					check_file_name(char *bot_file);
void					check_bot_size(char *bot_file, t_bot **bot);

/*
** something_useful.c
*/

void					error_management(char *error);
void					reverse_bits(void *b, int len);

/*
** bot_validation.c
*/

void					check_magic_header(unsigned char *bot_code,
								t_bot **bot);
void					check_bot_name(unsigned char *bot_code, t_bot **bot,
								int step);
void					check_bot_size_code(unsigned char *bot_code,
								t_bot **bot);
void					check_bot_comment(unsigned char *bot_code,
								t_bot **bot, int step);
void					check_bot_code(unsigned char *bot_code,
								t_bot **bot, int num, unsigned char *bot_start);

#endif
