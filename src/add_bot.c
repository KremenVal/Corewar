/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:33:08 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/25 11:33:10 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Проверка названия файла
*/

void				check_file_name(char *bot_file)
{
	if (bot_file[0] == '\0' || !ft_strcmp(bot_file, ".cor"))
		error_management("ERROR: incorrect champion name!\n");
	if (ft_strcmp(ft_strrchr(bot_file, '.'), ".cor"))
		error_management("ERROR: invalid file extension!\n");
}

/*
**	Проверка на открытие и считывание файла игрока и получение его данных
*/

void				check_bot_size(char *bot_file, t_bot **bot)
{
	int				fd;
	int				num;
	unsigned char	bot_code[4500];

	num = -1;
	if ((fd = open(bot_file, O_RDONLY)) < 0)
		error_management("ERROR: this file doesn't exist!\n");
	if ((num = read(fd, &bot_code, MAX_BOT_SIZE)) < 0)
		error_management("ERROR: unable to read file!\n");
	if (num < MIN_BOT_SIZE || num > MAX_BOT_SIZE)
		error_management("ERROR: wrong champion size!\n");
	close(fd);
	check_magic_header(bot_code, bot);
	check_bot_name(&bot_code[4], bot, -1);
	check_bot_size_code(&bot_code[4 + PROG_NAME_LENGTH + 4], bot);
	check_bot_comment(&bot_code[4 + PROG_NAME_LENGTH + 4 + 4], bot, -1);
	check_bot_code(&bot_code[MIN_BOT_SIZE], bot, num, bot_code);
}

/*
**	Добавление игрока в массив структур игроков
*/

void				add_bot_to_battle(char *bot_file, t_bot **bot)
{
	check_file_name(bot_file);
	check_bot_size(bot_file, bot);
}
