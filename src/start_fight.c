/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:24:46 by pmartyny          #+#    #+#             */
/*   Updated: 2019/05/05 08:49:15 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		make_oper(t_vmka **vmka, t_carr *carr)
{

}

static void		check_oper(t_vmka **vmka, t_carr *carr, int i, int j)
{
	int			code;
	int			res;

	(void)i;
	code = (*vmka)->field[(carr->poss_carr + 1) % MEM_SIZE].place;
	while (++i < g_op[carr->oper - 1].args_num)
	{
		carr->args_type[i] = (code >> j) % 4;
		if (carr->args_type[i] == REG_CODE)
		{
			carr->args_size[i] = 1;
			res = 
		}
	}
}

void			start_fight(t_vmka **vmka)
{
	t_carr		*tmp;
	int			kek;

	kek = 6;
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
					make_oper(vmka, tmp);
					// ft_bzero(tmp->args_size, 3);
					// check_oper(vmka, tmp, -1, 6);
				else
					tmp->poss_carr = (tmp->poss_carr + 1) % MEM_SIZE;
			}
			tmp = tmp->next;
		}
		visual(vmka);
	}
}
