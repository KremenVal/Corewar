/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:58:42 by vkremen           #+#    #+#             */
/*   Updated: 2019/05/09 01:24:52 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		introducing(t_vmka **vmka, int id)
{
	ft_printf("Introducing contestants...\n");
	while (++id < (*vmka)->nbr_players)
	{
		ft_printf("\033[0;3%dm* Player %d, weighing %d bytes, \"%s\" ",
			id + 1, id + 1, (*vmka)->bot[id]->code_size,
			(*vmka)->bot[id]->name);
		ft_printf("(\"%s\") !\n\033[0m", (*vmka)->bot[id]->comment);
	}
}

int				main(int argc, char **argv)
{
	t_vmka		*vmka;

	if (argc < 2)
	{
		ft_printf("Usage\n");
		exit(0);
	}
	g_id_players = (int *)ft_memalloc(sizeof(int) * 4);
	g_count_bot = -1;
	init_vm(&vmka, -1);
	parsing_argv_params(argc, argv, &vmka, 0);
	init_field(&vmka, -1, -1);
	init_carriages(&vmka, -1);
	introducing(&vmka, -1);
	start_fight(&vmka);
	endwin();
//	system("leaks -q corewar");
}
