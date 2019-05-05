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

t_carr		*prev_tmp(t_carr *carr)
{
	t_carr	*temp;

	temp = carr;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void		print_place_on_field(t_vmka *vmka, int i, int *var, t_carr **tmp)
{
	int		id;

	id = vmka->field[i].id_bot;
	if (vmka->field[(*tmp)->poss_carr].place == vmka->field[i].place &&
		vmka->field[i].id_bot == (*tmp)->id_carr && (*var))
	{
		ft_printf("\033[4;3%dm%02x", id, vmka->field[i].place);
		if ((*tmp)->prev)
			(*tmp) = (*tmp)->prev;
		else
			(*var) = 0;
	}
	else
		ft_printf("\033[0;3%dm%02x", id, vmka->field[i].place);
}

void		print_field(t_vmka *vmka, int i)
{
	t_carr	*tmp;
	int		var;

	var = 1;
	tmp = prev_tmp(vmka->carr);
	while (++i < MEM_SIZE)
	{
		if (vmka->field[i].id_bot == 1)
			print_place_on_field(vmka, i, &var, &tmp);
		else if (vmka->field[i].id_bot == 2)
			print_place_on_field(vmka, i, &var, &tmp);
		else if (vmka->field[i].id_bot == 3)
			print_place_on_field(vmka, i, &var, &tmp);
		else if (vmka->field[i].id_bot == 4)
			print_place_on_field(vmka, i, &var, &tmp);
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
