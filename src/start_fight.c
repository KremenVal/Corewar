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
			get_oper_code(tmp, (*vmka)->field[tmp->poss_carr].place);
		ft_printf("%d|%d\n", tmp->iter_to_wait, tmp->id_carr);
		tmp->iter_to_wait -= tmp->iter_to_wait > 0 ? 1 : 0;
		tmp = tmp->next;
	}
}
