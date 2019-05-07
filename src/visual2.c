/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 07:09:16 by oandrosh          #+#    #+#             */
/*   Updated: 2019/05/07 07:42:18 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	fill_usage(WINDOW **info)
{
	wprintw((*info), "\n\nUsage:\n\"Q\" - Speed UP\n\"A\" - Speed DOWN\n");
	wprintw((*info), "\"P\" / \"space\" - Pause\n\"Esc\" - Close program");
}

void	fill_info(t_vmka *all, WINDOW **info, int i)
{
	wprintw((*info), "STATUS: PLAY\n");
	wprintw((*info), "CYCLES/SEC: %.1f\n", 1000 / (float)all->speed);
	while (++i < 4 && all->bot[i]->name[0])
	{
		wprintw((*info), "\nPLAYER %d: ", i + 1);
		wattron((*info), COLOR_PAIR(i + 1));
		wprintw((*info), "%s\n", all->bot[i]->name);
		wattroff((*info), COLOR_PAIR(i + 1));
		wprintw((*info), "LIVE NOW: \n");
		wprintw((*info), "LAST LIVE: \n");
	}
	fill_usage(info);
}
