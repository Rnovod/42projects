/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_winner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:46:17 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/08 14:46:18 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

inline static SDL_Surface	*ft_draw(t_visual_data *d)
{
	TTF_Font	*font;
	SDL_Surface	*winner;

	if (!(font = TTF_OpenFont("./fonts/KohinoorDev-Semibold.ttf", 28)))
		ft_visual_error(d, 7);
	if (!(winner = TTF_RenderText_Solid(font, "DRAW",
		(SDL_Color){255, 255, 255, 255})))
	{
		TTF_CloseFont(font);
		ft_visual_error(d, 7);
	}
	return (winner);
}

void						ft_put_winner(t_visual_data *d)
{
	SDL_Surface	*winner;
	SDL_Rect	win;

	d->fl.winner = 1;
	if (d->step->score_o > d->step->score_x ||
		d->step->score_o < d->step->score_x)
	{
		if (!(winner = IMG_Load("./img/cup.png")))
			ft_visual_error(d, 8);
		if (d->step->score_o > d->step->score_x)
			win = (SDL_Rect){d->font.name_x[0], d->font.name_y, 0, 0};
		else if (d->step->score_o < d->step->score_x)
			win = (SDL_Rect){d->font.name_x[1] - winner->w,
			d->font.name_y, 0, 0};
	}
	else
	{
		winner = ft_draw(d);
		win = (SDL_Rect){d->game.start_x + d->game.centr_x + winner->w,
			d->font.name_y + 20, 0, 0};
	}
	SDL_BlitSurface(winner, NULL, d->win.screen, &win);
	SDL_FreeSurface(winner);
	SDL_UpdateWindowSurface(d->win.ptr);
}
