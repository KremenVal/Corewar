/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 20:07:01 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/12 20:07:03 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			ft_lld(t_token **token, t_label **labels, int fd2)
{
	char	*res;
	int		n;
	int		tmp;

	res = ft_hex_conv(13, 1);
	n = 0;
	ft_write(fd2, &res, 1);
	g_byte_pos++;
	tmp = 16;
	//size
	if ((*token)->next)
		(*token) = (*token)->next;
	if ((*token)->type == 2 || (*token)->type == 5)
		tmp += 128;
	else
		tmp += 192;
	res = ft_hex_conv(tmp, 1);
	ft_write(fd2, &res, 1);
	g_byte_pos++;
	//endofsize
	//arg 1
	if ((*token)->type == 3)
		n = ft_atoi((*token)->value);
	else if ((*token)->type == 2)
		n = ft_atoi((*token)->value + 1);
	else if ((*token)->type == 5)
		n = ft_get_label_val((*token)->value + 1, labels) - g_byte_pos + 2;
	else if ((*token)->type == 6)
		n = ft_get_label_val((*token)->value, labels) - g_byte_pos + 2;
	else
		ft_death("Bad first argument for lld!!!");
	if ((*token)->type == 2 || (*token)->type == 5)
		tmp = 4;
	else
		tmp = 2;
	res = ft_hex_conv(n, tmp);
	ft_write(fd2, &res, tmp);
	g_byte_pos += tmp;
	//dir
	if ((*token)->next)
		(*token) = (*token)->next;
	if ((*token)->type != 1)
		ft_death("Bad second argument for lld!!!");
	n = ft_atoi((*token)->value + 1);
	if (n > 99 || n < 0)
		ft_death("Bad register!!!");
	res = ft_hex_conv(n, 1);
	ft_write(fd2, &res, 1);
	g_byte_pos++;
}