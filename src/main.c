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

int				main(int argc, char **argv)
{
	t_vmka		*vmka;

	g_id_players = (int *)ft_memalloc(sizeof(int) * 4);
	g_count_bot = -1;
	init_vm(&vmka, -1);
	if (argc >= 2)
	{
		pars(argc, argv, &vmka, 0);
		init_field(&vmka, -1, -1);
		init_carriages(&vmka, -1);
	}
	else
	{
		ft_printf("Usage\n");
		exit(0);
	}
	for (int i = 0; i < g_count_bot + 1; i++)
	{
		ft_printf("Id: %d, Header: %x, Name: %s, Code-size: %d ",
			vmka->bot[i]->id_bot, vmka->bot[i]->header,
			vmka->bot[i]->name, vmka->bot[i]->code_size);
		ft_printf(", Comment: %s, Dump: %u, Nbr carriages: %d\n",
			vmka->bot[i]->comment, vmka->nbr_cycles, vmka->nbr_carr);
	}
	for (int j = 0; j < MEM_SIZE; j++)
	{
		ft_printf("%02x", vmka->field[j].place);
		if ((j + 1) % 64 != 0 || j == 0)
			ft_printf(" ");
		if ((j + 1) % 64 == 0 && j != 0)
			ft_printf("\n");
	}
	system("leaks -q corewar");
}
