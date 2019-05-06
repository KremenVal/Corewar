/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fight_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:43:56 by pmartyny          #+#    #+#             */
/*   Updated: 2019/05/06 15:44:01 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void		check_to_del_carr(t_vmka **vmka, t_carr *tmp, t_carr *tmp_prev)
{
	while (tmp)
	{
		if ((*vmka)->cycles - tmp->last_live >= (*vmka)->cycles_to_die)
		{
			if ((*vmka)->carr == tmp)
			{
				(*vmka)->carr = tmp->next;
				free(tmp);
				tmp = (*vmka)->carr;
			}
			else
			{
				tmp_prev->next = tmp->next;
				free(tmp);
				tmp = tmp_prev->next;
			}
		}
		else
		{
			tmp_prev = tmp;
			tmp = tmp->next;
		}
	}
}

void			start_fight_2(t_vmka **vmka)
{
	static int	cycles_to_dies = 0;
	static int	checks;
	static int	cycles = 0;
	
	cycles++;
	checks++;
	if (!cycles_to_dies)
		cycles_to_dies = (*vmka)->cycles_to_die;
	check_to_del_carr(vmka, (*vmka)->carr, NULL);
	if ()
}
