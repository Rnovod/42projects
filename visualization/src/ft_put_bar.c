/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 11:23:47 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/08 11:23:48 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_put_bar(t_visual_data *d)
{
	SDL_Rect	rect_x;
	SDL_Rect	rect_o;
	float		one_point;

	SDL_FillRect(d->win.screen, &d->rect_bar, 0x333333);
	rect_o.h = d->rect_bar.h - d->rect_bar.h / 4;
	rect_o.y = d->rect_bar.y + d->rect_bar.h / 4 / 2;
	rect_o.x = d->rect_bar.x + 5;
	one_point = FLT(d->rect_bar.w - 10) / FLT(d->game.points);
	rect_o.w = one_point * d->step->score_o;
	SDL_FillRect(d->win.screen, &rect_o, d->game.hex_clr[0][d->game.nbr_clr]);
	rect_x.h = rect_o.h;
	rect_x.y = rect_o.y;
	rect_x.w = one_point * d->step->score_x;
	rect_x.x = d->rect_bar.x + 5 + (one_point * d->game.points - rect_x.w);
	SDL_FillRect(d->win.screen, &rect_x, d->game.hex_clr[1][d->game.nbr_clr]);
	SDL_FillRect(d->win.screen, &(SDL_Rect){d->game.start_x + d->win.w / 12
	+ d->rect_bar.w / 2, d->rect_bar.y, 1, d->rect_bar.h}, 0xffffff);
}
