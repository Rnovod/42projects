/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:43:15 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 16:43:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_visual_exit(t_visual_data *d, int status)
{
	free(d->game_info.player_1);
	free(d->game_info.player_2);
	Mix_FreeMusic(d->music);
	SDL_FreeSurface(d->window.screen);
	SDL_DestroyWindow(d->window.ptr);
	SDL_ClearError();
	atexit(TTF_Quit);
	atexit(Mix_Quit);
	atexit(SDL_Quit);
	// system("leaks visual");
	exit(status);
}
