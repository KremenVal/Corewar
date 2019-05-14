/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 03:45:48 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/11 03:45:49 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			ft_check_ind(char *str, t_label **labels)
{
	int			i;
	int			flag;
	t_label		*cur;

	i = 0;
	flag = 0;
	cur = *labels;
	if (str[0] == LABEL_CHAR)
	{
		while (cur->next)
		{
			if (ft_strequ(str + 1, cur->name))
				flag = 1;
			cur = cur->next;
		}
		if (flag != 1)
			ft_death("Bad argument!");
	}
	else
	{
		while (str[++i])
			if (!ft_isdigit(str[i]))
				ft_death("Bad argument!");
	}
}

static void		ft_get_rest_2(t_token **cur, t_label **labels, char ***mass,
								int i)
{
	if ((*mass)[i][0] == 'r')
	{
		g_code_size++;
		(*cur)->type = REG;
	}
	else if ((*mass)[i][0] == '%')
	{
		if (ft_strchr((*mass)[i], LABEL_CHAR))
			(*cur)->type = DIR_L;
		else
			(*cur)->type = DIR;
	}
	else
	{
		ft_check_ind((*mass)[i], labels);
		if (ft_strchr((*mass)[i], LABEL_CHAR))
			(*cur)->type = IND_L;
		else
			(*cur)->type = IND;
		g_code_size += 2;
	}
}

void			ft_get_rest(char *str, t_token **tokens, int i,
								t_label **labels)
{
	char		*tmp;
	t_token		*cur;
	char		**mass;

	cur = *tokens;
	str = ft_destroy_comments(str);
	mass = ft_strsplit(str, ',');
	while (mass[++i])
	{
		tmp = mass[i];
		mass[i] = ft_strtrim(mass[i]);
		ft_strdel(&tmp);
	}
	i = -1;
	while (mass[++i])
	{
		while (cur->next)
			cur = cur->next;
		if (!cur->next)
			cur->next = (t_token*)ft_memalloc(sizeof(t_token));
		cur->value = mass[i];
		ft_get_rest_2(&cur, labels, &mass, i);
	}
}

void			ft_define_tokens(char *str, t_token **tokens, t_label **labels)
{
	int			i;
	int			y;
	t_token		*cur;
	char		*rest;
	char		*tmp;

	i = -1;
	cur = *tokens;
	while (cur->next)
		cur = cur->next;
	cur->next = (t_token*)ft_memalloc(sizeof(t_token));
	while (str[++i] == ' ' || str[i] == '\t')
		;
	y = i;
	while (str[++i] != ' ' && str[i] != '\t')
		;
	cur->value = ft_strsub(str, y, i - y);
	cur->type = OP;
	g_code_size++;
	rest = ft_strsub(str, i, (int)ft_strlen(str) - i);
	tmp = rest;
	rest = ft_strtrim(rest);
	ft_strdel(&tmp);
	ft_get_rest(rest, tokens, -1, labels);
}

void			ft_get_tokens(int fd, t_token **tokens, t_label **labels)
{
	char		*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_empty(line))
		{
			if (ft_is_label(line))
				ft_add_label(line, labels, tokens, -1);
			else
				ft_define_tokens(line, tokens, labels);
		}
		ft_strdel(&line);
	}
}
