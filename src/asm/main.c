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

void			ft_writer(int fd2, char **namecom, t_label **labels,
							t_token **tokens)
{
	ft_put_magic(fd2, 0);
	ft_write_name(fd2, namecom[0], 1);
	// if (namecom[0])
		// free(namecom);
	ft_put_null(fd2);
	ft_put_magic(fd2, 1);
	ft_write_name(fd2, namecom[1], 2);
	ft_put_null(fd2);
	g_byte_pos = 0;
	ft_write_code(fd2, labels, tokens);
}

void			ft_check_tokens(t_token **tokens)
{
	t_token		*cur;

	cur = (*tokens);
	while (cur->next)
	{
		if (ft_strchr(cur->value, ' ') || ft_strchr(cur->value, '\t'))
			ft_death("Error in token!");
		if (cur->type == 2 || cur->type == 5)
		{
			printf("%s\n", cur->value);
			if (ft_strchr(cur->value + 1, DIRECT_CHAR))
				ft_death("Error in token!");
			if (ft_strchr(cur->value + 2, LABEL_CHAR))
				ft_death("Error in token!");
		}
		if (cur->type == 1)
			if (ft_strchr(cur->value + 1, 'r'))
				ft_death("Error in token!");
		printf("%s\n", cur->value);
		cur = cur->next;
	}
}

void			ft_starter(t_label **labels, t_token **tokens, char *str)
{
	char		*filename;
	int			fd;
	int			fd2;
	char		**namecom;

	fd = open(str, O_RDONLY);
	filename = ft_get_filename(str);
	fd2 = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0666);
	namecom = ft_get_name_comment(fd);
	free(filename);
	ft_get_tokens(fd, tokens, labels);
	ft_check_tokens(tokens);
	ft_get_size(tokens, labels);
	ft_writer(fd2, namecom, labels, tokens);
	free(namecom);
}

int				main(int ac, char **av)
{
	t_token		*tokens;
	t_label		*labels;

	if (ac != 2)
		ft_death("MY USAGE:");
	tokens = (t_token*)ft_memalloc(sizeof(t_token));
	labels = (t_label*)ft_memalloc(sizeof(t_label));
	ft_starter(&labels, &tokens, av[ac - 1]);
	system("leaks -q asmMY");
	return (0);
}
