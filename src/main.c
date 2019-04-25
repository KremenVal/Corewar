/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:58:42 by vkremen           #+#    #+#             */
/*   Updated: 2019/04/23 11:58:46 by vkremen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

// static int32_t	bytecode_to_int32(const uint8_t *bytecode, size_t size)
// {
// 	int32_t	result;
// 	// t_bool	sign;
// 	int		i;

// 	result = 0;
// 	// sign = (t_bool)(bytecode[0] & 0x80);
// 	i = 0;
// 	while (size)
// 	{
// 		// if (sign)
// 			result += ((bytecode[size - 1] ^ 0xFF) << (i++ * 8));
// 		// else
// 		// result += bytecode[size - 1] << (i++ * 8);
// 		size--;
// 	}
// 	// if (sign)
// 	// 	result = ~(result);
// 	return (result);
// }

void		pars(int argc, char **argv, t_vmka **vmka)
{
	// int 	fd;
	// int 	r;
	// uint8_t	magic[5];
	// (void) argc;
	// (void) bot;

	// fd = open(argv[1], O_RDWR);

	// int i = 0;
	// // while (i < 10)
	// // {
	// 	r = read(fd, &magic, 4);
	// 	i++;
	// 	// magic[r] = '\0';
	// 	ft_printf("|%u|\n", bytecode_to_int32(magic, 4));
	// 	// ft_bzero(magic, 5);
	// // }
	int		i;

	i = 0;
	(void)vmka;
	while (++i < argc)
	{
		add_bot_to_battle(argv[i], vmka);
	}
}

int			main(int argc, char **argv)
{
	t_vmka	*vmka;

	init_vm(&vmka);
	if (argc >= 2)
		pars(argc, argv, &vmka);
	else
		ft_printf("Ne zaebis9\n");
	system("leaks -q corewar");
}
