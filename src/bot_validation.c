/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:56:02 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/26 10:56:03 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Проверка на соответствие магического хедера игрока с COREWAR_EXEC_MAGIC
*/

void				check_magic_header(unsigned char *bot_code, t_bot **bot)
{
	int				bot_header;

	ft_memcpy(&bot_header, bot_code, 4);
	reverse_bits(&bot_header, 4);
	if (bot_header != COREWAR_EXEC_MAGIC)
		error_management("ERROR: champion magic header is wrong!\n");
	else
		(*bot)->header = bot_header;
}

/*
**	Запись имени игрока
*/

void				check_bot_name(unsigned char *bot_code, t_bot **bot,
									int step)
{
	while (++step < PROG_NAME_LENGTH && bot_code[step])
		(*bot)->name[step] = bot_code[step];
}

/*
**	Проверка на размер кода игрока с CHAMP_MAX_SIZE
*/

void				check_bot_size_code(unsigned char *bot_code, t_bot **bot)
{
	ft_memcpy(&(*bot)->code_size, bot_code, 4);
	reverse_bits(&(*bot)->code_size, 4);
	if ((*bot)->code_size < 0 || (*bot)->code_size > CHAMP_MAX_SIZE)
		error_management("ERROR: invalid champion code size!\n");
}

/*
**	Запись комментария игрока
*/

void				check_bot_comment(unsigned char *bot_code, t_bot **bot,
									int step)
{
	while (++step < COMMENT_LENGTH && bot_code[step])
		(*bot)->comment[step] = bot_code[step];
}

/*
**	Запись исполняемого кода игрока
*/

void				check_bot_code(unsigned char *bot_code, t_bot **bot,
									int num, unsigned char *bot_start)
{
	int				step;

	step = -1;
	while (++step < (*bot)->code_size && step < num)
		(*bot)->code[step] = bot_code[step];
	if (&bot_code[step] - bot_start != num)
		error_management("ERROR: wrong size of code!\n");
}
