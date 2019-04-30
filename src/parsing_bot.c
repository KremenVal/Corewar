/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 13:59:42 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/30 13:59:44 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Парсинг флага -n
*/

void		pars_flag_n(int argc, char **argv, t_vmka **vmka, int *i)
{
	if ((*i) + 2 >= argc || !ft_strstr(argv[(*i) + 2], ".cor"))
		error_management("ERROR: invalid params!\n");
	g_count_bot++;
	if (g_count_bot > MAX_PLAYERS - 1)
		error_management("ERROR: too much players!\n");
	(*vmka)->bot[g_count_bot]->id_bot = return_bot_id(argv[(*i) + 1]);
	(*i) += 2;
	add_bot_to_battle(argv[(*i)], &(*vmka)->bot[g_count_bot]);
}

/*
**	Парсинг параметров заданых пользователем
*/

void		pars(int argc, char **argv, t_vmka **vmka, int i)
{
	while (++i < argc)
	{
		if (!ft_strcmp(argv[i], "-dump"))
		{
			if (i + 1 >= argc || (*vmka)->nbr_cycles > 0 ||
				ft_atoi(argv[i + 1]) < 0)
				error_management("ERROR: invalid number of cycles!\n");
			(*vmka)->nbr_cycles = ft_atoi(argv[i + 1]);
			i += 1;
		}
		else if (!ft_strcmp(argv[i], "-n"))
			pars_flag_n(argc, argv, vmka, &i);
		else if (ft_strstr(argv[i], ".cor"))
		{
			g_count_bot++;
			if (g_count_bot > MAX_PLAYERS - 1)
				error_management("ERROR: too much players!\n");
			add_bot_to_battle(argv[i], &(*vmka)->bot[g_count_bot]);
		}
		else
			error_management("ERROR: unknown type of data!\n");
	}
	get_id_bot(vmka, -1);
	sort_bot(vmka, -1);
}

/*
**	Сортировка игроков по возрастанию их порядковых номеров
*/

void		sort_bot(t_vmka **vmka, int step)
{
	t_bot	*tmp;

	while (++step < g_count_bot)
	{
		if ((*vmka)->bot[step]->id_bot > (*vmka)->bot[step + 1]->id_bot)
		{
			tmp = (*vmka)->bot[step];
			(*vmka)->bot[step] = (*vmka)->bot[step + 1];
			(*vmka)->bot[step + 1] = tmp;
			step = -1;
		}
	}
	(*vmka)->nbr_carr = g_count_bot + 1;
	(*vmka)->nbr_players = g_count_bot + 1;
}
