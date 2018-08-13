/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_font.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 14:30:49 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/07 14:30:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline int	ft_calc_score(t_visual_data *d, int8_t pl,
					int *player_score)
{
	int			y;
	int			x;
	int			score;
	const char	**map = (const char **)d->step->map;
	const char	player = pl == 0 ? 'O' : 'X';

	y = -1;
	score = 0;
	while (map[++y])
	{
		x = -1 + d->info[MAP].start;
		while (map[y][++x])
		{
			if (map[y][x] == player || map[y][x] == player + 32)
				++score;
		}
	}
	*player_score = score;
	return (score);
}

static inline void	ft_font_score(t_visual_data *d, int8_t pl, int *score)
{
	char		*str_score;
	SDL_Surface	*text;
	const int	who = pl == 0 ? 1 : 0;

	if (*score == -1)
		str_score = ft_itoa(ft_calc_score(d, pl, score));
	else
		str_score = ft_itoa(*score);
	if (!(text = TTF_RenderText_Solid(d->font_ttf[0], str_score,
		d->game.rgb_clr[pl][d->game.nbr_clr])))
		ft_visual_error(d, 7);
	if (text->w > d->font.size)
		d->font.size = text->w;
	SDL_FillRect(d->win.screen, &(SDL_Rect){d->font.name_x[pl] -
	d->font.size * who, d->font.name_y + 50, d->font.size, text->h},
	0x282828);
	SDL_BlitSurface(text, NULL, d->win.screen,
	&(SDL_Rect){d->font.name_x[pl] - text->w * who,
	d->font.name_y + 50, 0, 0});
	SDL_FreeSurface(text);
	free(str_score);
}

static inline void	ft_total_steps(t_visual_data *d)
{
	SDL_Surface	*text;
	char		*str_step;

	if (!(str_step = ft_itoa(d->nbr_steps)))
		ft_visual_error(d, 0);
	if (!(text = TTF_RenderText_Solid(d->font_ttf[1], str_step,
		(SDL_Color){115, 115, 115, 255})))
		ft_visual_error(d, 7);
	SDL_BlitSurface(text, NULL, d->win.screen,
	&(SDL_Rect){d->win.w / 9, d->win.h / 2 + 109, 0, 0});
	SDL_FreeSurface(text);
	free(str_step);
}

static inline void	ft_put_steps(t_visual_data *d)
{
	SDL_Surface	*text;
	char		*str_step;
	static char	total;

	if (!(str_step = ft_itoa(d->step->number)))
		ft_visual_error(d, 0);
	if (!(text = TTF_RenderText_Solid(d->font_ttf[1], str_step,
		(SDL_Color){115, 115, 115, 255})))
		ft_visual_error(d, 7);
	SDL_FillRect(d->win.screen, &(SDL_Rect){d->win.w / 9, d->win.h / 2 + 79,
	text->w + 40, text->h}, 0x3e3e3e);
	SDL_BlitSurface(text, NULL, d->win.screen,
	&(SDL_Rect){d->win.w / 9, d->win.h / 2 + 79, 0, 0});
	SDL_FreeSurface(text);
	free(str_step);
	if (d->nbr_steps != -1 && !total)
	{
		total = 1;
		ft_total_steps(d);
	}
}

void				ft_put_font(t_visual_data *d)
{
	SDL_Surface	*text;

	if (!(text = TTF_RenderText_Solid(d->font_ttf[0], d->game.player_1,
		d->game.rgb_clr[0][d->game.nbr_clr])))
		ft_visual_error(d, 7);
	SDL_BlitSurface(text, NULL, d->win.screen,
	&(SDL_Rect){d->font.name_x[0] - text->w, d->font.name_y, 0, 0});
	SDL_FreeSurface(text);
	if (!(text = TTF_RenderText_Solid(d->font_ttf[0], d->game.player_2,
		d->game.rgb_clr[1][d->game.nbr_clr])))
		ft_visual_error(d, 7);
	SDL_BlitSurface(text, NULL, d->win.screen,
	&(SDL_Rect){d->font.name_x[1], d->font.name_y, 0, 0});
	SDL_FreeSurface(text);
	ft_font_score(d, 0, &d->step->score_o);
	ft_font_score(d, 1, &d->step->score_x);
	ft_put_steps(d);
}
