/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 10:30:14 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/25 10:30:15 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		init_vm(t_vmka **vmka)
{
	int 	i;

	i = -1;
	(*vmka) = (t_vmka *)ft_memalloc(sizeof(t_vmka));
	(*vmka)->bot = (t_bot *)ft_memalloc(sizeof(t_bot) * MAX_PLAYERS);
	while (++i < MAX_PLAYERS)
	{
		(*vmka)->bot[i].name = (char *)ft_memalloc(sizeof(char)
			* PROG_NAME_LENGTH);
		(*vmka)->bot[i].comment = (char *)ft_memalloc(sizeof(char)
			* COMMENT_LENGTH);
		(*vmka)->bot[i].code = (char *)ft_memalloc(sizeof(char)
			* CHAMP_MAX_SIZE);
	}
}
