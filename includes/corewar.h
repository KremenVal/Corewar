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
# include <stdbool.h>

/*
**	Структура игроков (скорее всего ещё дополнять нужно будет)
**	id_bot - порядковый номер игрока
**	header - хевер игрока
**	code_size - размер кода игрока в байтах
**	name - имя игрока
**	comment - комментарий игрока
**	code - выполняемый код игрока
*/

typedef struct			s_bot
{
	int					id_bot;
	int					header;
	int					code_size;
	char				*name;
	char				*comment;
	unsigned char		*code;
}						t_bot;

/*
**	Структура поля
**	place - размещение выполняемого кода игрока на поле
**	id_bot - порядковый номер игрока
*/

typedef struct			s_battlefield
{
	unsigned int		place;
	int					id_bot;
}						t_batfield;

/*
**	Структура кареток (скорее всего ещё дополнять нужно будет)
**	id_carr - порядковый номер каретки
**	carry - переменная, которая влияет на работу функции zjmp
**	poss_carr - текущая позиция каретки
**	last_live - цикл, в котором в последний раз была выполнена операция live
**	reg_carr - регист игрока с отрицательным знаком, на коде игрока на
**	котором стоит каретка
*/

typedef struct			s_carriages
{
	int					id_carr;
	bool				carry;
	int					poss_carr;
	int					last_live;
	int					reg_carr;
	int					iter_to_wait;
	unsigned long int	oper;
	struct s_carriages	*next;
}						t_carr;

/*
**	Структура виртуалки
**	t_bot - массив структур игроков
**	t_field - указатель на структуру арены
**	t_carr - указатель на структуру кареток
**	nbr_cycles - количество цыклов, посе которых прекратить
**	игру (если была задана)
**	nbr_carr - количество кареток
**	nbr_players - количество игроков
*/

typedef struct			s_vmka
{
	t_bot				**bot;
	t_batfield			*field;
	t_carr				*carr;
	unsigned long int	nbr_cycles;
	int					nbr_carr;
	int					nbr_players;
}						t_vmka;

/*
**	Структура операций
**	name - имя операции
**	code - порядковый номер аргумента
**	args_num - максимальное количество принимаемых аргументов
**	types - включает ли байткод код типа аргумента
**	args_types - типы аргументов
**	dir_size - размер T_DIR аргумента
*/

typedef struct			s_oper
{
	char				*name;
	unsigned int		code;
	unsigned int		args_num;
	bool				types;
	unsigned int		args_types[3];
	unsigned int		dir_size;
	int					wait;
}						t_oper;

/*
** g_id_players - Переменная для определения порядковых номеров игроков
** g_count_bot - Переменная подсчёта игроков
*/

int						*g_id_players;
int						g_count_bot;
t_oper					g_oper[16];

/*
** parsing_bot.c
*/

void					pars(int argc, char **argv, t_vmka **vmka, int i);
void					pars_flag_n(int argc, char **argv, t_vmka **vmka,
								int *i);
void					sort_bot(t_vmka **vmka, int step);

/*
** init.c
*/

void					init_vm(t_vmka **vmka, int i);
void					init_field(t_vmka **vmka, int i, int j);
void					init_carriages(t_vmka **vmka, int step);

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
int						return_bot_id(char *param);
void					get_id_bot(t_vmka **vmka, int step);
void					create_carriage(t_vmka **vmka, int nbr_carr, int poss);

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

/*
** start_fight.c
*/

void					start_fight(t_vmka **vmka);

/*
** helpfull_functions.c
*/

void					introducing(t_vmka **vmka, int id);
void					get_oper_code(t_carr *tmp, unsigned int place);

#endif
