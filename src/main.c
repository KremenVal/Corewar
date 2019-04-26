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

void		pars(int argc, char **argv, t_vmka **vmka)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	(void)vmka;
	while (++i < argc)
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			j++;
			if ((*vmka)->bot[j]->id_bot == 0)
				(*vmka)->bot[j]->id_bot = j;
			add_bot_to_battle(argv[i], &(*vmka)->bot[j]);
			ft_printf("Id: %d, Header: %x, Name: %s, Code-size: %d ",
				(*vmka)->bot[j]->id_bot, (*vmka)->bot[j]->header,
				(*vmka)->bot[j]->name, (*vmka)->bot[j]->code_size);
			ft_printf(", Comment: %s\n", (*vmka)->bot[j]->comment);
		}
	}
}

int			main(int argc, char **argv)
{
	t_vmka	*vmka;

	init_vm(&vmka);
	if (argc >= 2)
		pars(argc, argv, &vmka);
	else
		ft_printf("Ne zaebis9\n");
	system("leaks -q corewar");
}
