/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:55:22 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/22 13:55:23 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualization.h"

void		draw_player(t_viz *v, char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strrchr(line, '/');
	while (str[i] != '.')
		i++;
	if (ft_atoi(&line[10]) == 1)
	{
		v->p1 = ft_strndup(str + 1, i - 1);
		v->text = TTF_RenderText_Solid(v->font, v->p1,
			(SDL_Color){33, 79, 155, 0});
		SDL_BlitSurface(v->text, NULL, v->surf,
			&(SDL_Rect){100, 30, 1000, 100});
	}
	else
	{
		v->p2 = ft_strndup(str + 1, i - 1);
		v->text = TTF_RenderText_Solid(v->font, v->p2,
			(SDL_Color){15, 68, 24, 0});
		SDL_BlitSurface(v->text, NULL, v->surf,
			&(SDL_Rect){100, 80, 1000, 100});
	}
	SDL_FreeSurface(v->text);
}

void		draw_score(t_viz *v)
{
	char	*tmp;

	SDL_FillRect(v->surf, &(SDL_Rect){760, 30, 300, 100}, 0x0);
	tmp = ft_itoa(v->score1);
	v->text = TTF_RenderText_Solid(v->font_score, tmp,
		(SDL_Color){33, 79, 155, 0});
	SDL_BlitSurface(v->text, NULL, v->surf,
		&(SDL_Rect){760, 30, 150, 50});
	SDL_FreeSurface(v->text);
	free(tmp);
	tmp = ft_itoa(v->score2);
	v->text = TTF_RenderText_Solid(v->font_score, tmp,
		(SDL_Color){15, 68, 24, 0});
	SDL_BlitSurface(v->text, NULL, v->surf,
		&(SDL_Rect){760, 80, 150, 50});
	SDL_FreeSurface(v->text);
	free(tmp);
}

void		final_score(t_viz *v)
{
	v->text = TTF_RenderText_Solid(v->font, "!winner!",
		(SDL_Color){255, 255, 255, 0});
	if (v->score1 > v->score2)
		SDL_BlitSurface(v->text, NULL, v->surf,
			&(SDL_Rect){500, 30, 1000, 1000});
	else
		SDL_BlitSurface(v->text, NULL, v->surf,
			&(SDL_Rect){500, 80, 1000, 1000});
}
