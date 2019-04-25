/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:39:09 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/23 12:39:12 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "../libft/libft.h"
# include "op.h"
# include <stdio.h>
# include <stdint.h>

typedef struct			s_bot
{
	int					id_bot;
	char				*name;
	char				*comment;
	char				*code;
}						t_bot;

typedef struct			s_vmka
{
	t_bot				*bot;
}						t_vmka;

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

/*
** main.c
*/

void					pars(int argc, char **argv, t_vmka **vmka);

/*
** init_vm.c
*/

void					init_vm(t_vmka **vmka);

/*
** init_vm.c
*/

void					add_bot_to_battle(char *bot, t_vmka  **vmka);

/*
** init_vm.c
*/

void					error_management(char *error);

# endif