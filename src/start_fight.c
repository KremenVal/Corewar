/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:24:46 by pmartyny          #+#    #+#             */
/*   Updated: 2019/05/03 13:24:47 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		start_fight(t_vmka **vmka)
{
	t_carr	*tmp;

	tmp = (*vmka)->carr;
	introducing(vmka, -1);
	while (tmp)
	{
		if (!tmp->iter_to_wait)
			get_oper(tmp, (*vmka)->field[tmp->poss_carr].place);
		if (tmp->iter_to_wait > 0)
			tmp->iter_to_wait--;
		if (!tmp->iter_to_wait)
		{
			if (tmp->oper >= 0x01 && tmp->oper <= 0x10)
				;
			else
				tmp->poss_carr = (tmp->poss_carr + 1) % MEM_SIZE;
		}
		tmp = tmp->next;
	}
	(*vmka)->dump_cycles++;
}
