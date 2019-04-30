/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:13:44 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/30 14:13:47 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Инициализация общей структуры
*/

void		init_vm(t_vmka **vmka, int i)
{
	(*vmka) = (t_vmka *)ft_memalloc(sizeof(t_vmka));
	(*vmka)->bot = (t_bot **)ft_memalloc(sizeof(t_bot *) * MAX_PLAYERS);
	(*vmka)->field = (t_batfield *)ft_memalloc(sizeof(t_batfield) * MEM_SIZE);
	while (++i < MAX_PLAYERS)
	{
		(*vmka)->bot[i] = (t_bot *)ft_memalloc(sizeof(t_bot));
		(*vmka)->bot[i]->name = (char *)ft_memalloc(sizeof(char)
			* PROG_NAME_LENGTH + 1);
		ft_bzero((*vmka)->bot[i]->name, PROG_NAME_LENGTH + 1);
		(*vmka)->bot[i]->comment = (char *)ft_memalloc(sizeof(char)
			* COMMENT_LENGTH + 1);
		ft_bzero((*vmka)->bot[i]->comment, COMMENT_LENGTH + 1);
		(*vmka)->bot[i]->code = (unsigned char *)ft_memalloc(
			sizeof(unsigned char) * CHAMP_MAX_SIZE + 1);
		ft_bzero((*vmka)->bot[i]->comment, CHAMP_MAX_SIZE + 1);
	}
}

/*
**	Инициализация арены
*/

void		init_field(t_vmka **vmka, int i, int j)
{
	int		place;

	place = MEM_SIZE / (*vmka)->nbr_players;
	while (++i < (*vmka)->nbr_players)
	{
		j = -1;
		while (++j < (*vmka)->bot[i]->code_size)
		{
			(*vmka)->field[i * place + j].id_bot = (*vmka)->bot[i]->id_bot;
			(*vmka)->field[i * place + j].place = (*vmka)->bot[i]->code[j];
		}
	}
}

/*
**	Инициализация кареток
*/

void		init_carriages(t_vmka **vmka, int step)
{
	create_carriage(vmka, 1, 0);
	while (++step < (*vmka)->nbr_players)
		create_carriage(vmka, step + 1,
			step * (MEM_SIZE / (*vmka)->nbr_players));
}
