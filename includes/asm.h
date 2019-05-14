/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbakhari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:34:38 by kbakhari          #+#    #+#             */
/*   Updated: 2019/05/06 13:35:04 by kbakhari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/libft.h"
# include <stdio.h>
# include "op.h"
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>
# include <ncurses.h>

/*
**	ft_utility.c
*/

void		ft_death(char *str);

/*
**	ft_write.c
*/

void		ft_write(int fd, char **str, int size);
void		ft_put_magic(int fd2);

/*
**	ft_functions.c
*/

void		ft_get_name_comment(int fd);
char		*ft_get_name(char *line);
char		*ft_get_comment(char *line);

#endif
