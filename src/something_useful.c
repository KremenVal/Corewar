/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   something_useful.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:41:52 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/25 11:41:54 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		error_management(char *error)
{
	ft_printf("%s", error);
	exit(0);
}

void		reverse_bits(void *b, int len)
{
	int		step;
	char	*tmptmp;
	char	tmp;

	step = -1;
	tmptmp = (char *)b;
	while (++step < len / 2)
	{
		tmp = tmptmp[step];
		tmptmp[step] = tmptmp[len - step - 1];
		tmptmp[len - step - 1] = tmp;
	}
}
