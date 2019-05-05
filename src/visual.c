/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 03:56:18 by oandrosh          #+#    #+#             */
/*   Updated: 2019/05/05 08:52:41 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

int		is_carr(t_vmka *all, int i)
{
	t_carr	*tmp;

	tmp = all->carr;
	while (tmp)
	{
		if (tmp->poss_carr == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	fill_field(t_vmka **all, WINDOW **field, int i)
{
	int		id;

	while (++i < MEM_SIZE)
	{
		id = (*all)->field[i].id_bot;
		if (id != 0 && is_carr(*all, i) == 1)
		{
			wattron((*field), COLOR_PAIR(id + 4));
			wprintw((*field), "%02x", (*all)->field[i].place);		
			wattroff((*field), COLOR_PAIR(id + 4));
			wprintw((*field), " ");
		}
		else
		{
			wattron((*field), COLOR_PAIR(id));
			wprintw((*field), "%02x ", (*all)->field[i].place);
			wattroff((*field), COLOR_PAIR(id));
		}
	}
}

void	set_colors(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_RED);
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	init_pair(7, COLOR_BLACK, COLOR_GREEN);
	init_pair(8, COLOR_BLACK, COLOR_YELLOW);
}

void	visual(t_vmka **all)
{
	WINDOW	*field;
	WINDOW	*inform;
	WINDOW	*usage;

	initscr();
	(void)all;
	field = newwin(64, 192, 0, 1);
	inform = newwin(30, 30, 0, 193);
	usage = newwin(10, 100, 65, 1);
	start_color();
	noecho();
	set_colors();
	fill_field(all, &field, -1);
	wprintw(inform, "fsdaf32r2rfd`sfffFdddadfadsfasf");
	refresh();
	wrefresh(field);
	wrefresh(inform);
	getch();
	endwin();
}
