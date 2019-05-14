/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:45:28 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/06 16:45:30 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

char		*ft_get_name(int fd, char *line, int flag)
{
	int		y;
	int		i;
	char	*name;
	char	*tmp;

	i = -1;
	while (line[++i] != '.')
		if(line[i] != ' ' && line[i] != '\t')
			ft_death("Error in name/comment");
	if(flag == 1 && (line[i + 1] != 'n' || line[i + 2] != 'a' || line[i + 3] != 'm' ||
		line[i + 4] != 'e'))
		ft_death("Error in name");
	if(flag == 2 && (line[i + 1] != 'c' || line[i + 2] != 'o' || line[i + 3] != 'm' ||
		line[i + 4] != 'm' || line[i + 5] != 'e' || line[i + 6] != 'n' || line[i + 7] != 't'))
		ft_death("Error in comment");
	i += flag == 1 ? 5 : 8;
	while (line[++i] != '"')
		if(line[i] != ' ' && line[i] != '\t')
			ft_death("Error in name/comment");
	y = i + 1;
	name = NULL;
	while(line[++i] != '"')
	{
		if (!line[i])
		{
			if (!name)
			{
				name = ft_strsub(line, y, i - y);
				name = ft_strjoin(name, "\n");
			}
			else
			{
				tmp = ft_strsub(line, y, i - y);
				name = ft_strjoin(name, tmp);
				ft_strdel(&tmp);
				name = ft_strjoin(name, "\n");
			}
			y = 0;
			i = -1;
			ft_strdel(&line);
			get_next_line(fd, &line);
		}
	}
	if (!name)
		name = ft_strsub(line, y, i - y);
	else
	{
		tmp = ft_strsub(line, y, i - y);
		name = ft_strjoin(name, tmp);
		ft_strdel(&tmp);
	}
	ft_strdel(&line);
	return (name);
}

char		**ft_get_name_comment(int fd)
{
	char	*line;
	int		i;
	int		flag;
	char	**res;

	i = 0;
	flag = 0;
	res = (char**)ft_memalloc(sizeof(char*) * 3);
	while (i < 2)
	{
		get_next_line(fd, &line);
		while (!ft_check_empty(line))
		{
			ft_strdel(&line);
			get_next_line(fd, &line);
		}
		if (ft_strstr(line, ".name"))
		{
			if (res[0])
				ft_death("Dublicate name");
			flag++;
			res[0] = ft_get_name(fd, line, 1);
		}
		else if (ft_strstr(line, ".comment") && !res[1])
		{
			if (res[1])
				ft_death("Dublicate comment");
			flag++;
			res[1] = ft_get_name(fd, line, 2);
		}
		i++;
	}
	if (flag != 2)
		ft_death("No name/comment!");
	res[2] = "\0";
	return(res);
}
