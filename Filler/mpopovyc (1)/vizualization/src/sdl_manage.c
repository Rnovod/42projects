/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:54:15 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/18 19:54:16 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualization.h"

void		init_sdl(t_viz *v)
{
	Uint32 render_flags;

	v->window = NULL;
	v->surf = NULL;
	v->font = NULL;
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		exit(0);
	if (TTF_Init() == -1)
		exit(0);
	v->font = TTF_OpenFont("./vizualization/fonts/FFF_Tusj.ttf", 50);
	v->font_score = TTF_OpenFont("./vizualization/fonts/CaviarDreams.ttf", 50);
	if (!(v->font))
		exit(0);
	if (!(v->window = SDL_CreateWindow("Filler", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, W_W, W_H, SDL_WINDOW_OPENGL)))
		exit(0);
	if (!(v->surf = SDL_GetWindowSurface(v->window)))
	{
		ft_putendl(SDL_GetError());
		SDL_DestroyWindow(v->window);
		quit_sdl(v);
		exit(0);
	}
}

void		quit_sdl(t_viz *v)
{
	TTF_CloseFont(v->font);
	TTF_CloseFont(v->font_score);
	TTF_Quit();
	SDL_Quit();
}
