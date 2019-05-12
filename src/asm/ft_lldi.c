/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 20:09:45 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/12 20:09:46 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			ft_lldi(t_token **token, t_label **labels, int fd2)
{
	char	*res;
	int		n;
	int		tmp;

	res = ft_hex_conv(14, 1);
	n = 0;
	ft_write(fd2, &res, 1);
	g_byte_pos++;
	tmp = 0;
	//size
	if ((*token)->next)
		(*token) = (*token)->next;
	if ((*token)->type == 1)
		tmp += 64;
	else if ((*token)->type == 2 || (*token)->type == 5)
		tmp += 128;
	else
		tmp += 192;
	if ((*token)->next->type == 1)
		tmp += 16;
	else if ((*token)->next->type == 2 || (*token)->next->type == 5)
		tmp += 32;
	else
		tmp += 48;
	res = ft_hex_conv(tmp + 4, 1);
	ft_write(fd2, &res, 1);
	g_byte_pos++;
	//endofsize
	//arg 1
	if ((*token)->type == 1)
		n = ft_atoi((*token)->value + 1);
	else if ((*token)->type == 3)
		n = ft_atoi((*token)->value);
	else if ((*token)->type == 2)
		n = ft_atoi((*token)->value + 1);
	else if ((*token)->type == 5)
		n = ft_get_label_val((*token)->value + 1, labels) - g_byte_pos + 2;
	else if ((*token)->type == 6)
		n = ft_get_label_val((*token)->value, labels) - g_byte_pos + 2;
	else
		ft_death("Bad first argument for lldi!!!");
	if ((*token)->type == 1)
		tmp = 1;
	else
		tmp = 2;
	res = ft_hex_conv(n, tmp);
	ft_write(fd2, &res, tmp);
	g_byte_pos += tmp;
	//arg 2
	if ((*token)->next)
		(*token) = (*token)->next;
	if ((*token)->type == 1)
		n = ft_atoi((*token)->value + 1);
	else if ((*token)->type == 2)
		n = ft_atoi((*token)->value + 1);
	else if ((*token)->type == 5)
		n = ft_get_label_val((*token)->value + 1, labels) - g_byte_pos + 2;
	else
		ft_death("Bad second argument for lldi!!!");
	if ((*token)->type == 1)
		tmp = 1;
	else
		tmp = 2;
	res = ft_hex_conv(n, tmp);
	ft_write(fd2, &res, tmp);
	g_byte_pos += tmp;
	//dir
	if ((*token)->next)
		(*token) = (*token)->next;
	if ((*token)->type != 1)
		ft_death("Bad third argument for lldi!!!");
	n = ft_atoi((*token)->value + 1);
	if (n > 99 || n < 0)
		ft_death("Bad register!!!");
	res = ft_hex_conv(n, 1);
	ft_write(fd2, &res, 1);
	g_byte_pos++;
}