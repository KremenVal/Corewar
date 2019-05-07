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

char		*ft_get_name(char *line)
{
	int		i;
	int		y;
	char	*name;

	i = 5;
	while (line[i])
	{
		if (line[i] != '"' && line[i] != ' ' && line[i] != '\t')
			ft_death("Invalid character in .name!");
		if (line[i] == '"')
			break ;
		i++;
	}
	i++;
	y = i;
	while(line[i] != '"')
		i++;
	name = ft_strsub(line, y, i - y);
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0' && line[i] != '\n' && line[i] != COMMENT_CHAR &&
		line[i] != ALT_COMMENT_CHAR)
		ft_death("Error in name!");
	return (name);
}

char		*ft_get_comment(char *line)
{
	int		i;
	int		y;
	char	*comment;

	i = 8;
	while (line[i])
	{
		if (line[i] != '"' && line[i] != ' ' && line[i] != '\t')
			ft_death("Invalid character in .comment!");
		if (line[i] == '"')
			break ;
		i++;
	}
	i++;
	y = i;
	while(line[i] != '"')
		i++;
	comment = ft_strsub(line, y, i - y);
	i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0' && line[i] != '\n' && line[i] != COMMENT_CHAR &&
		line[i] != ALT_COMMENT_CHAR)
		ft_death("Error in name!");
	return (comment);
}

void		ft_get_name_comment(int fd)
{
	char	*line;
	char	*name;
	char	*comment;
	int		i;

	i = 0;
	while (i < 2)
	{
		get_next_line(fd, &line);
		if (ft_strstr(line, ".name"))
			name = ft_get_name(line);
		else if (ft_strstr(line, ".comment"))
			comment = ft_get_comment(line);
		else
			ft_death("Error in name/comment!");
		free(line);
		i++;
	}
	printf("NAME: |%s|, COMMENT: |%s|\n", name, comment);
}