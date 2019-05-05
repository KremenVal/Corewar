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
	(*vmka)->carr = NULL;
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
	while (++step < (*vmka)->nbr_players)
		create_carriage(vmka, (*vmka)->bot[step]->id_bot,
			step * (MEM_SIZE / (*vmka)->nbr_players));
}

t_oper		g_oper[16] = {
	{
		.name = "live",
		.code = 0x01,
		.args_num = 1,
		.types = 0,
		.args_types = {T_DIR | 0 | 0},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "ld",
		.code = 0x02,
		.args_num = 2,
		.types = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.wait = 5
	},
	{
		.name = "st",
		.code = 0x03,
		.args_num = 2,
		.types = 1,
		.args_types = {T_REG, T_REG | T_IND, 0},
		.dir_size = 4,
		.wait = 5
	},
	{
		.name = "add",
		.code = 0x04,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "sub",
		.code = 0x05,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG, T_REG, T_REG},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "and",
		.code = 0x06,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "or",
		.code = 0x07,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "xor",
		.code = 0x08,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		.dir_size = 4,
		.wait = 6
	},
	{
		.name = "zjmp",
		.code = 0x09,
		.args_num = 1,
		.types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 20
	},
	{
		.name = "ldi",
		.code = 0x0A,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.wait = 25
	},
	{
		.name = "sti",
		.code = 0x0B,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		.dir_size = 2,
		.wait = 25
	},
	{
		.name = "fork",
		.code = 0x0C,
		.args_num = 1,
		.types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 800
	},
	{
		.name = "lld",
		.code = 0x0D,
		.args_num = 2,
		.types = 1,
		.args_types = {T_DIR | T_IND, T_REG, 0},
		.dir_size = 4,
		.wait = 10
	},
	{
		.name = "lldi",
		.code = 0x0E,
		.args_num = 3,
		.types = 1,
		.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		.dir_size = 2,
		.wait = 50
	},
	{
		.name = "lfork",
		.code = 0x0F,
		.args_num = 1,
		.types = 0,
		.args_types = {T_DIR, 0, 0},
		.dir_size = 2,
		.wait = 1000
	},
	{
		.name = "aff",
		.code = 0x10,
		.args_num = 1,
		.types = 1,
		.args_types = {T_REG, 0, 0},
		.dir_size = 4,
		.wait = 2
	}
};

static void		(*g_op[16])() = {&live_op, &ld_op, &st_op, &add_sub_op,
	&add_sub_op, &and_or_xor_op, &and_or_xor_op, &and_or_xor_op, &zjmp_op,
	&ldi_op, &sti_op, &fork_op, &ld_op, &ldi_op, &fork_op, &aff_op};
