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

void		ft_writer(int fd2, char **namecom, t_label **labels, t_token **tokens)
{
	ft_put_magic(fd2, 0);
	ft_write_name(fd2, namecom[0], 1);
	ft_put_null(fd2);
	ft_put_magic(fd2, 1);
	ft_write_name(fd2, namecom[1], 2);
	ft_put_null(fd2);
	g_byte_pos = 0;
	ft_write_code(fd2, labels, tokens);
}

void		ft_starter(t_label **labels, t_token **tokens, char *str)
{
	char		*filename;
	int			fd;
	int			fd2;
	char		**namecom;

	fd = open(str, O_RDONLY);
	filename = ft_get_filename(str);
	fd2 = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0666);
	namecom = ft_get_name_comment(fd);
	ft_get_tokens(fd, tokens, labels);
	ft_get_size(tokens, labels);
	ft_writer(fd2, namecom, labels, tokens);
}

int			main(int ac, char **av)
{
	
	t_token		*tokens;
	t_label		*labels;

	if (ac == 1)
		ft_death("MY USAGE:");
	tokens = (t_token*)ft_memalloc(sizeof(t_token));
	labels = (t_label*)ft_memalloc(sizeof(t_label));
	ft_starter(&labels, &tokens, av[ac - 1]);

	printf("\nLABELS\n");
	while (labels->next)
	{
		printf("NAME: %s POS: %d\n", labels->name, labels->position);
		labels = labels->next;
	}
	printf("\nTOKENS\n");
	while (tokens->next)
	{
		printf("VALUE: %s TYPE: %d\n", tokens->value, tokens->type);
		tokens = tokens->next;
	}
	// system("leaks asmMY");
	// ft_write_code();
	return (0);
}