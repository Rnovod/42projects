/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win_rend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:38:54 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 16:38:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_create_win_rend(t_visual_data *d)
{
	d->window.w = 1200;
	d->window.h = 800;
	if (!(d->window.ptr =
		SDL_CreateWindow("LET THE FIGHT BEGIN", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		d->window.w, d->window.h,
		SDL_WINDOW_OPENGL)))
		ft_visual_error(d, 0);
	if (!(d->window.screen = SDL_GetWindowSurface(d->window.ptr)))
		ft_visual_error(d, 0);
}
