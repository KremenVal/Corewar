/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:37:19 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/06 13:37:20 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void	ft_death(char *str)
{
	int len;
	int i;

	i = -1;
	len = (int)ft_strlen(str);
	ft_printf("\033[0;31m/");
	while (++i < len + 5)
		ft_printf("-");
	ft_printf("\\\n");
	ft_printf("| %s%s\n", str, "    |");
	i = -1;
	ft_printf("\\");
	while(++i < len + 5)
		ft_printf("-");
	ft_printf("/\n\033[0m");
	exit(0);
}