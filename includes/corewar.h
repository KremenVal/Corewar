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
	char				*name;
	char				*comment;
	struct s_player		*next;
}						t_bot;

# endif