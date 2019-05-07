/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oandrosh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 07:09:16 by oandrosh          #+#    #+#             */
/*   Updated: 2019/05/06 07:22:49 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void	fill_info(t_vmka *all, WINDOW **info, int i)
{
	while (++i < 4 && all->bot[i]->name[0])
	{
		wprintw((*info), "PLAYER %d: ", i);
		wattron((*info), COLOR_PAIR(i + 1));
		wprintw((*info), "%s\n", all->bot[i]->name);
		wattroff((*info), COLOR_PAIR(i + 1));
	}
}
