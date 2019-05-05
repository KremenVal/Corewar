/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 10:37:00 by vkremen           #+#    #+#             */
/*   Updated: 2019/05/04 10:37:01 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		print_field(t_vmka *vmka, int i)
{
	while (++i < MEM_SIZE)
	{
		if (vmka->field[i].id_bot == 1)
			ft_printf("\033[0;31m%02x", vmka->field[i].place);
		else if (vmka->field[i].id_bot == 2)
			ft_printf("\033[0;32m%02x", vmka->field[i].place);
		else if (vmka->field[i].id_bot == 3)
			ft_printf("\033[0;33m%02x", vmka->field[i].place);
		else if (vmka->field[i].id_bot == 4)
			ft_printf("\033[0;34m%02x", vmka->field[i].place);
		else
			ft_printf("\033[0m%02x", vmka->field[i].place);
		if ((i + 1) % 64 != 0 || i == 0)
			ft_printf(" ");
		if ((i + 1) % 64 == 0 && i != 0)
			ft_printf("\n");
	}
}

void		introducing(t_vmka **vmka, int id)
{
	ft_printf("Introducing contestants...\n");
	while (++id < (*vmka)->nbr_players)
	{
		ft_printf("\033[0;3%dm* Player %d, weighing %d bytes, \"%s\" ",
			id + 1, id + 1, (*vmka)->bot[id]->code_size,
			(*vmka)->bot[id]->name);
		ft_printf("(\"%s\") !\n", (*vmka)->bot[id]->comment);
	}
}

void		print_carriages(t_vmka *vmka)
{
	t_carr	*tmp;

	tmp = vmka->carr;
	while (tmp)
	{
		if (tmp->id_carr == 1)
			ft_printf("\033[0;31m%02x", tmp->poss_carr);
		else if (tmp->id_carr == 2)
			ft_printf("\033[0;32m%02x", tmp->poss_carr);
		else if (tmp->id_carr == 3)
			ft_printf("\033[0;33m%02x", tmp->poss_carr);
		tmp = tmp->next;
	}
	ft_printf("\033[0m");
}
