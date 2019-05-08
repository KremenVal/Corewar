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

static void		check_for_winner(t_vmka **vmka)
{
	if (!(*vmka)->carr)
	{
		if (!(*vmka)->visual)
		{
			ft_printf("Contestant %d, \"%s\", has won !\n",
				(*vmka)->nbr_players,
				(*vmka)->bot[(*vmka)->nbr_players - 1]->name);
		}
		exit(0);
	}
}

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
	static int	cycles_to_dies;
	static int	checks;
	static int	cycles;

	cycles++;
	checks++;
	if (!cycles_to_dies)
		cycles_to_dies = (*vmka)->cycles_to_die;
	check_to_del_carr(vmka, (*vmka)->carr, NULL);
	if ((*vmka)->lives >= NBR_LIVE)
	{
		(*vmka)->cycles_to_die -= CYCLE_DELTA;
		cycles_to_dies = (*vmka)->cycles_to_die;
		checks = 0;
	}
	if (checks && !(checks %= MAX_CHECKS))
		if (cycles_to_dies == (*vmka)->cycles_to_die &&
			(*vmka)->cycles_to_die > 0)
		{
			(*vmka)->cycles_to_die -= CYCLE_DELTA;
			cycles_to_dies = (*vmka)->cycles_to_die;
		}
	check_for_winner(vmka);
	// if ((*vmka)->visual)
		// visual(vmka);
}
