/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 17:25:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 17:25:02 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_draw_grid(t_visual_data *d)
{
	const char	**map = (const char**)d->step->map;
	int			y;
	int			x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '.')
				SDL_FillRect(d->window.screen, &(SDL_Rect){x * 10, y * 10, 8, 8}, 0x333333);
			else if (map[y][x] == 'X')
				SDL_FillRect(d->window.screen, &(SDL_Rect){x * 10, y * 10, 8, 8}, 0x8E0101);
			else if (map[y][x] == 'O')
				SDL_FillRect(d->window.screen, &(SDL_Rect){x * 10, y * 10, 8, 8}, 0x00009A);
			else if (map[y][x] == 'x')
				SDL_FillRect(d->window.screen, &(SDL_Rect){x * 10, y * 10, 8, 8}, 0xff0000);
			else if (map[y][x] == 'o')
				SDL_FillRect(d->window.screen, &(SDL_Rect){x * 10, y * 10, 8, 8}, 0x0000ff);
			x++;
		}
		y++;
	}
}

void		ft_draw_game(t_visual_data *d)
{
	SDL_FillRect(d->window.screen, NULL, 0x282828);
	ft_draw_grid(d);
	SDL_UpdateWindowSurface(d->window.ptr);
}

void		ft_visual_events(t_visual_data *d)
{
	while (!d->begin)
		;
	// Mix_PlayMusic(d->music, -1);
	d->step = d->begin;
	while (!d->fl.stop_event)
	{
		if (SDL_PollEvent(&d->event))
		{
			if (d->event.type == SDL_QUIT)
				d->fl.stop_event = 1;
			else if (d->event.type == SDL_KEYDOWN)
				ft_key_pressed(d);
		}
		if (d->fl.thread_error != 0)
			ft_visual_error(d, -1);
		if (!d->fl.pause && d->step->next)
				d->step = d->step->next;
		ft_draw_game(d);
	}
	// Mix_PauseMusic();
}

	// ft_printf("%s\n%s\n", d->game_info.player_1, d->game_info.player_2);
	// ft_printf("%d\n", d->nbr_steps);

// test data thread

	// t_vis_map	*prev;
	// sleep(2);
	// ;
	// while (d->step != NULL)
	// {
	// 	ft_printf("%m\n", d->step->map);
	// 	if (d->step->next == NULL)
	// 		prev = d->step;
	// 	d->step = d->step->next;
	// }
	// d->step = prev;
	// while (d->step != NULL)
	// {
	// 	ft_printf("%m\n", d->step->map);
	// 	d->step = d->step->prev;
	// }
	// ft_printf("%d\n", d->score_x);
	// ft_printf("%d\n", d->score_o);