/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 03:56:18 by oandrosh          #+#    #+#             */
/*   Updated: 2019/05/05 07:56:45 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	fill_field(t_vmka **all, WINDOW **field, int i)
{
	while (++i < MEM_SIZE)
	{
		wattron((*field), COLOR_PAIR((*all)->field[i].id_bot));
		wprintw((*field), "%02x ", (*all)->field[i].place);
		wattroff((*field), COLOR_PAIR((*all)->field[i].id_bot));
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
	field = newwin(64, 192, 1, 1);
	inform = newwin(30, 30, 1, 196);
	usage = newwin(10, 100, 65, 1);
	start_color();
	set_colors();
	fill_field(all, &field, -1);
	wprintw(inform, "fsdaf32r2rfd`sfffFdddadfadsfasf");
	refresh();
	wrefresh(field);
	wrefresh(inform);
	getch();
	endwin();
}
