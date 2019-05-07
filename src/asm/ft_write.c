/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:07:14 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/06 16:07:15 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		ft_write(int fd, char **str, int size)
{
	if (write(fd, *str, size) < 0)
		ft_death("Write error!");
	ft_strdel(str);
}

void		ft_put_magic(int fd2)
{
	int		magic;
	int		i;
	char	*res;

	res = ft_strnew(4);
	i = 4;
	magic = COREWAR_EXEC_MAGIC;
	while(--i >= 0)
	{
		res[i] = magic % 256;
		magic /= 256;
	}
	ft_write(fd2, &res, 4);
}
