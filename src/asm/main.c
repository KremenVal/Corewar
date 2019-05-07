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
	char	*filename;
	int		fd;
	int		fd2;

	if (ac != 2)
		ft_death("Not yet fam.");
	fd = open(av[1], O_RDONLY);
	filename = ft_get_filename(av[1]);
	fd2 = open(filename, O_RDWR | O_TRUNC | O_CREAT, 0666);
	ft_put_magic(fd2);
	ft_get_name_comment(fd);
	return (0);
}