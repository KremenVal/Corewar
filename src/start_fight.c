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

static void		check_oper(t_vmka **vmka, t_carr *carr, int i, int j)
{
	int			code;

	(void)i;
	(void)j;
	code = (*vmka)->field[(carr->poss_carr + 1) % MEM_SIZE].place;
	carr->args_types[0] = (code >> j) % 4;
}

void			start_fight(t_vmka **vmka)
{
	t_carr		*tmp;
	int			kek;

	introducing(vmka, -1);
	kek = 7;
	while (--kek >= 0)
	{
		tmp = (*vmka)->carr;
		while (tmp)
		{
			if (!tmp->iter_to_wait)
				get_oper(tmp, (*vmka)->field[tmp->poss_carr].place);
			if (tmp->iter_to_wait > 0)
				tmp->iter_to_wait--;
			if (!tmp->iter_to_wait)
			{
				if (tmp->oper >= 0x01 && tmp->oper <= 0x10)
					check_oper(vmka, tmp, -1, 6);
				tmp->poss_carr = (tmp->poss_carr + 1) % MEM_SIZE;
			}
			tmp = tmp->next;
		}
	}
}
