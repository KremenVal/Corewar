/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:58:42 by vkremen           #+#    #+#             */
/*   Updated: 2019/05/06 07:53:19 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

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
	start_fight(&vmka);
//	print_field(vmka, -1);
	visual(&vmka);
//	system("leaks -q corewar");
}
