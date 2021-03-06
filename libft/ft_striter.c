/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:46:48 by vkremen           #+#    #+#             */
/*   Updated: 2018/10/31 18:37:11 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int step;

	if (s != NULL && f != NULL)
	{
		step = 0;
		while (s[step])
		{
			f(&s[step]);
			step++;
		}
	}
}
