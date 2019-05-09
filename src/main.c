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
#include <SDL.h>
#include <SDL_mixer.h>

#define WAV_PATH "Eminem - Rap God.mp3"
#define MUS_PATH "HR2_Friska.ogg"

Mix_Chunk *wave = NULL;
Mix_Music *music = NULL;

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

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
		return -1;
	if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 ) 
		return -1; 
	wave = Mix_LoadWAV(WAV_PATH);
	if (wave == NULL)
		return -1;
	music = Mix_LoadMUS(WAV_PATH);
	if (music == NULL)
		return -1;
	
	if ( Mix_PlayChannel(-1, wave, 0) == -1 )
		return -1;
	
	if ( Mix_PlayMusic( music, -1) == -1 )
		return -1;
	// while ( Mix_PlayingMusic() ) ;

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
	start_fight(&vmka);
	endwin();


	Mix_FreeChunk(wave);
	Mix_FreeMusic(music);
	Mix_CloseAudio();


//	system("leaks -q corewar");
}
