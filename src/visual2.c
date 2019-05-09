/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 07:09:16 by oandrosh          #+#    #+#             */
/*   Updated: 2019/05/09 09:24:34 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	fill_usage(WINDOW **info)
{
	wprintw((*info), "\n\nUsage:\n\n\"Q\" - Speed UP\n\n\"A\" - Speed DOWN\n");
	wprintw((*info), "\n\"P\" / \"space\" - Pause\n\n\"Esc\" - Close program");
}

void	fill_info(t_vmka *all, WINDOW **info, int i)
{
	WINDOW	*header;

	header = newwin(5, 192, 1, 70);
	wattron(header, COLOR_PAIR(3));
	wprintw(header, "`¶¶¶¶`````¶¶¶¶````¶¶¶¶¶````¶¶¶¶¶```¶¶```¶¶```¶¶¶¶````");
	wprintw(header, "¶¶¶¶¶\n¶¶``¶¶```¶¶``¶¶```¶¶``¶¶```¶¶``````¶¶```¶¶``¶¶`");
	wprintw(header, "`¶¶```¶¶``¶¶\n¶¶```````¶¶``¶¶```¶¶¶¶¶````¶¶¶¶````¶¶`¶`");
	wprintw(header, "¶¶``¶¶¶¶¶¶```¶¶¶¶¶\n¶¶``¶¶```¶¶``¶¶```¶¶``¶¶```¶¶``````");
	wprintw(header, "¶¶¶¶¶¶¶``¶¶``¶¶```¶¶``¶¶\n`¶¶¶¶`````¶¶¶¶````¶¶``¶¶```¶¶");
	wprintw(header, "¶¶¶````¶¶`¶¶```¶¶``¶¶```¶¶``¶¶");
	wattroff(header, COLOR_PAIR(3));
	refresh();
	wrefresh(header);
	wprintw((*info), "CYCLES/SEC: %.f\n", 1000 / all->speed + 0.5);
	while (++i < 4 && all->bot[i]->name[0])
	{
		wprintw((*info), "\nPLAYER %d: ", i + 1);
		wattron((*info), COLOR_PAIR(i + 1));
		wprintw((*info), "%s\n", all->bot[i]->name);
		wattroff((*info), COLOR_PAIR(i + 1));
		wprintw((*info), "LIVES: %d\n", all->carr->last_live);
		wprintw((*info), "NUMBER OF LIVE: \n");
	}
	wprintw((*info), "\n\nCYCLES: %d\n", all->cycles);
	wprintw((*info), "CYCLES TO DIE: %d\n", all->cycles_to_die);
	fill_usage(info);
}

void	pause_game(void)
{
	int		key;
	WINDOW	*pause;

	pause = newwin(1, 5, 7, 208);
	wprintw(pause, "PAUSE");
	refresh();
	wrefresh(pause);
	while (1)
	{
		key = getch();
		if (key == 32 || key == 'p')
			break ;
		else if (key == 27)
		{
			endwin();
			exit(1);
		}
	}
}

void	config(t_vmka **all, int key)
{
	key = getch();
	if (key == 27)
	{
		endwin();
		exit(1);
	}
	else if (key == 32 || key == 'p')
		pause_game();
	else if (key == 'q' && (*all)->speed > 1)
		(*all)->speed /= 2;
	else if (key == 'a' && (*all)->speed < 512)
		(*all)->speed *= 2;
}
