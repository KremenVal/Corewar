/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:58:42 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/23 11:58:46 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		pars(int argc, char **argv, t_bot **bot)
{

}

int			main(int argc, char **argv)
{
	t_bot	*bot;
	if (argc >= 2)
		pars(argc, argv, &bot);
	else
		ft_printf("Ne zaebis9\n");
}
