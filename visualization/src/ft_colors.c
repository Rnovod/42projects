/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 10:28:59 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/07 10:29:00 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

inline static void	ft_rgb_color(t_visual_data *d)
{
	d->game.rgb_clr[0][0] = (SDL_Color){163, 44, 24, 0};
	d->game.rgb_clr[1][0] = (SDL_Color){24, 44, 163, 0};
	d->game.rgb_clr[0][1] = (SDL_Color){100, 0, 184, 0};
	d->game.rgb_clr[1][1] = (SDL_Color){203, 112, 2, 0};
	d->game.rgb_clr[0][2] = (SDL_Color){117, 185, 35, 0};
	d->game.rgb_clr[1][2] = (SDL_Color){142, 105, 202, 0};
	d->game.rgb_clr[0][3] = (SDL_Color){45, 142, 200, 0};
	d->game.rgb_clr[1][3] = (SDL_Color){201, 167, 54, 0};
}

inline static void	ft_hex_color(t_visual_data *d)
{
	d->game.hex_clr[0][0] = 0xA32C18;
	d->game.hex_clr[1][0] = 0x182CA3;
	d->game.hex_clr[0][1] = 0x6400B8;
	d->game.hex_clr[1][1] = 0xCB7002;
	d->game.hex_clr[0][2] = 0x75B923;
	d->game.hex_clr[1][2] = 0x8E69CA;
	d->game.hex_clr[0][3] = 0x2d8ec8;
	d->game.hex_clr[1][3] = 0xc9a736;
}

void				ft_record_colors(t_visual_data *d)
{
	ft_hex_color(d);
	ft_rgb_color(d);
}
