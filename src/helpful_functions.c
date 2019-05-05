/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmartyny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:27:18 by pmartyny          #+#    #+#             */
/*   Updated: 2019/05/03 13:27:19 by pmartyny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		get_oper(t_carr *tmp, unsigned int place)
{
	tmp->oper = place;
	if (tmp->oper >= 0x01 && tmp->oper <= 0x10)
		tmp->iter_to_wait = g_oper[tmp->oper - 1].wait;
}
