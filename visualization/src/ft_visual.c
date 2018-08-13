/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:25:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 17:25:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline void	ft_events(t_visual_data *d)
{
	if (d->event.type == SDL_QUIT)
		d->fl.stop_event = 1;
	else if (d->event.type == SDL_KEYDOWN && !d->fl.win_hide &&
		(SDLK == SDLK_LEFT || SDLK == SDLK_RIGHT || SDLK == SDLK_ESCAPE ||
		SDLK == SDLK_RETURN || SDLK == SDLK_TAB || SDLK == SDLK_SPACE))
		ft_key_pressed(d);
	else if (d->event.type == SDL_KEYUP && !d->fl.win_hide)
		ft_key_unpressed(d);
	else if (d->event.type == SDL_WINDOWEVENT)
		ft_window_events(d);
}

static inline void	ft_events_visual(t_visual_data *d)
{
	int			tick;

	while (!d->fl.stop_event)
	{
		if (SDL_PollEvent(&d->event))
			ft_events(d);
		if (!d->fl.win_hide)
		{
			tick = SDL_GetTicks();
			if (d->fl.thread_error != 0)
				ft_visual_error(d, -1);
			if (!d->fl.pause && !d->fl.end_game)
				ft_draw_game(d);
			if (!d->step->next && d->nbr_steps != -1)
				d->fl.end_game = 1;
			else
				d->fl.end_game = 0;
			if (!d->fl.pause && d->step->next)
				d->step = d->step->next;
			if (1000 / FPS > SDL_GetTicks() - tick)
				SDL_Delay(1000 / FPS - (SDL_GetTicks() - tick));
			if (d->fl.end_game && !d->fl.winner)
				ft_put_winner(d);
		}
	}
}

static inline void	ft_init(t_visual_data *d)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_visual_error(d, 0);
	if (MIX_INIT_MP3 & Mix_Init(MIX_INIT_MP3))
		ft_visual_error(d, 6);
	if (TTF_Init() < 0)
		ft_visual_error(d, 7);
	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
		ft_visual_error(d, 8);
}

static inline void	ft_calc_values(t_visual_data *d)
{
	int		size_x;
	int		size_h;
	int		sx;

	d->win.w = WIN_W;
	d->win.h = WIN_H;
	size_x = round(DBL(DBL(d->win.w) - d->win.w / 13) / DBL(d->info[MAP].w));
	size_h = round(DBL(DBL(d->win.h) - 200.0) / DBL(d->info[MAP].h));
	d->size_rect = (size_x <= size_h) ? size_x : size_h;
	sx = ((d->win.w - 265.0f - (d->info[MAP].w * d->size_rect)) / 2.0f);
	if ((d->win.w -= (sx - 55.0f) * 2.0f) < 600)
		d->win.w = WIN_W;
	d->game.dis = d->info[MAP].h >= 80 || d->info[MAP].h >= 80 ? 1 : 3;
	d->game.centr_y = d->size_rect * d->info[MAP].h / 2;
	d->game.centr_x = d->size_rect * d->info[MAP].w / 2;
	d->game.start_y = d->win.h / 2 - d->game.centr_y;
	d->game.start_x = d->win.w / 2 - d->game.centr_x;
	d->font.name_x[0] = d->game.start_x + d->win.w / 13 + d->game.centr_x - 90;
	d->font.name_y = d->game.start_y - 85;
	d->font.name_x[1] = d->game.start_x + d->win.w / 13 + d->game.centr_x + 90;
	d->game.points = d->info[MAP].h * d->info[MAP].w;
	d->rect_bar.h = d->win.h / 40 + d->size_rect / 4;
	d->rect_bar.w = d->info[MAP].w * d->size_rect - d->game.dis;
	d->rect_bar.y = d->game.start_y + d->info[MAP].h * d->size_rect + 40;
	d->rect_bar.x = d->game.start_x + d->win.w / 12;
}

void				ft_visual(t_visual_data *d)
{
	while (!d->begin)
		if (d->fl.thread_error)
			ft_visual_error(d, -1);
	d->step = d->begin;
	ft_init(d);
	ft_music(d);
	ft_calc_values(d);
	ft_create_win(d);
	Mix_PlayMusic(d->music, -1);
	ft_events_visual(d);
	Mix_PauseMusic();
}
