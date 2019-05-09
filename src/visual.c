/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 03:56:18 by oandrosh          #+#    #+#             */
/*   Updated: 2019/05/09 02:36:06 by oandrosh         ###   ########.fr       */
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
			return (tmp->carr_color);
		tmp = tmp->next;
	}
	return (0);
}

void	fill_field(t_vmka *all, WINDOW **field, int i)
{
	int		id;
	int		id_carr;

	while (++i < MEM_SIZE)
	{
		id = all->field[i].id_bot;
		if ((id_carr = is_carr(all, i)) != 0)
		{
			wattron((*field), COLOR_PAIR(id_carr + 4));
			wprintw((*field), "%02x", all->field[i].place);
			wattroff((*field), COLOR_PAIR(id_carr + 4));
			wprintw((*field), " ");
		}
		else
		{
			wattron((*field), COLOR_PAIR(id));
			wprintw((*field), "%02x ", all->field[i].place);
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
	WINDOW	*info;

	initscr();
	(void)all;
	curs_set(0);
	field = newwin(64, 192, 1, 1);
	info = newwin(30, 30, 1, 196);
	start_color();
	noecho();
	set_colors();
	fill_field(*all, &field, -1);
	fill_info(*all, &info, -1);
	refresh();
	nodelay(stdscr, TRUE);
	wrefresh(field);
	wrefresh(info);
	timeout((*all)->speed);
	config(all, 0);
}
