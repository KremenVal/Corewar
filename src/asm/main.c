/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:31:28 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/06 13:31:29 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void		ft_get_tokens(int fd, t_token **tokens, t_label **labels)
{
	char	*line;
	int		next;

	next = 0;
	tokens = NULL;
	g_byte_pos = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_empty(line))
		{
			if (ft_is_label(line))
			{
				printf("FOUND LABEL: %s\n", line);
			}
			else
			{
				if (next == 1)
				{
					printf("TARGET: %s\n", line);
				}
				else
					printf("FOUND: %s\n", line);
			}
		}
		free(line);
	}
}

char		*ft_get_filename(char *name)
{
	char	*result;
	int		endlen;
	int		namelen;

	endlen = (int)ft_strlen((ft_strrchr(name, '.'), ".s"));
	namelen = (int)ft_strlen(name) - endlen;
	if (ft_strcmp(ft_strrchr(name, '.'), ".s"))
		ft_death("Bad file");
	result = ft_strsub(name, 0, namelen);
	result = ft_strjoin(result, ".cor");
	return (result);
}

int			main(int ac, char **av)
{
	char		*filename;
	int			fd;
	int			fd2;
	char		*comment;
	t_token		*tokens;
	t_label		*labels;

	if (ac != 2)
		ft_death("Not yet fam.");
	fd = open(av[1], O_RDONLY);
	filename = ft_get_filename(av[1]);
	tokens = ft_memalloc(sizeof(t_token));
	tokens = ft_memalloc(sizeof(t_label));
	fd2 = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0666);
	ft_put_magic(fd2);
	comment = ft_get_name_comment(fd, fd2);
	ft_put_null(fd2);
	ft_get_tokens(fd, &tokens, &labels);
	ft_put_null(fd2); // тут будет размер кода
	ft_write_name(fd2, comment, 2);
	ft_put_null(fd2);
	return (0);
}