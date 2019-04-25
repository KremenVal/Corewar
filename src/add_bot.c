/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_bot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:33:08 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/25 11:33:10 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		add_bot_to_battle(char *bot, t_vmka  **vmka)
{
	int		fd;
	int		num;

	(void)vmka;
	if (bot[0] == '\0' || !ft_strcmp(bot, ".cor"))
		error_management("ERROR: incorrect champion name!\n");
	if (ft_strcmp(ft_strrchr(bot, '.'), ".cor"))
		error_management("ERROR: invalid file extension!\n");
	num = -1;
	if ((fd = open(bot, O_RDONLY)) != -1)
		num = lseek(fd, 0 , 2);
	else
		error_management("ERROR: this file doesn't exist!\n");
	close(fd);
	ft_printf("%d|%d\n", num - sizeof(t_header), CHAMP_MAX_SIZE);
	if (num - sizeof(t_header) > CHAMP_MAX_SIZE)
		error_management("ERROR: champion size exceeds the max "\
			"champion size\n");
}
