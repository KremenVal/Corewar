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

void			error_management(char *error)
{
	ft_printf("%s", error);
	exit(0);
}

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

int				return_bot_id(char *param)
{
	int			res;
	int			step;

	step = -1;
	while (param[++step])
		if (!ft_isdigit(param[step]))
			error_management("ERROR: invalid params!\n");
	if (step > 2147483647)
		error_management("ERROR: invalid params!\n");
	res = ft_atoi(param);
	if (res < 1 || res > MAX_PLAYERS || (res == g_id_players[0] ||
		res == g_id_players[1] || res == g_id_players[2] ||
		res == g_id_players[3]))
		error_management("ERROR: invalid params!\n");
	g_id_players[res - 1] = res;
	g_id++;
	return (res);
}

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
