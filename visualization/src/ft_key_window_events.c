/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_window_events.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 18:56:33 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 18:56:34 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_key_pressed(t_visual_data *d)
{
	ft_draw_game(d);
	if (SDLK == SDLK_ESCAPE)
		d->fl.stop_event = 1;
	else if (SDLK == SDLK_LEFT && d->step->prev)
	{
		d->fl.pause = 1;
		d->step = d->step->prev;
	}
	else if (SDLK == SDLK_RIGHT && d->step->next)
	{
		d->fl.pause = 1;
		d->step = d->step->next;
	}
	else if (SDLK == SDLK_SPACE)
		++d->fl.pause;
	else if (SDLK == SDLK_RETURN)
		d->step = d->begin;
	else if (!d->fl.color && SDLK == SDLK_TAB)
	{
		++d->game.nbr_clr;
		d->fl.color = 1;
	}
	ft_draw_game(d);
}

void		ft_key_unpressed(t_visual_data *d)
{
	if (SDLK == SDLK_TAB)
		d->fl.color = 0;
}

void		ft_window_events(t_visual_data *d)
{
	if (d->event.window.event == SDL_WINDOWEVENT_HIDDEN)
		d->fl.win_hide = 1;
	else if (d->event.window.event == SDL_WINDOWEVENT_SHOWN)
		d->fl.win_hide = 0;
}
