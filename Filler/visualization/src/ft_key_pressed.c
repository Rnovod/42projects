/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed.c                                   :+:      :+:    :+:   */
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
	if (d->event.key.keysym.sym == SDLK_ESCAPE)
		d->fl.stop_event = 1;
	else if (d->event.key.keysym.sym == SDLK_LEFT &&
		d->fl.pause && d->step->prev)
		d->step = d->step->prev;
	else if (d->event.key.keysym.sym == SDLK_RIGHT &&
		d->fl.pause && d->step->next)
		d->step = d->step->next;
	else if (d->event.key.keysym.sym == SDLK_SPACE)
		++d->fl.pause;
	else if (d->event.key.keysym.sym == SDLK_RETURN)
		d->step = d->begin;
}
