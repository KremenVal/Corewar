/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:58:42 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/23 11:58:46 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
}

int			main(int argc, char **argv)
{
	t_vmka	*vmka;

	g_id_players = (int *)ft_memalloc(sizeof(int) * 4);
	g_count_bot = -1;
	init_vm(&vmka, -1);
	if (argc >= 2)
		pars(argc, argv, &vmka, 0);
	else
		ft_printf("Ne zaebis9\n");
	for (int i = 0; i < MAX_PLAYERS; ++i)
	{
		ft_printf("Id: %d, Header: %x, Name: %s, Code-size: %d ",
			(*vmka).bot[i]->id_bot, (*vmka).bot[i]->header,
			(*vmka).bot[i]->name, (*vmka).bot[i]->code_size);
		ft_printf(", Comment: %s, Dump: %u\n", (*vmka).bot[i]->comment,
			(*vmka).nbr_cycles);
	}
	system("leaks -q corewar");
}
