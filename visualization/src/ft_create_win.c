/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:38:54 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 16:38:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline void	ft_icon_ui_cursor(t_visual_data *d)
{
	SDL_Surface	*image;

	if (!(image = IMG_Load("./img/icon.png")))
		ft_visual_error(d, 8);
	SDL_SetWindowIcon(d->win.ptr, image);
	SDL_FreeSurface(image);
	if (!(image = IMG_Load("./img/ui.png")))
		ft_visual_error(d, 0);
	if (SDL_BlitScaled(image, NULL, d->win.screen, NULL) < 0)
		ft_visual_error(d, 0);
	SDL_FreeSurface(image);
	if (!(image = IMG_Load("./img/cursor.png")))
		ft_visual_error(d, 8);
	if (!(d->cursor = SDL_CreateColorCursor(image, 0, 0)))
		ft_visual_error(d, 0);
	SDL_SetCursor(d->cursor);
	SDL_FreeSurface(image);
}

void				ft_create_win(t_visual_data *d)
{
	if (!(d->win.ptr =
		SDL_CreateWindow("LET THE FIGHT BEGIN", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, d->win.w, d->win.h, 0)))
		ft_visual_error(d, 0);
	if (!(d->win.screen = SDL_GetWindowSurface(d->win.ptr)))
		ft_visual_error(d, 0);
	ft_icon_ui_cursor(d);
	if (!(d->font_ttf[0] =
		TTF_OpenFont("./fonts/KohinoorDev-Semibold.ttf", 36)))
		ft_visual_error(d, 7);
	if (!(d->font_ttf[1] =
		TTF_OpenFont("./fonts/KohinoorDev-Semibold.ttf", 16)))
		ft_visual_error(d, 7);
}
