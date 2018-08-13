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

static inline void	ft_free_list(t_visual_data *d)
{
	t_vis_map	*tmp;

	d->step = d->begin;
	while (d->step)
	{
		tmp = d->step;
		d->step = d->step->next;
		ft_arrfree(&(tmp->map));
		free(tmp);
	}
}

void				ft_visual_exit(t_visual_data *d, int status)
{
	ft_free_list(d);
	free(d->game.player_1);
	free(d->game.player_2);
	Mix_FreeMusic(d->music);
	TTF_CloseFont(d->font_ttf[0]);
	TTF_CloseFont(d->font_ttf[1]);
	SDL_FreeCursor(d->cursor);
	SDL_FreeSurface(d->win.screen);
	SDL_DestroyWindow(d->win.ptr);
	SDL_ClearError();
	atexit(IMG_Quit);
	atexit(TTF_Quit);
	atexit(Mix_Quit);
	atexit(SDL_Quit);
	exit(status);
}
