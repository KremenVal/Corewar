/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something_useful.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:41:52 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/25 11:41:54 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Вывода ошибок и прекращения работы программы
*/

void			error_management(char *error)
{
	ft_printf("%s", error);
	exit(0);
}

/*
**	Перевод битов в обратном порядке
*/

void			reverse_bits(void *b, int len)
{
	int			step;
	char		*tmptmp;
	char		tmp;

	step = -1;
	tmptmp = (char *)b;
	while (++step < len / 2)
	{
		tmp = tmptmp[step];
		tmptmp[step] = tmptmp[len - step - 1];
		tmptmp[len - step - 1] = tmp;
	}
}

/*
**	Возвращения порядкового номера игрока, если номер был явно указан
*/

int				return_bot_id(char *param)
{
	int			res;
	int			step;

	step = -1;
	while (param[++step])
		if (!ft_isdigit(param[step]))
			error_management("ERROR: invalid params for id player!\n");
	if (step > 2147483647)
		error_management("ERROR: invalid params  for id player!\n");
	res = ft_atoi(param);
	if (res < 1 || res > MAX_PLAYERS || (res == g_id_players[0] ||
		res == g_id_players[1] || res == g_id_players[2] ||
		res == g_id_players[3]))
		error_management("ERROR: invalid params  for id player!\n");
	g_id_players[res - 1] = res;
	return (res);
}

/*
**	Присвоение игрокам порядковых номеров
*/

void			get_id_bot(t_vmka **vmka, int step)
{
	while (++step < MAX_PLAYERS)
	{
		if (!(*vmka)->bot[step]->id_bot && !g_id_players[0])
		{
			(*vmka)->bot[step]->id_bot = 1;
			g_id_players[0] = 1;
		}
		else if (!(*vmka)->bot[step]->id_bot && !g_id_players[1])
		{
			(*vmka)->bot[step]->id_bot = 2;
			g_id_players[1] = 2;
		}
		else if (!(*vmka)->bot[step]->id_bot && !g_id_players[2])
		{
			(*vmka)->bot[step]->id_bot = 3;
			g_id_players[2] = 3;
		}
		else if (!(*vmka)->bot[step]->id_bot && !g_id_players[3])
		{
			(*vmka)->bot[step]->id_bot = 4;
			g_id_players[3] = 4;
		}
	}
}

/*
**	Создание новых кареток
*/

void			create_carriage(t_vmka **vmka, int nbr_carr, int poss)
{
	t_carr		*new;

	new = (t_carr *)ft_memalloc(sizeof(t_carr));
	new->id_carr = nbr_carr;
	new->poss_carr = poss;
	new->reg_carr = nbr_carr * -1;
	if (!(*vmka)->carr)
		(*vmka)->carr = new;
	else
	{
		new->next = (*vmka)->carr;
		(*vmka)->carr = new;
	}
}
