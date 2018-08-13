/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:13:16 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/06 15:13:17 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline SDL_Rect	ft_calculate_rect(t_visual_data *d,
						const int y, const int x)
{
	SDL_Rect	rect;

	rect.y = y * d->size_rect + d->game.start_y + 35;
	rect.x = x * d->size_rect + d->game.start_x + d->win.w / 12;
	rect.h = d->size_rect - d->game.dis;
	rect.w = rect.h;
	return (rect);
}

static inline int		ft_random_clr(int color)
{
	sranddev();
	color = ft_gradient(color, 0, ft_randd(0.0, 0.3));
	return (color);
}

static inline void		ft_draw_grid_line(t_visual_data *d, const char **map,
						int y, int x)
{
	SDL_Rect	rect;
	const int	clr_1 = d->game.hex_clr[0][d->game.nbr_clr];
	const int	clr_2 = d->game.hex_clr[1][d->game.nbr_clr];

	while (map[y][++x])
	{
		rect = ft_calculate_rect(d, y, x - 4);
		if (map[y][x] == '.')
			SDL_FillRect(d->win.screen, &rect, 0x333333);
		else if (map[y][x] == 'X' && ((d->step->prev &&
				d->step->prev->map[y][x] != 'X') ||
				(d->step->next && d->step->next->map[y][x] == 'x' &&
				SDLK == SDLK_LEFT) || d->fl.color == 1))
			SDL_FillRect(d->win.screen, &rect, ft_random_clr(clr_2));
		else if (map[y][x] == 'O' && ((d->step->prev &&
				d->step->prev->map[y][x] != 'O') ||
				(d->step->next && d->step->next->map[y][x] == 'o' &&
				SDLK == SDLK_LEFT) || d->fl.color == 1))
			SDL_FillRect(d->win.screen, &rect, ft_random_clr(clr_1));
		else if (map[y][x] == 'x')
			SDL_FillRect(d->win.screen, &rect, ft_gradient(clr_2, WHITE, 0.4));
		else if (map[y][x] == 'o')
			SDL_FillRect(d->win.screen, &rect, ft_gradient(clr_1, WHITE, 0.4));
	}
}

static inline void		ft_draw_grid(t_visual_data *d)
{
	int			y;
	const char	**map = (const char**)d->step->map;

	y = -1;
	while (map[++y])
		ft_draw_grid_line(d, map, y, -1 + 4);
}

void					ft_draw_game(t_visual_data *d)
{
	ft_draw_grid(d);
	if (d->fl.color == 1)
		d->fl.color = 2;
	ft_put_font(d);
	ft_put_bar(d);
	SDL_UpdateWindowSurface(d->win.ptr);
}
