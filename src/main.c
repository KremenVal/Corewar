/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkremen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:58:42 by vkremen           #+#    #+#             */
/*   Updated: 2019/05/09 01:24:52 by oandrosh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static int		music(void)
{
	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return (0);
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		return (0);
	g_wave = Mix_LoadWAV(WAV_PATH);
	if (g_wave == NULL)
		return (0);
	g_music = Mix_LoadMUS(WAV_PATH);
	if (g_music == NULL)
		return (0);
	if (Mix_PlayChannel(-1, g_wave, 0) == -1)
		return (0);
	if (Mix_PlayMusic(g_music, -1) == -1)
		return (0);
	return (1);
}

static void		introducing(t_vmka **vmka, int id)
{
	ft_printf("Introducing contestants...\n");
	while (++id < (*vmka)->nbr_players)
	{
		ft_printf("\033[0;3%dm* Player %d, weighing %d bytes, \"%s\" ",
			id + 1, id + 1, (*vmka)->bot[id]->code_size,
			(*vmka)->bot[id]->name);
		ft_printf("(\"%s\") !\n\033[0m", (*vmka)->bot[id]->comment);
	}
}

int				main(int argc, char **argv)
{
	t_vmka		*vmka;

	if (!music())
		return (0);
	if (argc < 2)
	{
		ft_printf("Usage\n");
		exit(0);
	}
	g_id_players = (int *)ft_memalloc(sizeof(int) * 4);
	g_count_bot = -1;
	init_vm(&vmka, -1);
	parsing_argv_params(argc, argv, &vmka, 0);
	init_field(&vmka, -1, -1);
	init_carriages(&vmka, -1);
	introducing(&vmka, -1);
	vmka->last_alive = vmka->nbr_players;
	start_fight(&vmka);
	endwin();
	Mix_FreeChunk(g_wave);
	Mix_FreeMusic(g_music);
	Mix_CloseAudio();
}
